project(lbmdem LANGUAGES CXX)

# Require C++11-compliant compiler; only available for CMake v. 3.1 and up
set(CMAKE_CXX_STANDARD 11)

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
endif()

# LBM-DEM settings
OPTION(USE_DOUBLE_PRECISION "Use double precision" ON)

# CMake Modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Include directories
include_directories(
  ${lbmdem_SOURCE_DIR}/include
  ${lbmdem_SOURCE_DIR}/external
)

# LBMDEM executable
SET(lbm_src
    src/main.cc
)
add_executable(lbmdem
               ${lbm_src}
)

# Unit test
SET(test_src
    tests/test.cc
    tests/model_test.cc
    tests/lb_node_2d_test.cc
    tests/lb_node_3d_test.cc
)
add_executable(lbmdemtest
               ${test_src}
)
add_test(NAME lbmdemtest COMMAND $<TARGET_FILE:lbmdemtest>)
enable_testing()

# Coverage
find_package(codecov)
add_coverage(lbmdem)
add_coverage(lbmdemtest)
