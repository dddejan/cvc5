/******************************************************************************
 * Top contributors (to current version):
 *   Andres Noetzli, Morgan Deters, Tim King
 *
 * This file is part of the cvc5 project.
 *
 * Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
 * in the top-level source directory and their institutional affiliations.
 * All rights reserved.  See the file COPYING in the top-level source
 * directory for licensing information.
 * ****************************************************************************
 *
 * Dump utility classes and functions.
 */

#include "smt/dump.h"

#include "base/configuration.h"
#include "base/output.h"
#include "lib/strtok_r.h"
#include "options/option_exception.h"
#include "preprocessing/preprocessing_pass_registry.h"
#include "smt/command.h"
#include "smt/node_command.h"

namespace cvc5 {

#if defined(CVC5_DUMPING) && !defined(CVC5_MUZZLE)

CVC5dumpstream& CVC5dumpstream::operator<<(const Command& c)
{
  if (d_os != nullptr)
  {
    (*d_os) << c;
  }
  return *this;
}

CVC5dumpstream& CVC5dumpstream::operator<<(const NodeCommand& nc)
{
  if (d_os != nullptr)
  {
    (*d_os) << nc;
  }
  return *this;
}

#else

CVC5dumpstream& CVC5dumpstream::operator<<(const Command& c) { return *this; }
CVC5dumpstream& CVC5dumpstream::operator<<(const NodeCommand& nc)
{
  return *this;
}

#endif /* CVC5_DUMPING && !CVC5_MUZZLE */

DumpC DumpChannel;

std::ostream& DumpC::setStream(std::ostream* os)
{
  ::cvc5::DumpOutChannel.setStream(os);
  return *os;
}
std::ostream& DumpC::getStream() { return ::cvc5::DumpOutChannel.getStream(); }
std::ostream* DumpC::getStreamPointer()
{
  return ::cvc5::DumpOutChannel.getStreamPointer();
}

void DumpC::setDumpFromString(const std::string& optarg)
{
  if (Configuration::isDumpingBuild())
  {
    // Make a copy of optarg for strtok_r to use.
    std::string optargCopy = optarg;
    char* optargPtr = const_cast<char*>(optargCopy.c_str());
    char* tokstr = optargPtr;
    char* toksave;
    while ((optargPtr = strtok_r(tokstr, ",", &toksave)) != NULL)
    {
      tokstr = NULL;
      if (!strcmp(optargPtr, "benchmark"))
      {
      }
      else if (!strcmp(optargPtr, "declarations"))
      {
      }
      else if (!strcmp(optargPtr, "assertions"))
      {
        Dump.on("assertions:post-everything");
      }
      else if (!strncmp(optargPtr, "assertions:", 11))
      {
        const char* p = optargPtr + 11;
        if (!strncmp(p, "pre-", 4))
        {
          p += 4;
        }
        else if (!strncmp(p, "post-", 5))
        {
          p += 5;
        }
        else
        {
          throw OptionException(std::string("don't know how to dump `")
                                + optargPtr
                                + "'.  Please consult --dump help.");
        }
        // hard-coded cases
        if (!strcmp(p, "everything") || !strcmp(p, "definition-expansion")
            || !strcmp(p, "simplify") || !strcmp(p, "repeat-simplify"))
        {
        }
        else if (preprocessing::PreprocessingPassRegistry::getInstance()
                     .hasPass(p))
        {
        }
        else
        {
          throw OptionException(std::string("don't know how to dump `")
                                + optargPtr
                                + "'.  Please consult --dump help.");
        }
        Dump.on("assertions");
      }
      else if (!strcmp(optargPtr, "skolems"))
      {
      }
      else if (!strcmp(optargPtr, "clauses"))
      {
      }
      else if (!strcmp(optargPtr, "t-conflicts")
               || !strcmp(optargPtr, "t-lemmas")
               || !strcmp(optargPtr, "t-explanations")
               || !strcmp(optargPtr, "theory::fullcheck"))
      {
      }
      else if (!strcmp(optargPtr, "help"))
      {
        puts(s_dumpHelp.c_str());

        std::stringstream ss;
        ss << "Available preprocessing passes:\n";
        for (const std::string& pass :
             preprocessing::PreprocessingPassRegistry::getInstance()
                 .getAvailablePasses())
        {
          ss << "- " << pass << "\n";
        }
        puts(ss.str().c_str());
        exit(1);
      }
      else
      {
        throw OptionException(std::string("unknown option for --dump: `")
                              + optargPtr + "'.  Try --dump help.");
      }

      Dump.on(optargPtr);
      Dump.on("benchmark");
      if (strcmp(optargPtr, "benchmark"))
      {
        Dump.on("declarations");
      }
    }
  }
  else
  {
    throw OptionException(
        "The dumping feature was disabled in this build of cvc5.");
  }
}

const std::string DumpC::s_dumpHelp =
    "\
Dump modes currently supported by the --dump option:\n\
\n\
benchmark\n\
+ Dump the benchmark structure (set-logic, push/pop, queries, etc.), but\n\
  does not include any declarations or assertions.  Implied by all following\n\
  modes.\n\
\n\
declarations\n\
+ Dump user declarations.  Implied by all following modes.\n\
\n\
skolems\n\
+ Dump internally-created skolem variable declarations.  These can\n\
  arise from preprocessing simplifications, existential elimination,\n\
  and a number of other things.  Implied by all following modes.\n\
\n\
assertions\n\
+ Output the assertions after preprocessing and before clausification.\n\
  Can also specify \"assertions:pre-PASS\" or \"assertions:post-PASS\",\n\
  where PASS is one of the preprocessing passes: definition-expansion\n\
  boolean-terms constrain-subtypes substitution bv-to-bool bool-to-bv\n\
  strings-pp skolem-quant simplify static-learning ite-removal\n\
  repeat-simplify rewrite-apply-to-const theory-preprocessing.\n\
  PASS can also be the special value \"everything\", in which case the\n\
  assertions are printed before any preprocessing (with\n\
  \"assertions:pre-everything\") or after all preprocessing completes\n\
  (with \"assertions:post-everything\").\n\
\n\
clauses\n\
+ Do all the preprocessing outlined above, and dump the CNF-converted\n\
  output\n\
\n\
t-conflicts\n\
+ Output correctness queries for all theory conflicts\n\
\n\
t-lemmas\n\
+ Output correctness queries for all theory lemmas\n\
\n\
t-explanations\n\
+ Output correctness queries for all theory explanations\n\
\n\
theory::fullcheck\n\
+ Output completeness queries for all full-check effort-level theory checks\n\
\n\
Dump modes can be combined by concatenating the above values with \",\" in\n\
between them.  Generally you want one from the assertions category (either\n\
assertions or clauses), and perhaps one or more other modes for checking\n\
correctness and completeness of decision procedure implementations.\n\
\n\
The --output-language option controls the language used for dumping, and\n\
this allows you to connect cvc5 to another solver implementation via a UNIX\n\
pipe to perform on-line checking.  The --dump-to option can be used to dump\n\
to a file.\n\
";

}  // namespace cvc5
