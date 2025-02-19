/******************************************************************************
 * Top contributors (to current version):
 *   Aina Niemetz, Tim King, Mathias Preiner
 *
 * This file is part of the cvc5 project.
 *
 * Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
 * in the top-level source directory and their institutional affiliations.
 * All rights reserved.  See the file COPYING in the top-level source
 * directory for licensing information.
 * ****************************************************************************
 *
 * Interface for custom handlers and predicates options.
 */

#include "options/options_handler.h"

#include <cerrno>
#include <iostream>
#include <ostream>
#include <string>

#include "base/check.h"
#include "base/configuration.h"
#include "base/configuration_private.h"
#include "base/cvc5config.h"
#include "base/exception.h"
#include "base/modal_exception.h"
#include "base/output.h"
#include "expr/expr_iomanip.h"
#include "lib/strtok_r.h"
#include "options/base_options.h"
#include "options/bv_options.h"
#include "options/decision_options.h"
#include "options/didyoumean.h"
#include "options/language.h"
#include "options/option_exception.h"
#include "options/set_language.h"
#include "options/smt_options.h"
#include "options/theory_options.h"
#include "smt/command.h"
#include "smt/dump.h"

namespace cvc5 {
namespace options {

// helper functions
namespace {

static void printTags(const std::vector<std::string>& tags)
{
  std::cout << "available tags:";
  for (const auto& t : tags)
  {
    std::cout << "  " << t << std::endl;
  }
  std::cout << std::endl;
}

std::string suggestTags(const std::vector<std::string>& validTags,
                        std::string inputTag,
                        const std::vector<std::string>& additionalTags)
{
  DidYouMean didYouMean;
  didYouMean.addWords(validTags);
  didYouMean.addWords(additionalTags);
  return didYouMean.getMatchAsString(inputTag);
}

}  // namespace

OptionsHandler::OptionsHandler(Options* options) : d_options(options) { }

void OptionsHandler::setErrStream(const std::string& option,
                                  const std::string& flag,
                                  const ManagedErr& me)
{
  Debug.setStream(me);
  Warning.setStream(me);
  CVC5Message.setStream(me);
  Notice.setStream(me);
  Chat.setStream(me);
  Trace.setStream(me);
}

Language OptionsHandler::stringToLanguage(const std::string& option,
                                          const std::string& flag,
                                          const std::string& optarg)
{
  if (optarg == "help")
  {
    *d_options->base.out << R"FOOBAR(
Languages currently supported as arguments to the -L / --lang option:
  auto                           attempt to automatically determine language
  smt | smtlib | smt2 |
  smt2.6 | smtlib2.6             SMT-LIB format 2.6 with support for the strings standard
  tptp                           TPTP format (cnf, fof and tff)
  sygus | sygus2                 SyGuS version 2.0

Languages currently supported as arguments to the --output-lang option:
  auto                           match output language to input language
  smt | smtlib | smt2 |
  smt2.6 | smtlib2.6             SMT-LIB format 2.6 with support for the strings standard
  tptp                           TPTP format
  ast                            internal format (simple syntax trees)
)FOOBAR" << std::endl;
    std::exit(1);
    return Language::LANG_AUTO;
  }

  try
  {
    return language::toLanguage(optarg);
  }
  catch (OptionException& oe)
  {
    throw OptionException("Error in " + option + ": " + oe.getMessage()
                          + "\nTry --lang help");
  }

  Unreachable();
}

void OptionsHandler::languageIsNotAST(const std::string& option,
                                      const std::string& flag,
                                      Language lang)
{
  if (lang == Language::LANG_AST)
  {
    throw OptionException("Language LANG_AST is not allowed for " + flag);
  }
}

void OptionsHandler::applyOutputLanguage(const std::string& option,
                                         const std::string& flag,
                                         Language lang)
{
  d_options->base.out << language::SetLanguage(lang);
}

void OptionsHandler::setVerbosity(const std::string& option,
                                  const std::string& flag,
                                  int value)
{
  if(Configuration::isMuzzledBuild()) {
    DebugChannel.setStream(&cvc5::null_os);
    TraceChannel.setStream(&cvc5::null_os);
    NoticeChannel.setStream(&cvc5::null_os);
    ChatChannel.setStream(&cvc5::null_os);
    MessageChannel.setStream(&cvc5::null_os);
    WarningChannel.setStream(&cvc5::null_os);
  } else {
    if(value < 2) {
      ChatChannel.setStream(&cvc5::null_os);
    } else {
      ChatChannel.setStream(&std::cout);
    }
    if(value < 1) {
      NoticeChannel.setStream(&cvc5::null_os);
    } else {
      NoticeChannel.setStream(&std::cout);
    }
    if(value < 0) {
      MessageChannel.setStream(&cvc5::null_os);
      WarningChannel.setStream(&cvc5::null_os);
    } else {
      MessageChannel.setStream(&std::cout);
      WarningChannel.setStream(&std::cerr);
    }
  }
}

void OptionsHandler::decreaseVerbosity(const std::string& option,
                                       const std::string& flag)
{
  d_options->base.verbosity -= 1;
  setVerbosity(option, flag, d_options->base.verbosity);
}

void OptionsHandler::increaseVerbosity(const std::string& option,
                                       const std::string& flag)
{
  d_options->base.verbosity += 1;
  setVerbosity(option, flag, d_options->base.verbosity);
}

void OptionsHandler::setStats(const std::string& option,
                              const std::string& flag,
                              bool value)
{
#ifndef CVC5_STATISTICS_ON
  if (value)
  {
    std::stringstream ss;
    ss << "option `" << flag
       << "' requires a statistics-enabled build of cvc5; this binary was not "
          "built with statistics support";
    throw OptionException(ss.str());
  }
#endif /* CVC5_STATISTICS_ON */
  if (!value)
  {
    d_options->base.statisticsAll = false;
    d_options->base.statisticsEveryQuery = false;
    d_options->base.statisticsExpert = false;
  }
}

void OptionsHandler::setStatsDetail(const std::string& option,
                              const std::string& flag,
                              bool value)
{
#ifndef CVC5_STATISTICS_ON
  if (value)
  {
    std::stringstream ss;
    ss << "option `" << flag
       << "' requires a statistics-enabled build of cvc5; this binary was not "
          "built with statistics support";
    throw OptionException(ss.str());
  }
#endif /* CVC5_STATISTICS_ON */
  if (value)
  {
    d_options->base.statistics = true;
  }
}

void OptionsHandler::enableTraceTag(const std::string& option,
                                    const std::string& flag,
                                    const std::string& optarg)
{
  if(!Configuration::isTracingBuild())
  {
    throw OptionException("trace tags not available in non-tracing builds");
  }
  else if(!Configuration::isTraceTag(optarg.c_str()))
  {
    if (optarg == "help")
    {
      printTags(Configuration::getTraceTags());
      std::exit(0);
    }

    throw OptionException(
        std::string("trace tag ") + optarg + std::string(" not available.")
        + suggestTags(Configuration::getTraceTags(), optarg, {}));
  }
  Trace.on(optarg);
}

void OptionsHandler::enableDebugTag(const std::string& option,
                                    const std::string& flag,
                                    const std::string& optarg)
{
  if (!Configuration::isDebugBuild())
  {
    throw OptionException("debug tags not available in non-debug builds");
  }
  else if (!Configuration::isTracingBuild())
  {
    throw OptionException("debug tags not available in non-tracing builds");
  }

  if (!Configuration::isDebugTag(optarg.c_str())
      && !Configuration::isTraceTag(optarg.c_str()))
  {
    if (optarg == "help")
    {
      printTags(Configuration::getDebugTags());
      std::exit(0);
    }

    throw OptionException(std::string("debug tag ") + optarg
                          + std::string(" not available.")
                          + suggestTags(Configuration::getDebugTags(),
                                        optarg,
                                        Configuration::getTraceTags()));
  }
  Debug.on(optarg);
  Trace.on(optarg);
}

void OptionsHandler::enableOutputTag(const std::string& option,
                                     const std::string& flag,
                                     const std::string& optarg)
{
  d_options->base.outputTagHolder.set(
      static_cast<size_t>(stringToOutputTag(optarg)));
}

void OptionsHandler::setPrintSuccess(const std::string& option,
                                     const std::string& flag,
                                     bool value)
{
  Debug.getStream() << Command::printsuccess(value);
  Trace.getStream() << Command::printsuccess(value);
  Notice.getStream() << Command::printsuccess(value);
  Chat.getStream() << Command::printsuccess(value);
  CVC5Message.getStream() << Command::printsuccess(value);
  Warning.getStream() << Command::printsuccess(value);
  *d_options->base.out << Command::printsuccess(value);
}

void OptionsHandler::setResourceWeight(const std::string& option,
                                       const std::string& flag,
                                       const std::string& optarg)
{
  d_options->base.resourceWeightHolder.emplace_back(optarg);
}

void OptionsHandler::abcEnabledBuild(const std::string& option,
                                     const std::string& flag,
                                     bool value)
{
#ifndef CVC5_USE_ABC
  if(value) {
    std::stringstream ss;
    ss << "option `" << option
       << "' requires an abc-enabled build of cvc5; this binary was not built "
          "with abc support";
    throw OptionException(ss.str());
  }
#endif /* CVC5_USE_ABC */
}

void OptionsHandler::abcEnabledBuild(const std::string& option,
                                     const std::string& flag,
                                     const std::string& value)
{
#ifndef CVC5_USE_ABC
  if(!value.empty()) {
    std::stringstream ss;
    ss << "option `" << option
       << "' requires an abc-enabled build of cvc5; this binary was not built "
          "with abc support";
    throw OptionException(ss.str());
  }
#endif /* CVC5_USE_ABC */
}

void OptionsHandler::checkBvSatSolver(const std::string& option,
                                      const std::string& flag,
                                      SatSolverMode m)
{
  if (m == SatSolverMode::CRYPTOMINISAT
      && !Configuration::isBuiltWithCryptominisat())
  {
    std::stringstream ss;
    ss << "option `" << option
       << "' requires a CryptoMiniSat build of cvc5; this binary was not built "
          "with CryptoMiniSat support";
    throw OptionException(ss.str());
  }

  if (m == SatSolverMode::KISSAT && !Configuration::isBuiltWithKissat())
  {
    std::stringstream ss;
    ss << "option `" << option
       << "' requires a Kissat build of cvc5; this binary was not built with "
          "Kissat support";
    throw OptionException(ss.str());
  }

  if (d_options->bv.bvSolver != options::BVSolver::BITBLAST
      && (m == SatSolverMode::CRYPTOMINISAT || m == SatSolverMode::CADICAL
          || m == SatSolverMode::KISSAT))
  {
    if (d_options->bv.bitblastMode == options::BitblastMode::LAZY
        && d_options->bv.bitblastModeWasSetByUser)
    {
      std::string sat_solver;
      if (m == options::SatSolverMode::CADICAL)
      {
        sat_solver = "CaDiCaL";
      }
      else if (m == options::SatSolverMode::KISSAT)
      {
        sat_solver = "Kissat";
      }
      else
      {
        Assert(m == options::SatSolverMode::CRYPTOMINISAT);
        sat_solver = "CryptoMiniSat";
      }
      throw OptionException(sat_solver
                            + " does not support lazy bit-blasting.\n"
                            + "Try --bv-sat-solver=minisat");
    }
    options::bv::setDefaultBitvectorToBool(*d_options, true);
  }
}

void OptionsHandler::setBitblastAig(const std::string& option,
                                    const std::string& flag,
                                    bool arg)
{
  if(arg) {
    if (d_options->bv.bitblastModeWasSetByUser) {
      if (d_options->bv.bitblastMode != options::BitblastMode::EAGER)
      {
        throw OptionException("bitblast-aig must be used with eager bitblaster");
      }
    } else {
      d_options->bv.bitblastMode = options::BitblastMode::EAGER;
    }
  }
}

void OptionsHandler::setDefaultExprDepth(const std::string& option,
                                         const std::string& flag,
                                         int depth)
{
  Debug.getStream() << expr::ExprSetDepth(depth);
  Trace.getStream() << expr::ExprSetDepth(depth);
  Notice.getStream() << expr::ExprSetDepth(depth);
  Chat.getStream() << expr::ExprSetDepth(depth);
  CVC5Message.getStream() << expr::ExprSetDepth(depth);
  Warning.getStream() << expr::ExprSetDepth(depth);
}

void OptionsHandler::setDefaultDagThresh(const std::string& option,
                                         const std::string& flag,
                                         int dag)
{
  Debug.getStream() << expr::ExprDag(dag);
  Trace.getStream() << expr::ExprDag(dag);
  Notice.getStream() << expr::ExprDag(dag);
  Chat.getStream() << expr::ExprDag(dag);
  CVC5Message.getStream() << expr::ExprDag(dag);
  Warning.getStream() << expr::ExprDag(dag);
  Dump.getStream() << expr::ExprDag(dag);
}

static void print_config(const char* str, std::string config)
{
  std::string s(str);
  unsigned sz = 14;
  if (s.size() < sz) s.resize(sz, ' ');
  std::cout << s << ": " << config << std::endl;
}

static void print_config_cond(const char* str, bool cond = false)
{
  print_config(str, cond ? "yes" : "no");
}

void OptionsHandler::showConfiguration(const std::string& option,
                                       const std::string& flag)
{
  std::cout << Configuration::about() << std::endl;

  print_config("version", Configuration::getVersionString());
  if (Configuration::isGitBuild())
  {
    print_config("scm", Configuration::getGitInfo());
  }
  else
  {
    print_config_cond("scm", false);
  }

  std::cout << std::endl;

  std::stringstream ss;
  ss << Configuration::getVersionString();
  print_config("library", ss.str());

  std::cout << std::endl;

  print_config_cond("debug code", Configuration::isDebugBuild());
  print_config_cond("statistics", Configuration::isStatisticsBuild());
  print_config_cond("tracing", Configuration::isTracingBuild());
  print_config_cond("dumping", Configuration::isDumpingBuild());
  print_config_cond("muzzled", Configuration::isMuzzledBuild());
  print_config_cond("assertions", Configuration::isAssertionBuild());
  print_config_cond("coverage", Configuration::isCoverageBuild());
  print_config_cond("profiling", Configuration::isProfilingBuild());
  print_config_cond("asan", Configuration::isAsanBuild());
  print_config_cond("ubsan", Configuration::isUbsanBuild());
  print_config_cond("tsan", Configuration::isTsanBuild());
  print_config_cond("competition", Configuration::isCompetitionBuild());

  std::cout << std::endl;

  print_config_cond("abc", Configuration::isBuiltWithAbc());
  print_config_cond("cln", Configuration::isBuiltWithCln());
  print_config_cond("glpk", Configuration::isBuiltWithGlpk());
  print_config_cond("cryptominisat", Configuration::isBuiltWithCryptominisat());
  print_config_cond("gmp", Configuration::isBuiltWithGmp());
  print_config_cond("kissat", Configuration::isBuiltWithKissat());
  print_config_cond("poly", Configuration::isBuiltWithPoly());
  print_config_cond("editline", Configuration::isBuiltWithEditline());

  std::exit(0);
}

void OptionsHandler::showCopyright(const std::string& option,
                                   const std::string& flag)
{
  std::cout << Configuration::copyright() << std::endl;
  std::exit(0);
}

void OptionsHandler::showVersion(const std::string& option,
                                 const std::string& flag)
{
  d_options->base.out << Configuration::about() << std::endl;
  std::exit(0);
}

void OptionsHandler::showDebugTags(const std::string& option,
                                   const std::string& flag)
{
  if (!Configuration::isDebugBuild())
  {
    throw OptionException("debug tags not available in non-debug builds");
  }
  else if (!Configuration::isTracingBuild())
  {
    throw OptionException("debug tags not available in non-tracing builds");
  }
  printTags(Configuration::getDebugTags());
  std::exit(0);
}

void OptionsHandler::showTraceTags(const std::string& option,
                                   const std::string& flag)
{
  if (!Configuration::isTracingBuild())
  {
    throw OptionException("trace tags not available in non-tracing build");
  }
  printTags(Configuration::getTraceTags());
  std::exit(0);
}

void OptionsHandler::setDumpMode(const std::string& option,
                                 const std::string& flag,
                                 const std::string& optarg)
{
#ifdef CVC5_DUMPING
  Dump.setDumpFromString(optarg);
#else  /* CVC5_DUMPING */
  throw OptionException(
      "The dumping feature was disabled in this build of cvc5.");
#endif /* CVC5_DUMPING */
}

void OptionsHandler::setDumpStream(const std::string& option,
                                   const std::string& flag,
                                   const ManagedOut& mo)
{
#ifdef CVC5_DUMPING
  Dump.setStream(mo);
#else  /* CVC5_DUMPING */
  throw OptionException(
      "The dumping feature was disabled in this build of cvc5.");
#endif /* CVC5_DUMPING */
}

}  // namespace options
}  // namespace cvc5
