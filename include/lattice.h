#ifndef LBMDEM_LATTICE_H_
#define LBMDEM_LATTICE_H_

#include <array>

#include "settings.h"

namespace lbmdem {
template <unsigned Tdim, unsigned Tq>
class Lattice;
}

//! Abstract Lattice base class
//! \brief Base class that stores the information about Lattice
//! \tparam Tdim Dimension
//! \tparam Tq Number of discrete velocity directions
template <unsigned Tdim, unsigned Tq>
class lbmdem::Lattice {
 public:
  //! Index of opposite node in a stencil
  int opposite(int i) const { return Tq - i - 1; }

  //! Lattice weights
  static const std::array<lbmdem::Real, Tq> weights;
  //! Velocities
  static const std::array<std::array<int, Tdim>, Tq> velocities;
};

// Declaration of a static members
// D2Q9
template <>
const std::array<lbmdem::Real, 9> lbmdem::Lattice<2, 9>::weights;
template <>
const std::array<std::array<int, 2>, 9> lbmdem::Lattice<2, 9>::velocities;

// D3Q19
template <>
const std::array<lbmdem::Real, 19> lbmdem::Lattice<3, 19>::weights;
template <>
const std::array<std::array<int, 3>, 19> lbmdem::Lattice<3, 19>::velocities;

// D3Q27
template <>
const std::array<lbmdem::Real, 27> lbmdem::Lattice<3, 27>::weights;
template <>
const std::array<std::array<int, 3>, 27> lbmdem::Lattice<3, 27>::velocities;

#endif  // LBMDEM_LATTICE_H_
