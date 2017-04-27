#ifndef LBMDEM_LB_GRID_H_
#define LBMDEM_LB_GRID_H_

#include <Kokkos_Core.hpp>

namespace lbmdem {
template <unsigned Tdim, unsigned Tq>
class LB_Grid;

template <unsigned Tq>
class LB_Grid<2,Tq> {
public:
  static const unsigned Tdim = 2;

  Kokkos::View<double**[Tq]> f;
  Kokkos::View<double**[Tdim]> force;

  LB_Grid() :
    f("f", 8, 8),
    force("force", 8, 8) {}

};

template <unsigned Tq>
class LB_Grid<3,Tq> {
public:
  static const unsigned Tdim = 3;

  Kokkos::View<double***[Tq]> f;
  Kokkos::View<double***[Tdim]> force;

  LB_Grid() :
    f("f", 8, 8, 8),
    force("force", 8, 8, 8) {}
};

} // namespace lbmdem

#endif  // LBMDEM_LB_GRID_H_
