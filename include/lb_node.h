#ifndef LBMDEM_LB_NODE_H_
#define LBMDEM_LB_NODE_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>

#include "settings.h"

namespace lbmdem {
template <unsigned Tdim>
class LBNode;
}

//! LBM Node class
//! \brief Base class that stores the information about lbm nodes
//! \details LBNode class: id_ and coordinates.
//! \tparam Tdim Dimension
template <unsigned Tdim>
class lbmdem::LBNode {
 public:
  // Constructor with id and coordinates
  //! \param[in] id Node id
  //! \param[in] coord coordinates of the node
  LBNode(const lbmdem::Lint& id, const std::array<lbmdem::Lint, Tdim>& coord)
      : id_{id} {
    // Check if the dimension is between 2 or 3
    static_assert((Tdim == 2 || Tdim == 3), "Invalid global dimension");
    coordinates_ = coord;
    isfluid_ = true;
    std::fill(force_.begin(), force_.end(),
              std::numeric_limits<lbmdem::Real>::quiet_NaN());
  };

  // Constructor with id, coordinates and state
  //! \param[in] id Node id
  //! \param[in] coord Nodal coordinates
  //! \param[in] state State of the LB node (Solid, Fluid or Gas)
  LBNode(const lbmdem::Lint& id, const std::array<lbmdem::Lint, Tdim>& coord,
         bool isfluid)
      : id_{id}, isfluid_{isfluid} {
    // Check if the dimension is between 2 or 3
    static_assert((Tdim == 2 || Tdim == 3), "Invalid global dimension");
    coordinates_ = coord;
  };

  //! Return id of the node
  lbmdem::Lint id() const { return id_; }

  //! Return coordinates
  //! \param[out] coordinates_ return coordinates of the node
  std::array<lbmdem::Lint, Tdim> coordinates() const { return coordinates_; }

  //! Update fluid / solid state of the node
  void isfluid(const bool status) { isfluid_ = status; }

  //!  (Solid, Fluid, Gas) of the LB node
  bool isfluid() const { return isfluid_; }

  //! Assign force
  void force(const std::array<lbmdem::Real, Tdim>& force) { force_ = force; }

  //! Return force
  std::array<lbmdem::Real, Tdim> force() const { return force_; }

 private:
  //! Restict Copy constructor
  LBNode(const LBNode<Tdim>&);

  //! Restict Assignment operator
  LBNode& operator=(const LBNode<Tdim>&);

 protected:
  //! LB node id
  lbmdem::Lint id_;

  //! LB nodal coordinates
  std::array<lbmdem::Lint, Tdim> coordinates_;

  //! Solid or fluid node
  bool isfluid_;

  //! Force
  std::array<lbmdem::Real, Tdim> force_;
};

#endif  // LBMDEM_LB_NODE_H_
