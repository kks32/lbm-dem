#ifndef LBMDEM_FLUID_NODE_H_
#define LBMDEM_FLUID_NODE_H_

#include <array>
#include <iostream>
#include <limits>
#include <vector>

namespace lbmdem {
template <unsigned Tdim>
class FluidNode;
}

//! LBM Fluid Node class
//! \brief Base class that stores the information about lbm nodes
//! \details FluidNode class: id_ and coordinates.
//! \tparam Tdim Dimension
template <unsigned Tdim>
class lbmdem::FluidNode {
 public:
  // Constructor with id and coordinates
  //! \param[in] id Node id
  //! \param[in] coord coordinates of the node
  FluidNode(const long long& id, const std::array<long, Tdim>& coord)
      : id_{id} {
    // Check if the dimension is between 2 or 3
    static_assert((Tdim == 2 || Tdim == 3), "Invalid global dimension");
    coordinates_ = coord;
  };

  //! Destructor
  ~FluidNode(){};

  //! Return id of the node
  long long id() const { return id_; }

  //! Assign coordinates
  //! \param[in] coord Assign coord as coordinates of the node
  void coordinates(const std::array<long, Tdim>& coord) {
    coordinates_ = coord;
  }

  //! Return coordinates
  //! \param[out] coordinates_ return coordinates of the node
  std::array<double, Tdim> coordinates() const { return coordinates_; }

  //! Info
  void info() {
    std::cout << "Node id: " << id_ << ", coordinates: ";
    for (const auto& coord : coordinates_) std::cout << coord << ", ";
    std::cout << std::endl;
  }

 private:
  //! Restict Copy constructor
  FluidNode(const FluidNode<Tdim>&);

  //! Restict Assignment operator
  FluidNode& operator=(const FluidNode<Tdim>&);

 protected:
  //! node id
  long long id_;

  //! nodal coordinates
  std::array<long, Tdim> coordinates_;
};

#endif // LBMDEM_FLUID_NODE_H_
