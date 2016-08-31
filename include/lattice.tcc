// D3Q19 Lattice

//! \brief Constructor with relaxation parameter
//! \param[in] tau_ Relaxation parameter $\tau$
template <>
lbmdem::Lattice<3, 19>::Lattice() {
  //! LBM weights
  const lbmdem::Real w0 = 1. / 3.;
  const lbmdem::Real w1 = 1. / 18.;
  const lbmdem::Real w2 = 1. / 36.;
  weights_ = {{w0, w1, w1, w1, w2, w2, w2, w2, w2, w2, w1, w1, w1, w2, w2, w2,
               w2, w2, w2}};

  //! components of predefined velocity in Q directions
  //! x-direction
  velocities_.at(0) = {0, -1, 0, 0, -1, -1, -1, -1, 0, 0,
                       1, 0,  0, 1, 1,  1,  1,  0,  0};
  //! y-direction
  velocities_.at(1) = {0, 0, -1, 0, -1, 1, 0, 0, -1, -1,
                       0, 1, 0,  1, -1, 0, 0, 1, 1};

  //! z-direction
  velocities_.at(2) = {0, 0, 0, -1, 0, 0, -1, 1, -1, 1,
                       0, 0, 1, 0,  0, 1, -1, 1, -1};
}
