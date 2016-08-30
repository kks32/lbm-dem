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
  //! \brief Constructor with relaxation parameter
  DaQb(const lbmdem::Real& tau);

  //! Return velocities
  std::array<lbmdem::Real, Tdir> velocities() const { return velocities_; }

  //! Return weights
  std::array<std::array<int, Tdir>, Tdim> weights() const { return weights_; }

 private:
  //! Restict Copy constructor
  DaQb(const DaQb&);

  //! Restict Assignment operator
  DaQb& operator=(const DaQb&);

  //! Relaxation parameter - Tau
  lbmdem::Real tau_;
  //! Weights
  std::array<lbmdem::Real, Tdir> weights_;
  //! Velocities
  std::array<std::array<int, Tdir>, Tdim> velocities_;
};

#include "daqb.tcc"

#endif  // LBMDEM_DAQB_H_
