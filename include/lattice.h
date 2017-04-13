#ifndef LBMDEM_LATTICE_H_
#define LBMDEM_LATTICE_H_

#include <algorithm>
#include <array>
#include <limits>

#include "settings.h"

namespace lbmdem {
template <unsigned Tdim, unsigned Tdir>
class Lattice;
}

//! Abstract Lattice base class
//! \brief Base class that stores the information about Lattice model
//! \tparam Tdim Dimension
//! \tparam Tdir Number of discrete velocity directions
template <unsigned Tdim, unsigned Tdir>
class lbmdem::Lattice {
 public:
  //! \brief Constructor
  Lattice();

  //! Return weights
  std::array<lbmdem::Real, Tdir> weights() const { return weights_; }

  //! Return velocities
  std::array<std::array<int, Tdir>, Tdim> velocities() const {
    return velocities_;
  }

 private:
  //! Restict Copy & Assignment constructors
  Lattice(const Lattice&) = delete;
  Lattice& operator=(const Lattice&) = delete;

  //! Weights
  std::array<lbmdem::Real, Tdir> weights_;
  //! Velocities
  std::array<std::array<int, Tdir>, Tdim> velocities_;
};

#include "lattice.tcc"

#endif  // LBMDEM_LATTICE_H_
