cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

# create project
project(MyProject)
set(CMAKE_CXX_STANDARD 20)


# add dependencies
include(cmake/CPM.cmake)

add_compile_options("$<$<CONFIG:RELEASE>:-O3;-march=native;-mtune=native>")

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
CPMAddPackage(
  NAME ducc
  GIT_REPOSITORY https://github.com/ewoudwempe/ducc0.git
  GIT_TAG ducc0
  GIT_SHALLOW  YES
  EXCLUDE_FROM_ALL YES
  SYSTEM
  )
if(ducc_ADDED)
  add_library(ducc INTERFACE)
  set(SOURCES 
    healpix/healpix_base.cc
    healpix/healpix_tables.cc
    infra/communication.cc
    infra/mav.cc
    infra/string_utils.cc
    infra/system.cc
    infra/threading.cc
    infra/types.cc
    math/geom_utils.cc
    math/gl_integrator.cc
    math/gridding_kernel.cc
    math/pointing.cc
    math/space_filling.cc
    sht/sht.cc
    wgridder/wgridder.cc
  )
  list(TRANSFORM SOURCES PREPEND ${ducc_SOURCE_DIR}/src/ducc0/)
  target_sources(ducc PUBLIC ${SOURCES})
  target_include_directories(ducc SYSTEM INTERFACE ${ducc_SOURCE_DIR}/src/)
  #target_compile_features(ducc INTERFACE cxx_std_17 )
endif()

CPMAddPackage("gh:fmtlib/fmt#10.0.0")
#
# add executable
#
add_executable(main main.cpp)

target_link_libraries(main PRIVATE finufft nanobench ducc fmt::fmt)
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
