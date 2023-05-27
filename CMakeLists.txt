cmake_minimum_required(VERSION 3.23)
project(CppHighProgramming)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)


####################################################
################ Setting Output Dir ################
####################################################

message(STATUS "CMAKE_BINARY_DIR is ${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


option(ENABLE_TEST "enable test" ON)
option(ENABLE_BENCHMARK "enable benchmark" ON)


set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_ROOT ${PROJECT_ROOT}/src)

### Find Package.

#add_subdirectory(benchmark)

set(PUBLIC_MODULE_INCLUDE_DIR_LIST "")
set(PUBLIC_MODULE_LIBRARY_DIR_LIST "")
set(PUBLIC_MODULE_LIBRARIES_LIST "")

set(PRIVATE_MODULE_INCLUDE_DIR_LIST "")
set(PRIVATE_MODULE_LIBRARY_DIR_LIST "")
set(PRIVATE_MODULE_LIBRARIES_LIST "")


list(APPEND CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake)
if (ENABLE_TEST)
  enable_testing()
  include(gtest)
endif ()


include(third-party)

add_subdirectory(src)
