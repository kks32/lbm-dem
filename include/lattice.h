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

template <>
const std::array<lbmdem::Real,9> lbmdem::Lattice<2,9>::weights = {
  1./36., 1./ 9., 1./36.,
  1./ 9., 4./ 9., 1./ 9.,
  1./36., 1./ 9., 1./36.,
};
template <>
const std::array<std::array<int,2>,9> lbmdem::Lattice<2,9>::velocities = { std::array<int,2>
  {-1, 1}, { 0, 1}, { 1, 1},
  {-1, 0}, { 0, 0}, { 1, 0},
  {-1,-1}, { 0,-1}, { 1,-1},
};

template <>
const std::array<lbmdem::Real,27> lbmdem::Lattice<3,27>::weights = {
  1./216., 1./ 54., 1./216.,
  1./ 54., 2./ 27., 1./ 54.,
  1./216., 1./ 54., 1./216.,

  1./ 54., 2./ 27., 1./ 54.,
  2./ 27., 8./ 27., 2./ 27.,
  1./ 54., 2./ 27., 1./ 54.,

  1./216., 1./ 54., 1./216.,
  1./ 54., 2./ 27., 1./ 54.,
  1./216., 1./ 54., 1./216.,
};
template <>
const std::array<std::array<int,3>,27> lbmdem::Lattice<3,27>::velocities = { std::array<int,3>
  {-1, 1, 1}, { 0, 1, 1}, { 1, 1, 1},
  {-1, 0, 1}, { 0, 0, 1}, { 1, 0, 1},
  {-1,-1, 1}, { 0,-1, 1}, { 1,-1, 1},

  {-1, 1, 0}, { 0, 1, 0}, { 1, 1, 0},
  {-1, 0, 0}, { 0, 0, 0}, { 1, 0, 0},
  {-1,-1, 0}, { 0,-1, 0}, { 1,-1, 0},

  {-1, 1,-1}, { 0, 1,-1}, { 1, 1,-1},
  {-1, 0,-1}, { 0, 0,-1}, { 1, 0,-1},
  {-1,-1,-1}, { 0,-1,-1}, { 1,-1,-1},
};

#endif //LBMDEM_LATTICE_H_
