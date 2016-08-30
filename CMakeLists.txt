project(lbmdem LANGUAGES CXX)

# Require C++11-compliant compiler; only available for CMake v. 3.1 and up
set(CMAKE_CXX_STANDARD 11)

cmake_minimum_required(VERSION 3.1)

SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_VERBOSE_MAKEFILE OFF)

add_executable(lbmdem src/main.cc)

add_executable(lb_node_2d tests/lb_node_2d_test.cc)
add_executable(lb_node_3d tests/lb_node_3d_test.cc)

add_test(NAME lb_node_2d COMMAND $<TARGET_FILE:lb_node_2d>)
add_test(NAME lb_node_3d COMMAND $<TARGET_FILE:lb_node_3d>)

# LBM-DEM settings
OPTION(USE_DOUBLE_PRECISION "Use double precision" ON)

enable_testing()

IF (NOT CMAKE_BUILD_TYPE)
 SET(CMAKE_BUILD_TYPE "Debug")
 #SET(CMAKE_BUILD_TYPE "Release")
ENDIF (NOT CMAKE_BUILD_TYPE)

include_directories(
  ${lbmdem_SOURCE_DIR}/include
  ${lbmdem_SOURCE_DIR}/external
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
endif()
