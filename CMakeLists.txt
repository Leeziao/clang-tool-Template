project(cmake-search-clang)
cmake_minimum_required(VERSION 3.12)

# set(CMAKE_VERBOSE_MAKEFILE ON)

if (NOT DEFINED ENV{LLVM_ROOT})
	message(FATAL_ERROR "Environmental Variable LLVM_ROOT is not set, please set to the path to build directory")
else()
	file(TO_CMAKE_PATH $ENV{LLVM_ROOT} LLVM_ROOT)
	message(STATUS "LLVM_ROOT is set to ${LLVM_ROOT}")
endif()

find_package(LLVM REQUIRED CONFIG HINTS ${LLVM_ROOT})
find_package(Clang REQUIRED CONFIG HINTS ${LLVM_ROOT})

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}" "${CLANG_CMAKE_DIR}")
message(STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
include(AddLLVM)
include(AddClang)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "LLVM STATUS:
Definitions: 	${LLVM_DEFINITIONS}
Includes:		${LLVM_INCLUDE_DIRS}
				${CLANG_INCLUDE_DIRS}
Libraries:		${LLVM_LIBRARY_DIRS}
Targets:		${LLVM_TARGETS_TO_BUILD}
LLVM Lib:		${LLVM_AVAILABLE_LIBS}
Clang Lib:		${CLANG_EXPORTED_TARGETS}
")

include_directories(SYSTEM ${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(REQ_LLVM_LIBRARIES ${LLVM_TARGETS_TO_BUILD}
    core support option)

unset(REQ_CLANG_LIBRARIES CACHE)
list(APPEND REQ_CLANG_LIBRARIES clangAST)
list(APPEND REQ_CLANG_LIBRARIES clangBasic)
list(APPEND REQ_CLANG_LIBRARIES clangCodeGen)
list(APPEND REQ_CLANG_LIBRARIES clangLex)
list(APPEND REQ_CLANG_LIBRARIES clangParse)
list(APPEND REQ_CLANG_LIBRARIES clangSema)
list(APPEND REQ_CLANG_LIBRARIES clangAnalysis)
list(APPEND REQ_CLANG_LIBRARIES clangDriver)
list(APPEND REQ_CLANG_LIBRARIES clangFrontend)
list(APPEND REQ_CLANG_LIBRARIES clangEdit)
list(APPEND REQ_CLANG_LIBRARIES clangSerialization)
list(APPEND REQ_CLANG_LIBRARIES clangTooling)
list(APPEND REQ_CLANG_LIBRARIES clangToolingCore)
# set(REQ_CLANG_LIBRARIES "clangAST;clangBasic;clangCodeGen;clangCodeGen;clangLex;clangParse;clangSema;clangAnalysis;clangDriver;clangFrontend;clangEdit;clangSerialization;clangTooling;clangToolingCore")

message(STATUS "REQ_LLVM_LIBRARIES: ${REQ_LLVM_LIBRARIES}")
message(STATUS "REQ_CLANG_LIBRARIES: ${REQ_CLANG_LIBRARIES}")


# Final Build
include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(lib)
add_subdirectory(tools)

# target_link_libraries(test-clang
#   	${REQ_LLVM_LIBRARIES}
# )
