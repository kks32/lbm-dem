#ifndef LBMDEM_DAQB_H_
#define LBMDEM_DAQB_H_

#include <algorithm>
#include <array>
#include <limits>

#include "settings.h"

namespace lbmdem {
template <unsigned Tdim, unsigned Tdir>
class DaQb;
}

//! Abstract DaQb base class
//! \brief Base class that stores the information about DaQb model
//! \tparam Tdim Dimension
//! \tparam Tdir Number of discrete velocity directions
template <unsigned Tdim, unsigned Tdir>
class lbmdem::DaQb {
 public:
  //! \brief Constructor
  DaQb();

  //! Return weights
  std::array<lbmdem::Real, Tdir> weights() const { return weights_; }

  //! Return velocities
  std::array<std::array<int, Tdir>, Tdim> velocities() const {
    return velocities_;
  }

 private:
  //! Restict Copy constructor
  DaQb(const DaQb&);

  //! Restict Assignment operator
  DaQb& operator=(const DaQb&);

  //! Weights
  std::array<lbmdem::Real, Tdir> weights_;
  //! Velocities
  std::array<std::array<int, Tdir>, Tdim> velocities_;
};

#include "daqb.tcc"

#endif  // LBMDEM_DAQB_H_
