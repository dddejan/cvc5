/******************************************************************************
 * Top contributors (to current version):
 *   Mudathir Mohamed
 *
 * This file is part of the cvc5 project.
 *
 * Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
 * in the top-level source directory and their institutional affiliations.
 * All rights reserved.  See the file COPYING in the top-level source
 * directory for licensing information.
 * ****************************************************************************
 *
 * The cvc5 Java API.
 */

#include "cvc5_Solver.h"

#include "api/cpp/cvc5.h"
#include "cvc5JavaApi.h"

using namespace cvc5::api;

/*
 * Class:     cvc5_Solver
 * Method:    newSolver
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_newSolver(JNIEnv*, jobject)
{
  Solver* solver = new Solver();
  return reinterpret_cast<jlong>(solver);
}

/*
 * Class:     cvc5_Solver
 * Method:    deletePointer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_deletePointer(JNIEnv*,
                                                      jclass,
                                                      jlong pointer)
{
  delete (reinterpret_cast<Solver*>(pointer));
}

/*
 * Class:     cvc5_Solver
 * Method:    getNullSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getNullSort(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->getNullSort());
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getBooleanSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getBooleanSort(JNIEnv* env,
                                                        jobject,
                                                        jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->getBooleanSort());
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getIntegerSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getIntegerSort(JNIEnv* env,
                                                        jobject,
                                                        jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->getIntegerSort());
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getRealSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getRealSort(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->getRealSort());
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getRegExpSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getRegExpSort(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->getRegExpSort());
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getRoundingModeSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getRoundingModeSort(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->getRoundingModeSort());
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getStringSort
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getStringSort(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->getStringSort());
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkArraySort
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkArraySort(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer,
                                                     jlong indexSortPointer,
                                                     jlong elementSortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* indexSort = reinterpret_cast<Sort*>(indexSortPointer);
  Sort* elementSort = reinterpret_cast<Sort*>(elementSortPointer);
  Sort* retPointer = new Sort(solver->mkArraySort(*indexSort, *elementSort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkBitVectorSort
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkBitVectorSort(JNIEnv* env,
                                                         jobject,
                                                         jlong pointer,
                                                         jint size)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer = new Sort(solver->mkBitVectorSort((uint32_t)size));
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkFloatingPointSort
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkFloatingPointSort(
    JNIEnv* env, jobject, jlong pointer, jint exp, jint sig)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sortPointer =
      new Sort(solver->mkFloatingPointSort((uint32_t)exp, (uint32_t)sig));
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkDatatypeSort
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkDatatypeSort(
    JNIEnv* env, jobject, jlong pointer, jlong datatypeDeclPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  DatatypeDecl* decl = reinterpret_cast<DatatypeDecl*>(datatypeDeclPointer);
  Sort* retPointer = new Sort(solver->mkDatatypeSort(*decl));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkDatatypeSorts
 * Signature: (J[J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc5_Solver_mkDatatypeSorts__J_3J(
    JNIEnv* env, jobject, jlong pointer, jlongArray jDecls)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<DatatypeDecl> decls =
      getObjectsFromPointers<DatatypeDecl>(env, jDecls);
  std::vector<Sort> sorts = solver->mkDatatypeSorts(decls);
  std::vector<jlong> sortPointers(sorts.size());

  for (size_t i = 0; i < sorts.size(); i++)
  {
    sortPointers[i] = reinterpret_cast<jlong>(new Sort(sorts[i]));
  }

  jlongArray ret = env->NewLongArray(sorts.size());
  env->SetLongArrayRegion(ret, 0, sorts.size(), sortPointers.data());
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkDatatypeSorts
 * Signature: (J[J[J)[J
 */
JNIEXPORT jlongArray JNICALL
Java_cvc5_Solver_mkDatatypeSorts__J_3J_3J(JNIEnv* env,
                                          jobject,
                                          jlong pointer,
                                          jlongArray jDecls,
                                          jlongArray jUnresolved)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<DatatypeDecl> decls =
      getObjectsFromPointers<DatatypeDecl>(env, jDecls);
  std::vector<Sort> cUnresolved =
      getObjectsFromPointers<Sort>(env, jUnresolved);
  std::set<Sort> unresolved(cUnresolved.begin(), cUnresolved.end());
  std::vector<Sort> sorts = solver->mkDatatypeSorts(decls, unresolved);
  jlongArray ret = getPointersFromObjects<Sort>(env, sorts);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkFunctionSort
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_mkFunctionSort__JJJ(JNIEnv* env,
                                     jobject,
                                     jlong pointer,
                                     jlong domainPointer,
                                     jlong codomainPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* domain = reinterpret_cast<Sort*>(domainPointer);
  Sort* codomain = reinterpret_cast<Sort*>(codomainPointer);
  Sort* sortPointer = new Sort(solver->mkFunctionSort(*domain, *codomain));
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkFunctionSort
 * Signature: (J[JJ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_mkFunctionSort__J_3JJ(JNIEnv* env,
                                       jobject,
                                       jlong pointer,
                                       jlongArray sortPointers,
                                       jlong codomainPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* codomain = reinterpret_cast<Sort*>(codomainPointer);
  std::vector<Sort> sorts = getObjectsFromPointers<Sort>(env, sortPointers);
  Sort* retPointer = new Sort(solver->mkFunctionSort(sorts, *codomain));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkParamSort
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkParamSort(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer,
                                                     jstring jSymbol)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  Sort* retPointer = new Sort(solver->mkParamSort(cSymbol));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkPredicateSort
 * Signature: (J[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkPredicateSort(
    JNIEnv* env, jobject, jlong pointer, jlongArray sortPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Sort> sorts = getObjectsFromPointers<Sort>(env, sortPointers);
  Sort* retPointer = new Sort(solver->mkPredicateSort(sorts));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkRecordSort
 * Signature: (J[Lcvc5/Pair;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkRecordSort(JNIEnv* env,
                                                      jobject,
                                                      jlong pointer,
                                                      jobjectArray jFields)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  jsize size = env->GetArrayLength(jFields);
  // Lcvc5/Pair; is signature of cvc5.Pair<String, Long>
  jclass pairClass = env->FindClass("Lcvc5/Pair;");
  jclass longClass = env->FindClass("Ljava/lang/Long;");
  // Ljava/lang/Object; is the signature of cvc5.Pair.first field
  jfieldID firstFieldId =
      env->GetFieldID(pairClass, "first", "Ljava/lang/Object;");
  // Ljava/lang/Object; is the signature of cvc5.Pair.second field
  jfieldID secondFieldId =
      env->GetFieldID(pairClass, "second", "Ljava/lang/Object;");
  // we need to call method longValue to get long Long object
  jmethodID methodId = env->GetMethodID(longClass, "longValue", "()J");

  std::vector<std::pair<std::string, Sort>> cFields;
  for (jsize i = 0; i < size; i++)
  {
    // get the pair at index i
    jobject object = env->GetObjectArrayElement(jFields, i);

    // get the object at cvc5.Pair.first and convert it to char *
    jstring jFirst = (jstring)env->GetObjectField(object, firstFieldId);
    const char* cFirst = env->GetStringUTFChars(jFirst, nullptr);

    // get the object at cvc5.Pair.second and convert it to Sort
    jobject jSecond = env->GetObjectField(object, secondFieldId);
    jlong sortPointer = env->CallLongMethod(jSecond, methodId);
    Sort* sort = reinterpret_cast<Sort*>(sortPointer);

    // add the pair to to the list of fields
    cFields.push_back(std::make_pair(std::string(cFirst), *sort));
  }
  // get the record sort from the solver
  Sort* retPointer = new Sort(solver->mkRecordSort(cFields));
  // return a pointer to the sort
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkSetSort
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkSetSort(JNIEnv* env,
                                                   jobject,
                                                   jlong pointer,
                                                   jlong elemSortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* elemSort = reinterpret_cast<Sort*>(elemSortPointer);
  Sort* retPointer = new Sort(solver->mkSetSort(*elemSort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkBagSort
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkBagSort(JNIEnv* env,
                                                   jobject,
                                                   jlong pointer,
                                                   jlong elemSortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* elemSort = reinterpret_cast<Sort*>(elemSortPointer);
  Sort* retPointer = new Sort(solver->mkBagSort(*elemSort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkSequenceSort
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkSequenceSort(JNIEnv* env,
                                                        jobject,
                                                        jlong pointer,
                                                        jlong elemSortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* elemSort = reinterpret_cast<Sort*>(elemSortPointer);
  Sort* sortPointer = new Sort(solver->mkSequenceSort(*elemSort));
  return reinterpret_cast<jlong>(sortPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkUninterpretedSort
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkUninterpretedSort(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer,
                                                             jstring jSymbol)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;

  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* cSymbol = env->GetStringUTFChars(jSymbol, nullptr);
  Sort* sort = new Sort(solver->mkUninterpretedSort(std::string(cSymbol)));
  env->ReleaseStringUTFChars(jSymbol, cSymbol);
  return reinterpret_cast<jlong>(sort);

  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkSortConstructorSort
 * Signature: (JLjava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkSortConstructorSort(
    JNIEnv* env, jobject, jlong pointer, jstring jSymbol, jint arity)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;

  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  Sort* retPointer =
      new Sort(solver->mkSortConstructorSort(cSymbol, (size_t)arity));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);

  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTupleSort
 * Signature: (J[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTupleSort(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer,
                                                     jlongArray sortPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Sort> sorts = getObjectsFromPointers<Sort>(env, sortPointers);
  Sort* retPointer = new Sort(solver->mkTupleSort(sorts));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JI(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jint kindValue)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  Term* retPointer = new Term(solver->mkTerm(kind));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JIJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JIJ(
    JNIEnv* env, jobject, jlong pointer, jint kindValue, jlong childPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  Term* child = reinterpret_cast<Term*>(childPointer);
  Term* termPointer = new Term(solver->mkTerm(kind, *child));
  return reinterpret_cast<jlong>(termPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JIJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JIJJ(JNIEnv* env,
                                                      jobject,
                                                      jlong pointer,
                                                      jint kindValue,
                                                      jlong child1Pointer,
                                                      jlong child2Pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  Term* child1 = reinterpret_cast<Term*>(child1Pointer);
  Term* child2 = reinterpret_cast<Term*>(child2Pointer);
  Term* termPointer = new Term(solver->mkTerm(kind, *child1, *child2));
  return reinterpret_cast<jlong>(termPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JIJJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JIJJJ(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer,
                                                       jint kindValue,
                                                       jlong child1Pointer,
                                                       jlong child2Pointer,
                                                       jlong child3Pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  Term* child1 = reinterpret_cast<Term*>(child1Pointer);
  Term* child2 = reinterpret_cast<Term*>(child2Pointer);
  Term* child3 = reinterpret_cast<Term*>(child3Pointer);
  Term* retPointer = new Term(solver->mkTerm(kind, *child1, *child2, *child3));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JI[J)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_mkTerm__JI_3J(JNIEnv* env,
                               jobject,
                               jlong pointer,
                               jint kindValue,
                               jlongArray childrenPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  std::vector<Term> children =
      getObjectsFromPointers<Term>(env, childrenPointers);
  Term* retPointer = new Term(solver->mkTerm(kind, children));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JJ(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jlong opPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Op* op = reinterpret_cast<Op*>(opPointer);
  Term* retPointer = new Term(solver->mkTerm(*op));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JJJ(
    JNIEnv* env, jobject, jlong pointer, jlong opPointer, jlong childPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Op* op = reinterpret_cast<Op*>(opPointer);
  Term* child = reinterpret_cast<Term*>(childPointer);
  Term* retPointer = new Term(solver->mkTerm(*op, *child));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JJJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JJJJ(JNIEnv* env,
                                                      jobject,
                                                      jlong pointer,
                                                      jlong opPointer,
                                                      jlong child1Pointer,
                                                      jlong child2Pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Op* op = reinterpret_cast<Op*>(opPointer);
  Term* child1 = reinterpret_cast<Term*>(child1Pointer);
  Term* child2 = reinterpret_cast<Term*>(child2Pointer);
  Term* retPointer = new Term(solver->mkTerm(*op, *child1, *child2));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JJJJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTerm__JJJJJ(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer,
                                                       jlong opPointer,
                                                       jlong child1Pointer,
                                                       jlong child2Pointer,
                                                       jlong child3Pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Op* op = reinterpret_cast<Op*>(opPointer);
  Term* child1 = reinterpret_cast<Term*>(child1Pointer);
  Term* child2 = reinterpret_cast<Term*>(child2Pointer);
  Term* child3 = reinterpret_cast<Term*>(child3Pointer);
  Term* retPointer = new Term(solver->mkTerm(*op, *child1, *child2, *child3));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTerm
 * Signature: (JJ[J)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_mkTerm__JJ_3J(JNIEnv* env,
                               jobject,
                               jlong pointer,
                               jlong opPointer,
                               jlongArray childrenPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Op* op = reinterpret_cast<Op*>(opPointer);
  std::vector<Term> children =
      getObjectsFromPointers<Term>(env, childrenPointers);
  Term* retPointer = new Term(solver->mkTerm(*op, children));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTuple
 * Signature: (J[J[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTuple(JNIEnv* env,
                                                 jobject,
                                                 jlong pointer,
                                                 jlongArray sortPointers,
                                                 jlongArray termPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Sort> sorts = getObjectsFromPointers<Sort>(env, sortPointers);
  std::vector<Term> terms = getObjectsFromPointers<Term>(env, termPointers);
  Term* retPointer = new Term(solver->mkTuple(sorts, terms));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkOp
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkOp__JI(JNIEnv* env,
                                                  jobject,
                                                  jlong pointer,
                                                  jint kindValue)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  Op* retPointer = new Op(solver->mkOp(kind));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkOp
 * Signature: (JILjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkOp__JILjava_lang_String_2(
    JNIEnv* env, jobject, jlong pointer, jint kindValue, jstring jArg)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  const char* s = env->GetStringUTFChars(jArg, nullptr);
  std::string cArg(s);

  Op* retPointer = new Op(solver->mkOp(kind, cArg));

  env->ReleaseStringUTFChars(jArg, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkOp
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkOp__JII(
    JNIEnv* env, jobject, jlong pointer, jint kindValue, jint arg)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  Op* retPointer = new Op(solver->mkOp(kind, (uint32_t)arg));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkOp
 * Signature: (JIII)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkOp__JIII(
    JNIEnv* env, jobject, jlong pointer, jint kindValue, jint arg1, jint arg2)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;
  Op* retPointer = new Op(solver->mkOp(kind, (uint32_t)arg1, (uint32_t)arg2));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkOp
 * Signature: (JI[I)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkOp__JI_3I(
    JNIEnv* env, jobject, jlong pointer, jint kindValue, jintArray jArgs)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Kind kind = (Kind)kindValue;

  jsize size = env->GetArrayLength(jArgs);
  jint* argElements = env->GetIntArrayElements(jArgs, nullptr);

  std::vector<uint32_t> cArgs(size);
  for (jsize i = 0; i < size; i++)
  {
    cArgs[i] = (uint32_t)argElements[i];
  }
  env->ReleaseIntArrayElements(jArgs, argElements, 0);

  Op* retPointer = new Op(solver->mkOp(kind, cArgs));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkTrue
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkTrue(JNIEnv* env,
                                                jobject,
                                                jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* termPointer = new Term(solver->mkTrue());
  return reinterpret_cast<jlong>(termPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkFalse
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkFalse(JNIEnv* env,
                                                 jobject,
                                                 jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* termPointer = new Term(solver->mkFalse());
  return reinterpret_cast<jlong>(termPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkBoolean
 * Signature: (JZ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkBoolean(JNIEnv* env,
                                                   jobject,
                                                   jlong pointer,
                                                   jboolean val)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkBoolean((bool)val));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkPi
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkPi(JNIEnv* env,
                                              jobject,
                                              jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkPi());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkInteger
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkInteger__JLjava_lang_String_2(
    JNIEnv* env, jobject, jlong pointer, jstring jS)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jS, nullptr);
  std::string cS(s);
  Term* retPointer = new Term(solver->mkInteger(cS));
  env->ReleaseStringUTFChars(jS, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkInteger
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkInteger__JJ(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer,
                                                       jlong val)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* termPointer = new Term(solver->mkInteger((int64_t)val));
  return reinterpret_cast<jlong>(termPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkReal
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkReal__JLjava_lang_String_2(
    JNIEnv* env, jobject, jlong pointer, jstring jS)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jS, nullptr);
  std::string cS(s);
  Term* retPointer = new Term(solver->mkReal(cS));
  env->ReleaseStringUTFChars(jS, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkRealValue
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkRealValue(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer,
                                                     jlong val)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkReal((int64_t)val));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkReal
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkReal__JJJ(
    JNIEnv* env, jobject, jlong pointer, jlong num, jlong den)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkReal((int64_t)num, (int64_t)den));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkRegexpEmpty
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkRegexpEmpty(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkRegexpEmpty());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkRegexpSigma
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkRegexpSigma(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkRegexpSigma());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkEmptySet
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkEmptySet(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer = new Term(solver->mkEmptySet(*sort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkEmptyBag
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkEmptyBag(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer = new Term(solver->mkEmptyBag(*sort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkSepNil
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkSepNil(JNIEnv* env,
                                                  jobject,
                                                  jlong pointer,
                                                  jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer = new Term(solver->mkSepNil(*sort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkString
 * Signature: (JLjava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkString__JLjava_lang_String_2Z(
    JNIEnv* env, jobject, jlong pointer, jstring jS, jboolean useEscSequences)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jS, nullptr);
  std::string cS(s);
  Term* retPointer = new Term(solver->mkString(cS, (bool)useEscSequences));
  env->ReleaseStringUTFChars(jS, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkEmptySequence
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkEmptySequence(JNIEnv* env,
                                                         jobject,
                                                         jlong pointer,
                                                         jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer = new Term(solver->mkEmptySequence(*sort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkUniverseSet
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkUniverseSet(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer,
                                                       jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer = new Term(solver->mkUniverseSet(*sort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkBitVector
 * Signature: (JIJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkBitVector__JIJ(
    JNIEnv* env, jobject, jlong pointer, jint size, jlong val)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer =
      new Term(solver->mkBitVector((uint32_t)size, (uint64_t)val));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkBitVector
 * Signature: (JILjava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkBitVector__JILjava_lang_String_2I(
    JNIEnv* env, jobject, jlong pointer, jint size, jstring jS, jint base)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jS, nullptr);
  std::string cS(s);
  Term* retPointer =
      new Term(solver->mkBitVector((uint32_t)size, cS, (uint32_t)base));
  env->ReleaseStringUTFChars(jS, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkConstArray
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkConstArray(
    JNIEnv* env, jobject, jlong pointer, jlong sortPointer, jlong valPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* val = reinterpret_cast<Term*>(valPointer);
  Term* retPointer = new Term(solver->mkConstArray(*sort, *val));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkPosInf
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkPosInf(
    JNIEnv* env, jobject, jlong pointer, jint exp, jint sig)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkPosInf((uint32_t)exp, (uint32_t)sig));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkNegInf
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkNegInf(
    JNIEnv* env, jobject, jlong pointer, jint exp, jint sig)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkNegInf((uint32_t)exp, (uint32_t)sig));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkNaN
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_mkNaN(JNIEnv* env, jobject, jlong pointer, jint exp, jint sig)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkNaN((uint32_t)exp, (uint32_t)sig));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkPosZero
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkPosZero(
    JNIEnv* env, jobject, jlong pointer, jint exp, jint sig)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkPosZero((uint32_t)exp, (uint32_t)sig));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkNegZero
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkNegZero(
    JNIEnv* env, jobject, jlong pointer, jint exp, jint sig)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkNegZero((uint32_t)exp, (uint32_t)sig));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkRoundingMode
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkRoundingMode(JNIEnv* env,
                                                        jobject,
                                                        jlong pointer,
                                                        jint rm)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkRoundingMode((RoundingMode)rm));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkUninterpretedConst
 * Signature: (JJI)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkUninterpretedConst(
    JNIEnv* env, jobject, jlong pointer, jlong sortPointer, jint index)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer =
      new Term(solver->mkUninterpretedConst(*sort, (int32_t)index));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkAbstractValue
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkAbstractValue__JLjava_lang_String_2(
    JNIEnv* env, jobject, jlong pointer, jstring jIndex)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jIndex, nullptr);
  std::string cIndex(s);
  Term* retPointer = new Term(solver->mkAbstractValue(cIndex));
  env->ReleaseStringUTFChars(jIndex, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkAbstractValue
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkAbstractValue__JJ(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer,
                                                             jlong index)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->mkAbstractValue((uint64_t)index));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkFloatingPoint
 * Signature: (JIIJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkFloatingPoint(
    JNIEnv* env, jobject, jlong pointer, jint exp, jint sig, jlong valPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* val = reinterpret_cast<Term*>(valPointer);
  Term* retPointer =
      new Term(solver->mkFloatingPoint((uint32_t)exp, (uint32_t)sig, *val));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkConst
 * Signature: (JJLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkConst__JJLjava_lang_String_2(
    JNIEnv* env, jobject, jlong pointer, jlong sortPointer, jstring jSymbol)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  Term* retPointer = new Term(solver->mkConst(*sort, cSymbol));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkConst
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkConst__JJ(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer,
                                                     jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer = new Term(solver->mkConst(*sort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkVar
 * Signature: (JJLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkVar(
    JNIEnv* env, jobject, jlong pointer, jlong sortPointer, jstring jSymbol)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;

  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  Term* ret = new Term(solver->mkVar(*sort, cSymbol));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkDatatypeConstructorDecl
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkDatatypeConstructorDecl(
    JNIEnv* env, jobject, jlong pointer, jstring jName)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jName, nullptr);
  std::string cName(s);

  DatatypeConstructorDecl* retPointer =
      new DatatypeConstructorDecl(solver->mkDatatypeConstructorDecl(cName));
  env->ReleaseStringUTFChars(jName, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkDatatypeDecl
 * Signature: (JLjava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkDatatypeDecl__JLjava_lang_String_2Z(
    JNIEnv* env, jobject, jlong pointer, jstring jName, jboolean isCoDatatype)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jName, nullptr);
  std::string cName(s);
  DatatypeDecl* retPointer =
      new DatatypeDecl(solver->mkDatatypeDecl(cName, (bool)isCoDatatype));
  env->ReleaseStringUTFChars(jName, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkDatatypeDecl
 * Signature: (JLjava/lang/String;JZ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_mkDatatypeDecl__JLjava_lang_String_2JZ(JNIEnv* env,
                                                        jobject,
                                                        jlong pointer,
                                                        jstring jName,
                                                        jlong paramPointer,
                                                        jboolean isCoDatatype)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jName, nullptr);
  std::string cName(s);
  Sort* param = reinterpret_cast<Sort*>(paramPointer);
  DatatypeDecl* retPointer = new DatatypeDecl(
      solver->mkDatatypeDecl(cName, *param, (bool)isCoDatatype));
  env->ReleaseStringUTFChars(jName, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkDatatypeDecl
 * Signature: (JLjava/lang/String;[JZ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_mkDatatypeDecl__JLjava_lang_String_2_3JZ(JNIEnv* env,
                                                          jobject,
                                                          jlong pointer,
                                                          jstring jName,
                                                          jlongArray jParams,
                                                          jboolean isCoDatatype)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jName, nullptr);
  std::string cName(s);
  std::vector<Sort> params = getObjectsFromPointers<Sort>(env, jParams);
  DatatypeDecl* retPointer = new DatatypeDecl(
      solver->mkDatatypeDecl(cName, params, (bool)isCoDatatype));
  env->ReleaseStringUTFChars(jName, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    simplify
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_simplify(JNIEnv* env,
                                                  jobject,
                                                  jlong pointer,
                                                  jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* retPointer = new Term(solver->simplify(*term));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    assertFormula
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_assertFormula(JNIEnv* env,
                                                      jobject,
                                                      jlong pointer,
                                                      jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  solver->assertFormula(*term);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    checkSat
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_checkSat(JNIEnv* env,
                                                  jobject,
                                                  jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Result* retPointer = new Result(solver->checkSat());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    checkSatAssuming
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_checkSatAssuming__JJ(
    JNIEnv* env, jobject, jlong pointer, jlong assumptionPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* assumption = reinterpret_cast<Term*>(assumptionPointer);
  Result* retPointer = new Result(solver->checkSatAssuming(*assumption));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    checkSatAssuming
 * Signature: (J[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_checkSatAssuming__J_3J(
    JNIEnv* env, jobject, jlong pointer, jlongArray jAssumptions)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> assumptions =
      getObjectsFromPointers<Term>(env, jAssumptions);
  Result* retPointer = new Result(solver->checkSatAssuming(assumptions));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    checkEntailed
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_checkEntailed__JJ(JNIEnv* env,
                                                           jobject,
                                                           jlong pointer,
                                                           jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Result* retPointer = new Result(solver->checkEntailed(*term));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    checkEntailed
 * Signature: (J[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_checkEntailed__J_3J(JNIEnv* env,
                                                             jobject,
                                                             jlong pointer,
                                                             jlongArray jTerms)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> terms = getObjectsFromPointers<Term>(env, jTerms);
  Result* retPointer = new Result(solver->checkEntailed(terms));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    declareDatatype
 * Signature: (JLjava/lang/String;[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_declareDatatype(
    JNIEnv* env, jobject, jlong pointer, jstring jSymbol, jlongArray jCtors)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<DatatypeConstructorDecl> ctors =
      getObjectsFromPointers<DatatypeConstructorDecl>(env, jCtors);
  Sort* retPointer = new Sort(solver->declareDatatype(cSymbol, ctors));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    declareFun
 * Signature: (JLjava/lang/String;[JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_declareFun(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jstring jSymbol,
                                                    jlongArray jSorts,
                                                    jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<Sort> sorts = getObjectsFromPointers<Sort>(env, jSorts);
  Term* retPointer = new Term(solver->declareFun(cSymbol, sorts, *sort));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    declareSort
 * Signature: (JLjava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_declareSort(
    JNIEnv* env, jobject, jlong pointer, jstring jSymbol, jint arity)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  Sort* retPointer = new Sort(solver->declareSort(cSymbol, (uint32_t)arity));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    defineFun
 * Signature: (JLjava/lang/String;[JJJZ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_defineFun__JLjava_lang_String_2_3JJJZ(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer,
                                                       jstring jSymbol,
                                                       jlongArray jVars,
                                                       jlong sortPointer,
                                                       jlong termPointer,
                                                       jboolean global)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<Term> vars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer =
      new Term(solver->defineFun(cSymbol, vars, *sort, *term, (bool)global));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    defineFun
 * Signature: (JJ[JJZ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_defineFun__JJ_3JJZ(JNIEnv* env,
                                                            jobject,
                                                            jlong pointer,
                                                            jlong funPointer,
                                                            jlongArray jVars,
                                                            jlong termPointer,
                                                            jboolean global)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* fun = reinterpret_cast<Term*>(funPointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  std::vector<Term> vars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer =
      new Term(solver->defineFun(*fun, vars, *term, (bool)global));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    defineFunRec
 * Signature: (JLjava/lang/String;[JJJZ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_defineFunRec__JLjava_lang_String_2_3JJJZ(JNIEnv* env,
                                                          jobject,
                                                          jlong pointer,
                                                          jstring jSymbol,
                                                          jlongArray jVars,
                                                          jlong sortPointer,
                                                          jlong termPointer,
                                                          jboolean global)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<Term> vars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer =
      new Term(solver->defineFunRec(cSymbol, vars, *sort, *term, (bool)global));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    defineFunRec
 * Signature: (JJ[JJZ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_defineFunRec__JJ_3JJZ(JNIEnv* env,
                                       jobject,
                                       jlong pointer,
                                       jlong funPointer,
                                       jlongArray jVars,
                                       jlong termPointer,
                                       jboolean global)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* fun = reinterpret_cast<Term*>(funPointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  std::vector<Term> vars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer =
      new Term(solver->defineFunRec(*fun, vars, *term, (bool)global));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    defineFunsRec
 * Signature: (J[J[[J[JZ)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_defineFunsRec(JNIEnv* env,
                                                      jobject,
                                                      jlong pointer,
                                                      jlongArray jFuns,
                                                      jobjectArray jVars,
                                                      jlongArray jTerms,
                                                      jboolean global)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> funs = getObjectsFromPointers<Term>(env, jFuns);
  std::vector<Term> terms = getObjectsFromPointers<Term>(env, jTerms);
  std::vector<std::vector<Term>> varsMatrix;
  jsize rows = env->GetArrayLength(jVars);
  for (jint i = 0; i < rows; i++)
  {
    std::vector<Term> vars;
    jlongArray row = (jlongArray)env->GetObjectArrayElement(jVars, i);
    jsize columns = env->GetArrayLength(row);
    jlong* columnElements = env->GetLongArrayElements(row, nullptr);
    for (jint j = 0; j < columns; j++)
    {
      Term* var = reinterpret_cast<Term*>((jlongArray)columnElements[j]);
      vars.push_back(*var);
    }
    varsMatrix.push_back(vars);
  }
  solver->defineFunsRec(funs, varsMatrix, terms, (bool)global);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    getAssertions
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc5_Solver_getAssertions(JNIEnv* env,
                                                            jobject,
                                                            jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> assertions = solver->getAssertions();
  jlongArray ret = getPointersFromObjects<Term>(env, assertions);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     cvc5_Solver
 * Method:    getInfo
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc5_Solver_getInfo(JNIEnv* env,
                                                   jobject,
                                                   jlong pointer,
                                                   jstring jFlag)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jFlag, nullptr);
  std::string cFlag(s);
  env->ReleaseStringUTFChars(jFlag, s);
  return env->NewStringUTF(solver->getInfo(cFlag).c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getOption
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc5_Solver_getOption(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer,
                                                     jstring jOption)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jOption, nullptr);
  std::string cOption(s);
  env->ReleaseStringUTFChars(jOption, s);
  return env->NewStringUTF(solver->getOption(cOption).c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getUnsatAssumptions
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc5_Solver_getUnsatAssumptions(JNIEnv* env,
                                                                  jobject,
                                                                  jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> core = solver->getUnsatAssumptions();
  jlongArray ret = getPointersFromObjects<Term>(env, core);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     cvc5_Solver
 * Method:    getUnsatCore
 * Signature: (J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc5_Solver_getUnsatCore(JNIEnv* env,
                                                           jobject,
                                                           jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> core = solver->getUnsatCore();
  jlongArray ret = getPointersFromObjects<Term>(env, core);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     cvc5_Solver
 * Method:    getValue
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getValue__JJ(JNIEnv* env,
                                                      jobject,
                                                      jlong pointer,
                                                      jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* retPointer = new Term(solver->getValue(*term));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getValue
 * Signature: (J[J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc5_Solver_getValue__J_3J(
    JNIEnv* env, jobject, jlong pointer, jlongArray termPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> terms = getObjectsFromPointers<Term>(env, termPointers);
  std::vector<Term> values = solver->getValue(terms);
  jlongArray ret = getPointersFromObjects<Term>(env, values);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    isModelCoreSymbol
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_cvc5_Solver_isModelCoreSymbol(JNIEnv* env,
                                                              jobject,
                                                              jlong pointer,
                                                              jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  return static_cast<jboolean>(solver->isModelCoreSymbol(*term));
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, static_cast<jboolean>(false));
}

/*
 * Class:     cvc5_Solver
 * Method:    getModel
 * Signature: (J[J[J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cvc5_Solver_getModel(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jlongArray sortPointers,
                                                    jlongArray varPointers)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Sort> sorts = getObjectsFromPointers<Sort>(env, sortPointers);
  std::vector<Term> vars = getObjectsFromPointers<Term>(env, varPointers);
  std::string model = solver->getModel(sorts, vars);
  return env->NewStringUTF(model.c_str());
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getQuantifierElimination
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getQuantifierElimination(
    JNIEnv* env, jobject, jlong pointer, jlong qPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* q = reinterpret_cast<Term*>(qPointer);
  Term* retPointer = new Term(solver->getQuantifierElimination(*q));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getQuantifierEliminationDisjunct
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getQuantifierEliminationDisjunct(
    JNIEnv* env, jobject, jlong pointer, jlong qPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* q = reinterpret_cast<Term*>(qPointer);
  Term* retPointer = new Term(solver->getQuantifierEliminationDisjunct(*q));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    declareSeparationHeap
 * Signature: (JJJ)V
 */
JNIEXPORT void JNICALL
Java_cvc5_Solver_declareSeparationHeap(JNIEnv* env,
                                       jobject,
                                       jlong pointer,
                                       jlong locSortPointer,
                                       jlong dataSortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* locSort = reinterpret_cast<Sort*>(locSortPointer);
  Sort* dataSort = reinterpret_cast<Sort*>(dataSortPointer);
  solver->declareSeparationHeap(*locSort, *dataSort);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    getSeparationHeap
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getSeparationHeap(JNIEnv* env,
                                                           jobject,
                                                           jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->getSeparationHeap());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getSeparationNilTerm
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getSeparationNilTerm(JNIEnv* env,
                                                              jobject,
                                                              jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* retPointer = new Term(solver->getSeparationNilTerm());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    pop
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_pop(JNIEnv* env,
                                            jobject,
                                            jlong pointer,
                                            jint nscopes)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  solver->pop((uint32_t)nscopes);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    getInterpolant
 * Signature: (JJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_cvc5_Solver_getInterpolant__JJJ(
    JNIEnv* env, jobject, jlong pointer, jlong conjPointer, jlong outputPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* conj = reinterpret_cast<Term*>(conjPointer);
  Term* output = reinterpret_cast<Term*>(outputPointer);
  return (jboolean)solver->getInterpolant(*conj, *output);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getInterpolant
 * Signature: (JJJJ)Z
 */
JNIEXPORT jboolean JNICALL
Java_cvc5_Solver_getInterpolant__JJJJ(JNIEnv* env,
                                      jobject,
                                      jlong pointer,
                                      jlong conjPointer,
                                      jlong grammarPointer,
                                      jlong outputPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* conj = reinterpret_cast<Term*>(conjPointer);
  Grammar* grammar = reinterpret_cast<Grammar*>(grammarPointer);
  Term* output = reinterpret_cast<Term*>(outputPointer);
  return (jboolean)solver->getInterpolant(*conj, *grammar, *output);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getAbduct
 * Signature: (JJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_cvc5_Solver_getAbduct__JJJ(
    JNIEnv* env, jobject, jlong pointer, jlong conjPointer, jlong outputPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* conj = reinterpret_cast<Term*>(conjPointer);
  Term* output = reinterpret_cast<Term*>(outputPointer);
  return (jboolean)solver->getAbduct(*conj, *output);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getAbduct
 * Signature: (JJJJ)Z
 */
JNIEXPORT jboolean JNICALL
Java_cvc5_Solver_getAbduct__JJJJ(JNIEnv* env,
                                 jobject,
                                 jlong pointer,
                                 jlong conjPointer,
                                 jlong grammarPointer,
                                 jlong outputPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* conj = reinterpret_cast<Term*>(conjPointer);
  Grammar* grammar = reinterpret_cast<Grammar*>(grammarPointer);
  Term* output = reinterpret_cast<Term*>(outputPointer);
  return (jboolean)solver->getAbduct(*conj, *grammar, *output);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    blockModel
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_blockModel(JNIEnv* env,
                                                   jobject,
                                                   jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  solver->blockModel();
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    blockModelValues
 * Signature: (J[J)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_blockModelValues(JNIEnv* env,
                                                         jobject,
                                                         jlong pointer,
                                                         jlongArray jTerms)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> terms = getObjectsFromPointers<Term>(env, jTerms);
  solver->blockModelValues(terms);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    push
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_push(JNIEnv* env,
                                             jobject,
                                             jlong pointer,
                                             jint nscopes)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  solver->push((uint32_t)nscopes);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    resetAssertions
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_resetAssertions(JNIEnv* env,
                                                        jobject,
                                                        jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  solver->resetAssertions();
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    setInfo
 * Signature: (JLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_setInfo(
    JNIEnv* env, jobject, jlong pointer, jstring jKeyword, jstring jValue)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* sKeyword = env->GetStringUTFChars(jKeyword, nullptr);
  const char* sValue = env->GetStringUTFChars(jValue, nullptr);
  std::string cKeyword(sKeyword);
  std::string cValue(sValue);
  solver->setInfo(cKeyword, cValue);
  env->ReleaseStringUTFChars(jKeyword, sKeyword);
  env->ReleaseStringUTFChars(jValue, sValue);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    setLogic
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_setLogic(JNIEnv* env,
                                                 jobject,
                                                 jlong pointer,
                                                 jstring jLogic)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;

  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* cLogic = env->GetStringUTFChars(jLogic, nullptr);
  solver->setLogic(std::string(cLogic));

  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    setOption
 * Signature: (JLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_setOption(
    JNIEnv* env, jobject, jlong pointer, jstring jOption, jstring jValue)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* sOption = env->GetStringUTFChars(jOption, nullptr);
  const char* sValue = env->GetStringUTFChars(jValue, nullptr);
  std::string cOption(sOption);
  std::string cValue(sValue);
  solver->setOption(cOption, cValue);
  env->ReleaseStringUTFChars(jOption, sOption);
  env->ReleaseStringUTFChars(jValue, sValue);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    ensureTermSort
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_ensureTermSort(
    JNIEnv* env, jobject, jlong pointer, jlong termPointer, jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Term* retPointer = new Term(solver->ensureTermSort(*term, *sort));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkSygusVar
 * Signature: (JJLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkSygusVar(
    JNIEnv* env, jobject, jlong pointer, jlong sortPointer, jstring jSymbol)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  Term* retPointer = new Term(solver->mkSygusVar(*sort, cSymbol));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    mkSygusGrammar
 * Signature: (J[J[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_mkSygusGrammar(JNIEnv* env,
                                                        jobject,
                                                        jlong pointer,
                                                        jlongArray jBoundVars,
                                                        jlongArray jNtSymbols)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> boundVars = getObjectsFromPointers<Term>(env, jBoundVars);
  std::vector<Term> ntSymbols = getObjectsFromPointers<Term>(env, jNtSymbols);
  Grammar* retPointer =
      new Grammar(solver->mkSygusGrammar(boundVars, ntSymbols));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    synthFun
 * Signature: (JLjava/lang/String;[JJ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_synthFun__JLjava_lang_String_2_3JJ(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jstring jSymbol,
                                                    jlongArray jVars,
                                                    jlong sortPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<Term> boundVars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer = new Term(solver->synthFun(cSymbol, boundVars, *sort));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    synthFun
 * Signature: (JLjava/lang/String;[JJJ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_synthFun__JLjava_lang_String_2_3JJJ(JNIEnv* env,
                                                     jobject,
                                                     jlong pointer,
                                                     jstring jSymbol,
                                                     jlongArray jVars,
                                                     jlong sortPointer,
                                                     jlong grammarPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Sort* sort = reinterpret_cast<Sort*>(sortPointer);
  Grammar* grammar = reinterpret_cast<Grammar*>(grammarPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<Term> boundVars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer =
      new Term(solver->synthFun(cSymbol, boundVars, *sort, *grammar));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    synthInv
 * Signature: (JLjava/lang/String;[J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_synthInv__JLjava_lang_String_2_3J(
    JNIEnv* env, jobject, jlong pointer, jstring jSymbol, jlongArray jVars)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<Term> vars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer = new Term(solver->synthInv(cSymbol, vars));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    synthInv
 * Signature: (JLjava/lang/String;[JJ)J
 */
JNIEXPORT jlong JNICALL
Java_cvc5_Solver_synthInv__JLjava_lang_String_2_3JJ(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer,
                                                    jstring jSymbol,
                                                    jlongArray jVars,
                                                    jlong grammarPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Grammar* grammar = reinterpret_cast<Grammar*>(grammarPointer);
  const char* s = env->GetStringUTFChars(jSymbol, nullptr);
  std::string cSymbol(s);
  std::vector<Term> vars = getObjectsFromPointers<Term>(env, jVars);
  Term* retPointer = new Term(solver->synthInv(cSymbol, vars, *grammar));
  env->ReleaseStringUTFChars(jSymbol, s);
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    addSygusConstraint
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_cvc5_Solver_addSygusConstraint(JNIEnv* env,
                                                           jobject,
                                                           jlong pointer,
                                                           jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  solver->addSygusConstraint(*term);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    addSygusInvConstraint
 * Signature: (JJJJJ)V
 */
JNIEXPORT void JNICALL
Java_cvc5_Solver_addSygusInvConstraint(JNIEnv* env,
                                       jobject,
                                       jlong pointer,
                                       jlong invPointer,
                                       jlong prePointer,
                                       jlong transPointer,
                                       jlong postPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* inv = reinterpret_cast<Term*>(invPointer);
  Term* pre = reinterpret_cast<Term*>(prePointer);
  Term* trans = reinterpret_cast<Term*>(transPointer);
  Term* post = reinterpret_cast<Term*>(postPointer);
  solver->addSygusInvConstraint(*inv, *pre, *trans, *post);
  CVC5_JAVA_API_TRY_CATCH_END(env);
}

/*
 * Class:     cvc5_Solver
 * Method:    checkSynth
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_checkSynth(JNIEnv* env,
                                                    jobject,
                                                    jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Result* retPointer = new Result(solver->checkSynth());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getSynthSolution
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getSynthSolution(JNIEnv* env,
                                                          jobject,
                                                          jlong pointer,
                                                          jlong termPointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Term* term = reinterpret_cast<Term*>(termPointer);
  Term* retPointer = new Term(solver->getSynthSolution(*term));
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getSynthSolutions
 * Signature: (J[J)[J
 */
JNIEXPORT jlongArray JNICALL Java_cvc5_Solver_getSynthSolutions(
    JNIEnv* env, jobject, jlong pointer, jlongArray jTerms)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  std::vector<Term> terms = getObjectsFromPointers<Term>(env, jTerms);
  std::vector<Term> solutions = solver->getSynthSolutions(terms);
  jlongArray ret = getPointersFromObjects<Term>(env, solutions);
  return ret;
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, nullptr);
}

/*
 * Class:     cvc5_Solver
 * Method:    getStatistics
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getStatistics(JNIEnv* env,
                                                       jobject,
                                                       jlong pointer)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Solver* solver = reinterpret_cast<Solver*>(pointer);
  Statistics* retPointer = new Statistics(solver->getStatistics());
  return reinterpret_cast<jlong>(retPointer);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getNullTerm
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getNullTerm(JNIEnv* env,
                                                     jobject,
                                                     jlong)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Term* ret = new Term();
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getNullResult
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getNullResult(JNIEnv* env,
                                                       jobject,
                                                       jlong)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Result* ret = new Result();
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getNullOp
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getNullOp(JNIEnv* env, jobject, jlong)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  Op* ret = new Op();
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}

/*
 * Class:     cvc5_Solver
 * Method:    getNullDatatypeDecl
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_cvc5_Solver_getNullDatatypeDecl(JNIEnv* env,
                                                             jobject,
                                                             jlong)
{
  CVC5_JAVA_API_TRY_CATCH_BEGIN;
  DatatypeDecl* ret = new DatatypeDecl();
  return reinterpret_cast<jlong>(ret);
  CVC5_JAVA_API_TRY_CATCH_END_RETURN(env, 0);
}