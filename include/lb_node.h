#ifndef LBMDEM_LBM_NODE_H_
#define LBMDEM_LBM_NODE_H_

#include <array>
#include <iostream>
#include <limits>
#include <vector>

#include "settings.h"

namespace lbmdem {
template <unsigned Tdim>
class LbNode;
}

//! LBM Node class
//! \brief Base class that stores the information about lbm nodes
//! \details LbNode class: id_ and coordinates.
//! \tparam Tdim Dimension
template <unsigned Tdim>
class lbmdem::LbNode {
 public:
  // Constructor with id and coordinates
  //! \param[in] id Node id
  //! \param[in] coord coordinates of the node
  LbNode(const lbmdem::Lint& id, const std::array<lbmdem::Lint, Tdim>& coord)
      : id_{id} {
    // Check if the dimension is between 2 or 3
    static_assert((Tdim == 2 || Tdim == 3), "Invalid global dimension");
    coordinates_ = coord;
  };

  //! Destructor
  ~LbNode(){};

  //! Return id of the node
  lbmdem::Lint id() const { return id_; }

  //! Assign coordinates
  //! \param[in] coord Assign coord as coordinates of the node
  void coordinates(const std::array<lbmdem::Lint, Tdim>& coord) {
    coordinates_ = coord;
  }

  //! Return coordinates
  //! \param[out] coordinates_ return coordinates of the node
  std::array<lbmdem::Lint, Tdim> coordinates() const { return coordinates_; }

 private:
  //! Restict Copy constructor
  LbNode(const LbNode<Tdim>&);

  //! Restict Assignment operator
  LbNode& operator=(const LbNode<Tdim>&);

 protected:
  //! node id
  lbmdem::Lint id_;

  //! nodal coordinates
  std::array<lbmdem::Lint, Tdim> coordinates_;
};

#endif // LBMDEM_LBM_NODE_H_
