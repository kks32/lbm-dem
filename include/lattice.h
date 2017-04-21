#ifndef LBMDEM_LATTICE_H_
#define LBMDEM_LATTICE_H_

#include "settings.h"

namespace lbmdem {
//! Abstract Lattice base class
//! \brief Base class that stores the information about Lattice
//! \tparam Tdim Dimension
//! \tparam Tq Number of discrete velocity directions
template <unsigned Tdim, unsigned Tq>
class Lattice;
}

//! D2Q9 Lattice
//! \brief Weights for the D2Q9 stencil
template <>
class lbmdem::Lattice<2, 9> {
 public:
  lbmdem::Real weight(int x, int y) const {
    if (abs(x) > 1) return 0.0;
    if (abs(y) > 1) return 0.0;
    switch ((x == 0) + (y == 0)) {
      case 2:
        return 4.0 / 9.0;
      case 1:
        return 1.0 / 9.0;
      default:
        return 1.0 / 36.0;
    }
  }
};

//! D3Q27 Lattice
//! \brief Weights for the D3Q27 lattice
template <>
class lbmdem::Lattice<3, 27> {
 public:
  lbmdem::Real weight(int x, int y, int z) const {
    if (abs(x) > 1) return 0.0;
    if (abs(y) > 1) return 0.0;
    if (abs(z) > 1) return 0.0;
    switch ((x == 0) + (y == 0) + (z == 0)) {
      case 3:
        return 8.0 / 27.0;
      case 2:
        return 2.0 / 27.0;
      case 1:
        return 1.0 / 54.0;
      default:
        return 1.0 / 216.0;
    }
  }
};

#endif //LBMDEM_LATTICE_H_
