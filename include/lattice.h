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

template <unsigned Tdim, unsigned Tq>
class lbmdem::Lattice {
  public:

  static const std::array<lbmdem::Real,Tq> weights;
  static const std::array<std::array<int,Tdim>,Tq> velocities;

  template <typename... Ix>
  lbmdem::Real weight(Ix... i) const {
    std::array<int,Tdim> ix{i...};
    for (int j = 0; j < Tq; ++j)
      if (ix == velocities.at(j))
        return weights.at(j);
    return 0.0;
  }
};

#endif //LBMDEM_LATTICE_H_
