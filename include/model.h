#ifndef LBMDEM_MODEL_H_
#define LBMDEM_MODEL_H_

#include "settings.h"

namespace lbmdem {
//! Abstract Model base class
//! \brief Base class that stores the information about Lattice model
//! \tparam TD Dimension
//! \tparam TQ Number of discrete velocity directions
template <unsigned TD, unsigned TQ>
class Model;
}

//! D2Q9 Model
//! \brief Weights for the D2Q9 stencil
template <>
class lbmdem::Model<2, 9> {
 public:
  lbmdem::Real weight(int x, int y) const {
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

//! D3Q27 Model
//! \brief Weights for the D3Q27 lattice model
template <>
class lbmdem::Model<3, 27> {
 public:
  lbmdem::Real weight(int x, int y, int z) const {
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

#endif //LBMDEM_MODEL_H_
