//! \brief Weights for D2Q9
template <>
const std::array<lbmdem::Real, 9> lbmdem::Lattice<2, 9>::weights = {
    // clang-format off
  1./36., 1./ 9., 1./36.,
  1./ 9., 4./ 9., 1./ 9.,
  1./36., 1./ 9., 1./36.,
    // clang-format on
};

//! \brief Velocities for D2Q9
template <>
const std::array<std::array<int,2>,9> lbmdem::Lattice<2,9>::velocities = {
  std::array<int,2>
  // clang-format off
  {-1,-1}, { 0,-1}, { 1,-1},
  {-1, 0}, { 0, 0}, { 1, 0},
  {-1, 1}, { 0, 1}, { 1, 1},
  // clang-format on
};

//! \brief Weights for D3Q19
template <>
const std::array<lbmdem::Real, 19> lbmdem::Lattice<3, 19>::weights = {
    // clang-format off
           1./ 36.,
  1./ 36., 1./ 18., 1./ 36.,
           1./ 36.,

  1./ 36., 1./ 18., 1./ 36.,
  1./ 18., 1./  3., 1./ 18.,
  1./ 36., 1./ 18., 1./ 36.,

           1./ 36.,
  1./ 36., 1./ 18., 1./ 36.,
           1./ 36.,
    // clang-format on
};

//! \brief Velocities for D3Q19
template <>
const std::array<std::array<int, 3>, 19> lbmdem::Lattice<3, 19>::velocities = {
    std::array<int, 3>
    // clang-format off
              { 0,-1,-1},
  {-1, 0,-1}, { 0, 0,-1}, { 1, 0,-1},
              { 0, 1,-1},

  {-1,-1, 0}, { 0,-1, 0}, { 1,-1, 0},
  {-1, 0, 0}, { 0, 0, 0}, { 1, 0, 0},
  {-1, 1, 0}, { 0, 1, 0}, { 1, 1, 0},

              { 0,-1, 1},
  {-1, 0, 1}, { 0, 0, 1}, { 1, 0, 1},
              { 0, 1, 1},
    // clang-format on
};

//! \brief Weights for D3Q27
template <>
const std::array<lbmdem::Real, 27> lbmdem::Lattice<3, 27>::weights = {
    // clang-format off
  1./216., 1./ 54., 1./216.,
  1./ 54., 2./ 27., 1./ 54.,
  1./216., 1./ 54., 1./216.,

  1./ 54., 2./ 27., 1./ 54.,
  2./ 27., 8./ 27., 2./ 27.,
  1./ 54., 2./ 27., 1./ 54.,

  1./216., 1./ 54., 1./216.,
  1./ 54., 2./ 27., 1./ 54.,
  1./216., 1./ 54., 1./216.,
    // clang-format on
};

//! \brief Velocities for D3Q27
template <>
const std::array<std::array<int, 3>, 27> lbmdem::Lattice<3, 27>::velocities = {
    std::array<int, 3>
    // clang-format off
  {-1,-1,-1}, { 0,-1,-1}, { 1,-1,-1},
  {-1, 0,-1}, { 0, 0,-1}, { 1, 0,-1},
  {-1, 1,-1}, { 0, 1,-1}, { 1, 1,-1},

  {-1,-1, 0}, { 0,-1, 0}, { 1,-1, 0},
  {-1, 0, 0}, { 0, 0, 0}, { 1, 0, 0},
  {-1, 1, 0}, { 0, 1, 0}, { 1, 1, 0},

  {-1,-1, 1}, { 0,-1, 1}, { 1,-1, 1},
  {-1, 0, 1}, { 0, 0, 1}, { 1, 0, 1},
  {-1, 1, 1}, { 0, 1, 1}, { 1, 1, 1},
    // clang-format on
};
