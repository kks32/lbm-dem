#include <limits>
#include <memory>

#include "catch.hpp"

#include "lattice.h"
#include "settings.h"

//! \brief Check 2D lattice D2Q9 case
TEST_CASE("D2Q9 Lattice weights are checked", "[LBM][Lattice][D2Q9]") {
  const unsigned DIM = 2; // Dimension
  const unsigned NQ = 9; // Number of velocities
  SECTION("D2Q9 lattice weights are checked") {
    const auto d2q9 = lbmdem::Lattice<DIM, NQ>();

    REQUIRE(d2q9.weights.at(0) == Approx(1.0/36.0));
    REQUIRE(d2q9.weights.at(1) == Approx(1.0/9.0));
    REQUIRE(d2q9.weights.at(2) == Approx(1.0/36.0));

    REQUIRE(d2q9.weights.at(3) == Approx(1.0/9.0));
    REQUIRE(d2q9.weights.at(4) == Approx(4.0/9.0));
    REQUIRE(d2q9.weights.at(5) == Approx(1.0/9.0));

    REQUIRE(d2q9.weights.at(6) == Approx(1.0/36.0));
    REQUIRE(d2q9.weights.at(7) == Approx(1.0/9.0));
    REQUIRE(d2q9.weights.at(8) == Approx(1.0/36.0));
  }

  SECTION("D2Q9 lattice weights sum to 1") {
    const auto d2q9 = lbmdem::Lattice<DIM, NQ>();

    lbmdem::Real sum = 0;
    for (int i = 0; i < NQ; ++i)
      sum += d2q9.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D2Q9 lattice weights are zero outside the stencil") {
    const auto d2q9 = lbmdem::Lattice<DIM, NQ>();

    lbmdem::Real sum = 0;
    for (int i = -100; i <= 100; ++i)
      for (int j = -100; j <= 100; ++j)
        sum += d2q9.weight(i,j);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D2Q9 opposite lattice velocities are opposite") {
    const auto d2q9 = lbmdem::Lattice<DIM, NQ>();

    for (int i = 0; i < NQ; ++i) {
      int j = d2q9.opposite(i);
      for (int k = 0; k < DIM; ++k)
        REQUIRE(d2q9.velocities.at(i).at(k) + d2q9.velocities.at(j).at(k) ==
                Approx(0.0));
    }
  }
}

//! \brief Check 3D lattice D3Q19 case
TEST_CASE("D3Q19 Lattice weights are checked", "[LBM][Lattice][D3Q19]") {
  const unsigned DIM = 3; // Dimension
  const unsigned NQ = 19; // Number of velocities
  SECTION("D3Q19 lattice weights sum to 1") {
    const auto d3q19 = lbmdem::Lattice<DIM, NQ>();

    lbmdem::Real sum = 0;
    for (int i = 0; i < NQ; ++i)
      sum += d3q19.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D3Q19 lattice weights are zero outside the stencil") {
    const auto d3q19 = lbmdem::Lattice<DIM, NQ>();

    lbmdem::Real sum = 0;
    for (int i = -100; i <= 100; ++i)
      for (int j = -100; j <= 100; ++j)
        for (int k = -100; k <= 100; ++k)
          sum += d3q19.weight(i,j,k);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D3Q19 opposite lattice velocities are opposite") {
    const auto d3q19 = lbmdem::Lattice<DIM, NQ>();

    for (int i = 0; i < NQ; ++i) {
      int j = d3q19.opposite(i);
      for (int k = 0; k < DIM; ++k)
        REQUIRE(d3q19.velocities.at(i).at(k) + d3q19.velocities.at(j).at(k) ==
                Approx(0.0));
    }
  }
}

//! \brief Check 3D lattice D3Q27 case
TEST_CASE("D3Q27 Lattice weights are checked", "[LBM][Lattice][D3Q27]") {
  const unsigned DIM = 3; // Dimension
  const unsigned NQ = 27; // Number of velocities
  SECTION("D3Q27 lattice weights are checked") {
    const auto d3q27 = lbmdem::Lattice<DIM, NQ>();

    REQUIRE(d3q27.weight( 0, 0, 0) == Approx(8.0/27.0));

    REQUIRE(d3q27.weight( 1, 0, 0) == Approx(2.0/27.0));
    REQUIRE(d3q27.weight( 0, 1, 0) == Approx(2.0/27.0));
    REQUIRE(d3q27.weight( 0, 0, 1) == Approx(2.0/27.0));
    REQUIRE(d3q27.weight(-1, 0, 0) == Approx(2.0/27.0));
    REQUIRE(d3q27.weight( 0,-1, 0) == Approx(2.0/27.0));
    REQUIRE(d3q27.weight( 0, 0,-1) == Approx(2.0/27.0));

    REQUIRE(d3q27.weight( 1, 1, 0) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight( 1, 0, 1) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight( 0, 1, 1) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight(-1, 1, 0) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight(-1, 0, 1) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight( 0,-1, 1) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight( 1,-1, 0) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight( 1, 0,-1) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight( 0, 1,-1) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight(-1,-1, 0) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight(-1, 0,-1) == Approx(1.0/54.0));
    REQUIRE(d3q27.weight( 0,-1,-1) == Approx(1.0/54.0));

    REQUIRE(d3q27.weight( 1, 1, 1) == Approx(1.0/216.0));
    REQUIRE(d3q27.weight( 1, 1, 1) == Approx(1.0/216.0));
    REQUIRE(d3q27.weight( 1, 1, 1) == Approx(1.0/216.0));
    REQUIRE(d3q27.weight(-1,-1,-1) == Approx(1.0/216.0));
    REQUIRE(d3q27.weight(-1,-1,-1) == Approx(1.0/216.0));
    REQUIRE(d3q27.weight(-1,-1,-1) == Approx(1.0/216.0));
  }

  SECTION("D3Q27 lattice weights sum to 1") {
    const auto d3q27 = lbmdem::Lattice<DIM, NQ>();

    lbmdem::Real sum = 0;
    for (int i = 0; i < NQ; ++i)
      sum += d3q27.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D3Q27 lattice weights are zero outside the stencil") {
    const auto d3q27 = lbmdem::Lattice<DIM, NQ>();

    lbmdem::Real sum = 0;
    for (int i = -100; i <= 100; ++i)
      for (int j = -100; j <= 100; ++j)
        for (int k = -100; k <= 100; ++k)
          sum += d3q27.weight(i,j,k);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D3Q27 opposite lattice velocities are opposite") {
    const auto d3q27 = lbmdem::Lattice<DIM, NQ>();

    for (int i = 0; i < NQ; ++i) {
      int j = d3q27.opposite(i);
      for (int k = 0; k < DIM; ++k)
        REQUIRE(d3q27.velocities.at(i).at(k) + d3q27.velocities.at(j).at(k) ==
                Approx(0.0));
    }
  }
}
