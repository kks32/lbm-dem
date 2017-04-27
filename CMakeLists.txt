project(lbmdem LANGUAGES CXX)

# Require C++11-compliant compiler; only available for CMake v. 3.1 and up
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

cmake_minimum_required(VERSION 3.1)

SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_VERBOSE_MAKEFILE OFF)

# General compile settings
IF (NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "RelWithDebInfo")
ENDIF (NOT CMAKE_BUILD_TYPE)

# GNU Specific settings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-missing-braces")
endif()

# OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#  add_compile_options(${OpenMP_CXX_FLAGS})
endif()

# LBM-DEM settings
OPTION(USE_DOUBLE_PRECISION "Use double precision" ON)

# CMake Modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# KOKKOS
find_package(KOKKOS REQUIRED)
include_directories(${KOKKOS_INCLUDE_DIRS})
link_libraries(${KOKKOS_LIBRARIES})


# Include directories
include_directories(
  ${lbmdem_SOURCE_DIR}/include
  ${lbmdem_SOURCE_DIR}/external
)

# LBMDEM executable
SET(lbm_src
    src/lattice.cc
    src/main.cc
)
add_executable(lbmdem
               ${lbm_src}
)

# Unit test
SET(test_src
    src/lattice.cc
    tests/test.cc
    tests/lattice_test.cc
    tests/patch.cc
)
add_executable(lbmdemtest
               ${test_src}
)
add_test(NAME lbmdemtest COMMAND $<TARGET_FILE:lbmdemtest>)
include(CTest)

find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --error-exitcode=1" )

# Coverage
find_package(codecov)
add_coverage(lbmdem)
add_coverage(lbmdemtest)

install(TARGETS lbmdem lbmdemtest RUNTIME DESTINATION bin)
