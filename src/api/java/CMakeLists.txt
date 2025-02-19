###############################################################################
# Top contributors (to current version):
#   Mudathir Mohamed, Mathias Preiner, Aina Niemetz
#
# This file is part of the cvc5 project.
#
# Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
# in the top-level source directory and their institutional affiliations.
# All rights reserved.  See the file COPYING in the top-level source
# directory for licensing information.
# #############################################################################
#
# The build system configuration.
##

# create directories
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/src/api/java/cvc5")
set(JNI_DIR "${CMAKE_CURRENT_BINARY_DIR}/src/api/java/jni")
file(MAKE_DIRECTORY ${JNI_DIR})

# Generate cvc5/Kind.java
configure_file(genkinds.py.in genkinds.py)

set(JAVA_KIND_FILE
  "${CMAKE_CURRENT_BINARY_DIR}/src/api/java/cvc5/Kind.java"
)

add_custom_command(
  OUTPUT
    ${JAVA_KIND_FILE}
  BYPRODUCTS
    ${JAVA_KIND_FILE}
  COMMAND
    "${PYTHON_EXECUTABLE}"
    "${CMAKE_CURRENT_BINARY_DIR}/genkinds.py"
    --kinds-header "${PROJECT_SOURCE_DIR}/src/api/cpp/cvc5_kind.h"
    --kinds-file-prefix "${CMAKE_CURRENT_BINARY_DIR}/src/api/java/cvc5/Kind"
  DEPENDS
    "${CMAKE_CURRENT_BINARY_DIR}/genkinds.py"
    "${PROJECT_SOURCE_DIR}/src/api/cpp/cvc5_kind.h"
)

add_custom_target(generate-java-kinds DEPENDS ${JAVA_KIND_FILE})

# find java
find_package(Java COMPONENTS Development REQUIRED)
include(UseJava)

# specify java source files
set(JAVA_FILES
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/AbstractPointer.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/CVC5ApiException.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/CVC5ApiRecoverableException.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Datatype.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/DatatypeConstructor.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/DatatypeConstructorDecl.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/DatatypeDecl.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/DatatypeSelector.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Grammar.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/IPointer.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Op.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Pair.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Result.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/RoundingMode.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Solver.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Sort.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Stat.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Statistics.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Term.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Triplet.java
  ${CMAKE_CURRENT_LIST_DIR}/cvc5/Utils.java
  ${JAVA_KIND_FILE}
)

# specify generated jni headers
set(JNI_HEADERS
  ${JNI_DIR}/cvc5_Solver.h
)

# generate jni headers
add_custom_command(
  OUTPUT
    ${JNI_HEADERS}
  BYPRODUCTS
    ${JNI_HEADERS}
  COMMAND
    # generate jni header files
    ${Java_JAVAC_EXECUTABLE} -h ${JNI_DIR} ${JAVA_FILES} -d ${JNI_DIR}
  DEPENDS
    ${JAVA_FILES}
  COMMENT "Generate jni headers"
  VERBATIM
)

add_custom_target(generate-jni-headers DEPENDS ${JNI_HEADERS})
add_dependencies(generate-jni-headers generate-java-kinds)

# find jni package
find_package(JNI REQUIRED)
message(STATUS "JAVA_AWT_LIBRARY     : ${JAVA_AWT_LIBRARY}")
message(STATUS "JNI_INCLUDE_DIRS     : ${JNI_INCLUDE_DIRS}")
message(STATUS "JNI_LIBRARIES        : ${JNI_LIBRARIES} ")
message(STATUS "JNI_FOUND            : ${JNI_FOUND}")
message(STATUS "JAVA_AWT_LIBRARY     : ${JAVA_AWT_LIBRARY}")
message(STATUS "JAVA_JVM_LIBRARY     : ${JAVA_JVM_LIBRARY}")
message(STATUS "JAVA_INCLUDE_PATH    : ${JAVA_INCLUDE_PATH}")
message(STATUS "JAVA_INCLUDE_PATH2   : ${JAVA_INCLUDE_PATH2}")
message(STATUS "JAVA_AWT_INCLUDE_PATH: ${JAVA_AWT_INCLUDE_PATH}")

add_library(cvc5jni SHARED
  jni/cvc5_Datatype.cpp
  jni/cvc5_DatatypeConstructor.cpp
  jni/cvc5_DatatypeConstructorDecl.cpp
  jni/cvc5_DatatypeDecl.cpp
  jni/cvc5_DatatypeSelector.cpp
  jni/cvc5_Grammar.cpp
  jni/cvc5_Op.cpp
  jni/cvc5_Result.cpp
  jni/cvc5_Solver.cpp
  jni/cvc5_Sort.cpp
  jni/cvc5_Stat.cpp
  jni/cvc5_Statistics.cpp
  jni/cvc5_Term.cpp)
add_dependencies(cvc5jni generate-jni-headers)

target_include_directories(cvc5jni PUBLIC ${JNI_INCLUDE_DIRS})
target_include_directories(cvc5jni PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(cvc5jni PUBLIC ${CMAKE_BINARY_DIR}/src/)
target_include_directories(cvc5jni PUBLIC ${JNI_DIR})
target_link_libraries(cvc5jni PRIVATE ${JNI_LIBRARIES})
target_link_libraries(cvc5jni PRIVATE cvc5-shared)

set(CVC5_JAR "cvc5-${CVC5_VERSION}.jar")

# create cvc5.jar file
add_jar(cvc5jar
  SOURCES
  ${JAVA_FILES}
  VERSION ${CVC5_VERSION}
  OUTPUT_NAME cvc5
)
set_target_properties(cvc5jar PROPERTIES SOURCES "${JAVA_FILES}")

add_dependencies(cvc5jar generate-java-kinds cvc5jni cvc5-shared)
