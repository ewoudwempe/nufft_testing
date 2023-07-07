cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# create project
project(MyProject)


# add dependencies
include(cmake/CPM.cmake)

#CPMAddPackage("gh:fmtlib/fmt#7.1.3")
#CPMAddPackage("gh:nlohmann/json@3.10.5")
#CPMAddPackage("gh:catchorg/Catch2@3.2.1")
CPMAddPackage(
  NAME             finufft
  GIT_REPOSITORY   https://github.com/flatironinstitute/finufft.git
  GIT_TAG          master
  GIT_SHALLOW      Yes
  GIT_PROGRESS     Yes
  EXCLUDE_FROM_ALL Yes
  SYSTEM
)
CPMAddPackage("gh:martinus/nanobench@4.3.11")
#
# add executable
#

#include(FetchContent)
#FetchContent_Declare(
#  finufft
#  GIT_REPOSITORY https://github.com/flatironinstitute/finufft
#  GIT_TAG        v2.1.0
#)
#FetchContent_MakeAvailable(finufft)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE finufft nanobench)
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)

#target_include_directories(main PUBLIC ${finufft_SOURCE_DIR}/include/)


#add_dependencies(main finufft_static)

