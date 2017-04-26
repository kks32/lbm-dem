# - try to find KOKKOS
#
#  KOKKOS_INCLUDE_DIRS - where to find kokkos.h, etc
#  KOKKOS_LIBRARIES    - List of libraries when using kokkos.
#  KOKKOS_FOUND        - True if kokkos found.
#

if(NOT ${KOKKOS_ROOT})
	set(KOKKOS_ROOT "/usr" CACHE PATH "Root directory of Kokkos installation")
endif()

find_file(KOKKOS_CMAKE "kokkos.cmake" HINTS ${KOKKOS_ROOT} PATHS ENV CMAKE_PREFIX_PATH)
include(${KOKKOS_CMAKE})

find_path(KOKKOS_INCLUDE_DIR Kokkos_Core.hpp HINTS ${KOKKOS_ROOT}/include)

set(KOKKOS_LIBRARIES "${KOKKOS_LDFLAGS} ${KOKKOS_LIBS}")
set(KOKKOS_INCLUDE_DIRS "${KOKKOS_INCLUDE_DIR}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(KOKKOS DEFAULT_MSG KOKKOS_CMAKE KOKKOS_LIBRARIES KOKKOS_INCLUDE_DIRS)

mark_as_advanced(KOKKOS_INCLUDE_DIR KOKKOS_CMAKE)
