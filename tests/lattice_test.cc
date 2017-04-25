#include <limits>
#include <memory>

#include "catch.hpp"

#include "lattice.h"
#include "settings.h"

//! \brief Check 2D lattice D2Q9 case
TEST_CASE("D2Q9 Lattice parameters are checked", "[LBM][Lattice][D2Q9]") {
  const unsigned DIM = 2; // Dimension
  const unsigned NQ = 9;  // Number of velocities
  const auto d2q9 = lbmdem::Lattice<DIM, NQ>();

  SECTION("D2Q9 lattice weights are checked") {
    REQUIRE(d2q9.weights.at(0) == Approx(1.0 / 36.0));
    REQUIRE(d2q9.weights.at(1) == Approx(1.0 / 9.0));
    REQUIRE(d2q9.weights.at(2) == Approx(1.0 / 36.0));

    REQUIRE(d2q9.weights.at(3) == Approx(1.0 / 9.0));
    REQUIRE(d2q9.weights.at(4) == Approx(4.0 / 9.0));
    REQUIRE(d2q9.weights.at(5) == Approx(1.0 / 9.0));

    REQUIRE(d2q9.weights.at(6) == Approx(1.0 / 36.0));
    REQUIRE(d2q9.weights.at(7) == Approx(1.0 / 9.0));
    REQUIRE(d2q9.weights.at(8) == Approx(1.0 / 36.0));
  }

  SECTION("D2Q9 lattice weights sum to 1") {
    lbmdem::Real sum = 0;
    for (unsigned i = 0; i < NQ; ++i)
      sum += d2q9.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D2Q9 lattice velocities are checked") {
    // Velocity in Direction 0
    REQUIRE(d2q9.velocities.at(0).at(0) == -1);
    REQUIRE(d2q9.velocities.at(1).at(0) == 0);
    REQUIRE(d2q9.velocities.at(2).at(0) == 1);

    REQUIRE(d2q9.velocities.at(3).at(0) == -1);
    REQUIRE(d2q9.velocities.at(4).at(0) == 0);
    REQUIRE(d2q9.velocities.at(5).at(0) == 1);

    REQUIRE(d2q9.velocities.at(6).at(0) == -1);
    REQUIRE(d2q9.velocities.at(7).at(0) == 0);
    REQUIRE(d2q9.velocities.at(8).at(0) == 1);

    // Velocity in Direction 1
    REQUIRE(d2q9.velocities.at(0).at(1) == -1);
    REQUIRE(d2q9.velocities.at(1).at(1) == -1);
    REQUIRE(d2q9.velocities.at(2).at(1) == -1);

    REQUIRE(d2q9.velocities.at(3).at(1) == 0);
    REQUIRE(d2q9.velocities.at(4).at(1) == 0);
    REQUIRE(d2q9.velocities.at(5).at(1) == 0);

    REQUIRE(d2q9.velocities.at(6).at(1) == 1);
    REQUIRE(d2q9.velocities.at(7).at(1) == 1);
    REQUIRE(d2q9.velocities.at(8).at(1) == 1);
  }

  SECTION("D2Q9 lattice velocities sum to zero") {
    std::array<lbmdem::Real, DIM> sum{0};
    for (unsigned i = 0; i < NQ; ++i)
      for (unsigned j = 0; j < DIM; ++j)
        sum.at(j) += d2q9.velocities.at(i).at(j);

    for (unsigned j = 0; j < DIM; ++j)
      REQUIRE(sum.at(j) == Approx(0.0));
  }

  SECTION("D2Q9 opposite lattice velocities are equal and opposite") {
    for (unsigned i = 0; i < NQ; ++i) {
      auto j = d2q9.opposite(i);
      for (unsigned k = 0; k < DIM; ++k)
        REQUIRE(d2q9.velocities.at(i).at(k) + d2q9.velocities.at(j).at(k) ==
                Approx(0.0));
    }
  }
}

//! \brief Check 3D lattice D3Q19 case
TEST_CASE("D3Q19 Lattice parameters are checked", "[LBM][Lattice][D3Q19]") {
  const unsigned DIM = 3; // Dimension
  const unsigned NQ = 19; // Number of velocities
  const auto d3q19 = lbmdem::Lattice<DIM, NQ>();

  SECTION("D3Q19 lattice weights are checked") {
    REQUIRE(d3q19.weights.at(0) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(1) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(2) == Approx(1.0 / 18.0));
    REQUIRE(d3q19.weights.at(3) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(4) == Approx(1.0 / 36.0));

    REQUIRE(d3q19.weights.at(5) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(6) == Approx(1.0 / 18.0));
    REQUIRE(d3q19.weights.at(7) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(8) == Approx(1.0 / 18.0));
    REQUIRE(d3q19.weights.at(9) == Approx(1.0 / 3.0));
    REQUIRE(d3q19.weights.at(10) == Approx(1.0 / 18.0));
    REQUIRE(d3q19.weights.at(11) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(12) == Approx(1.0 / 18.0));
    REQUIRE(d3q19.weights.at(13) == Approx(1.0 / 36.0));

    REQUIRE(d3q19.weights.at(14) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(15) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(16) == Approx(1.0 / 18.0));
    REQUIRE(d3q19.weights.at(17) == Approx(1.0 / 36.0));
    REQUIRE(d3q19.weights.at(18) == Approx(1.0 / 36.0));
  }

  SECTION("D3Q19 lattice weights sum to 1") {
    lbmdem::Real sum = 0;
    for (unsigned i = 0; i < NQ; ++i)
      sum += d3q19.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D2Q9 lattice velocities are checked") {
    // Velocity in direction 0
    REQUIRE(d3q19.velocities.at(0).at(0) == 0);
    REQUIRE(d3q19.velocities.at(1).at(0) == -1);
    REQUIRE(d3q19.velocities.at(2).at(0) == 0);
    REQUIRE(d3q19.velocities.at(3).at(0) == 1);
    REQUIRE(d3q19.velocities.at(4).at(0) == 0);

    REQUIRE(d3q19.velocities.at(5).at(0) == -1);
    REQUIRE(d3q19.velocities.at(6).at(0) == 0);
    REQUIRE(d3q19.velocities.at(7).at(0) == 1);
    REQUIRE(d3q19.velocities.at(8).at(0) == -1);
    REQUIRE(d3q19.velocities.at(9).at(0) == 0);
    REQUIRE(d3q19.velocities.at(10).at(0) == 1);
    REQUIRE(d3q19.velocities.at(11).at(0) == -1);
    REQUIRE(d3q19.velocities.at(12).at(0) == 0);
    REQUIRE(d3q19.velocities.at(13).at(0) == 1);

    REQUIRE(d3q19.velocities.at(14).at(0) == 0);
    REQUIRE(d3q19.velocities.at(15).at(0) == -1);
    REQUIRE(d3q19.velocities.at(16).at(0) == 0);
    REQUIRE(d3q19.velocities.at(17).at(0) == 1);
    REQUIRE(d3q19.velocities.at(18).at(0) == 0);

    // Velocity in direction 1
    REQUIRE(d3q19.velocities.at(0).at(1) == -1);
    REQUIRE(d3q19.velocities.at(1).at(1) == 0);
    REQUIRE(d3q19.velocities.at(2).at(1) == 0);
    REQUIRE(d3q19.velocities.at(3).at(1) == 0);
    REQUIRE(d3q19.velocities.at(4).at(1) == 1);

    REQUIRE(d3q19.velocities.at(5).at(1) == -1);
    REQUIRE(d3q19.velocities.at(6).at(1) == -1);
    REQUIRE(d3q19.velocities.at(7).at(1) == -1);
    REQUIRE(d3q19.velocities.at(8).at(1) == 0);
    REQUIRE(d3q19.velocities.at(9).at(1) == 0);
    REQUIRE(d3q19.velocities.at(10).at(1) == 0);
    REQUIRE(d3q19.velocities.at(11).at(1) == 1);
    REQUIRE(d3q19.velocities.at(12).at(1) == 1);
    REQUIRE(d3q19.velocities.at(13).at(1) == 1);

    REQUIRE(d3q19.velocities.at(14).at(1) == -1);
    REQUIRE(d3q19.velocities.at(15).at(1) == 0);
    REQUIRE(d3q19.velocities.at(16).at(1) == 0);
    REQUIRE(d3q19.velocities.at(17).at(1) == 0);
    REQUIRE(d3q19.velocities.at(18).at(1) == 1);

    // Velocity in direction 2
    REQUIRE(d3q19.velocities.at(0).at(2) == -1);
    REQUIRE(d3q19.velocities.at(1).at(2) == -1);
    REQUIRE(d3q19.velocities.at(2).at(2) == -1);
    REQUIRE(d3q19.velocities.at(3).at(2) == -1);
    REQUIRE(d3q19.velocities.at(4).at(2) == -1);

    REQUIRE(d3q19.velocities.at(5).at(2) == 0);
    REQUIRE(d3q19.velocities.at(6).at(2) == 0);
    REQUIRE(d3q19.velocities.at(7).at(2) == 0);
    REQUIRE(d3q19.velocities.at(8).at(2) == 0);
    REQUIRE(d3q19.velocities.at(9).at(2) == 0);
    REQUIRE(d3q19.velocities.at(10).at(2) == 0);
    REQUIRE(d3q19.velocities.at(11).at(2) == 0);
    REQUIRE(d3q19.velocities.at(12).at(2) == 0);
    REQUIRE(d3q19.velocities.at(13).at(2) == 0);

    REQUIRE(d3q19.velocities.at(14).at(2) == 1);
    REQUIRE(d3q19.velocities.at(15).at(2) == 1);
    REQUIRE(d3q19.velocities.at(16).at(2) == 1);
    REQUIRE(d3q19.velocities.at(17).at(2) == 1);
    REQUIRE(d3q19.velocities.at(18).at(2) == 1);
  }

  SECTION("D3Q19 opposite lattice velocities are equal and opposite") {
    for (unsigned i = 0; i < NQ; ++i) {
      auto j = d3q19.opposite(i);
      for (unsigned k = 0; k < DIM; ++k)
        REQUIRE(d3q19.velocities.at(i).at(k) + d3q19.velocities.at(j).at(k) ==
                Approx(0.0));
    }
  }
}

//! \brief Check 3D lattice D3Q27 case
TEST_CASE("D3Q27 Lattice parameters are checked", "[LBM][Lattice][D3Q27]") {
  const unsigned DIM = 3; // Dimension
  const unsigned NQ = 27; // Number of velocities
  const auto d3q27 = lbmdem::Lattice<DIM, NQ>();

  SECTION("D3Q27 lattice weights are checked") {
    // Top
    REQUIRE(d3q27.weights.at(0) == Approx(1.0 / 216.0));
    REQUIRE(d3q27.weights.at(1) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(2) == Approx(1.0 / 216.0));
    REQUIRE(d3q27.weights.at(3) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(4) == Approx(2.0 / 27.0));
    REQUIRE(d3q27.weights.at(5) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(6) == Approx(1.0 / 216.0));
    REQUIRE(d3q27.weights.at(7) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(8) == Approx(1.0 / 216.0));
    // Middle
    REQUIRE(d3q27.weights.at(9) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(10) == Approx(2.0 / 27.0));
    REQUIRE(d3q27.weights.at(11) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(12) == Approx(2.0 / 27.0));
    REQUIRE(d3q27.weights.at(13) == Approx(8.0 / 27.0));
    REQUIRE(d3q27.weights.at(14) == Approx(2.0 / 27.0));
    REQUIRE(d3q27.weights.at(15) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(16) == Approx(2.0 / 27.0));
    REQUIRE(d3q27.weights.at(17) == Approx(1.0 / 54.0));
    // Bottom
    REQUIRE(d3q27.weights.at(18) == Approx(1.0 / 216.0));
    REQUIRE(d3q27.weights.at(19) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(20) == Approx(1.0 / 216.0));
    REQUIRE(d3q27.weights.at(21) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(22) == Approx(2.0 / 27.0));
    REQUIRE(d3q27.weights.at(23) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(24) == Approx(1.0 / 216.0));
    REQUIRE(d3q27.weights.at(25) == Approx(1.0 / 54.0));
    REQUIRE(d3q27.weights.at(26) == Approx(1.0 / 216.0));
  }

  SECTION("D3Q27 lattice weights sum to 1") {
    lbmdem::Real sum = 0;
    for (unsigned i = 0; i < NQ; ++i)
      sum += d3q27.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D3Q27 lattice veolocities are checked") {
    // Velocity in direction 0
    // Top
    REQUIRE(d3q27.velocities.at(0).at(0) == -1);
    REQUIRE(d3q27.velocities.at(1).at(0) == 0);
    REQUIRE(d3q27.velocities.at(2).at(0) == 1);
    REQUIRE(d3q27.velocities.at(3).at(0) == -1);
    REQUIRE(d3q27.velocities.at(4).at(0) == 0);
    REQUIRE(d3q27.velocities.at(5).at(0) == 1);
    REQUIRE(d3q27.velocities.at(6).at(0) == -1);
    REQUIRE(d3q27.velocities.at(7).at(0) == 0);
    REQUIRE(d3q27.velocities.at(8).at(0) == 1);
    // Middle
    REQUIRE(d3q27.velocities.at(9).at(0) == -1);
    REQUIRE(d3q27.velocities.at(10).at(0) == 0);
    REQUIRE(d3q27.velocities.at(11).at(0) == 1);
    REQUIRE(d3q27.velocities.at(12).at(0) == -1);
    REQUIRE(d3q27.velocities.at(13).at(0) == 0);
    REQUIRE(d3q27.velocities.at(14).at(0) == 1);
    REQUIRE(d3q27.velocities.at(15).at(0) == -1);
    REQUIRE(d3q27.velocities.at(16).at(0) == 0);
    REQUIRE(d3q27.velocities.at(17).at(0) == 1);
    // Bottom
    REQUIRE(d3q27.velocities.at(18).at(0) == -1);
    REQUIRE(d3q27.velocities.at(19).at(0) == 0);
    REQUIRE(d3q27.velocities.at(20).at(0) == 1);
    REQUIRE(d3q27.velocities.at(21).at(0) == -1);
    REQUIRE(d3q27.velocities.at(22).at(0) == 0);
    REQUIRE(d3q27.velocities.at(23).at(0) == 1);
    REQUIRE(d3q27.velocities.at(24).at(0) == -1);
    REQUIRE(d3q27.velocities.at(25).at(0) == 0);
    REQUIRE(d3q27.velocities.at(26).at(0) == 1);

    // Velocity in direction 1
    // Top
    REQUIRE(d3q27.velocities.at(0).at(1) == -1);
    REQUIRE(d3q27.velocities.at(1).at(1) == -1);
    REQUIRE(d3q27.velocities.at(2).at(1) == -1);
    REQUIRE(d3q27.velocities.at(3).at(1) == 0);
    REQUIRE(d3q27.velocities.at(4).at(1) == 0);
    REQUIRE(d3q27.velocities.at(5).at(1) == 0);
    REQUIRE(d3q27.velocities.at(6).at(1) == 1);
    REQUIRE(d3q27.velocities.at(7).at(1) == 1);
    REQUIRE(d3q27.velocities.at(8).at(1) == 1);
    // Middle
    REQUIRE(d3q27.velocities.at(9).at(1) == -1);
    REQUIRE(d3q27.velocities.at(10).at(1) == -1);
    REQUIRE(d3q27.velocities.at(11).at(1) == -1);
    REQUIRE(d3q27.velocities.at(12).at(1) == 0);
    REQUIRE(d3q27.velocities.at(13).at(1) == 0);
    REQUIRE(d3q27.velocities.at(14).at(1) == 0);
    REQUIRE(d3q27.velocities.at(15).at(1) == 1);
    REQUIRE(d3q27.velocities.at(16).at(1) == 1);
    REQUIRE(d3q27.velocities.at(17).at(1) == 1);
    // Bottom
    REQUIRE(d3q27.velocities.at(18).at(1) == -1);
    REQUIRE(d3q27.velocities.at(19).at(1) == -1);
    REQUIRE(d3q27.velocities.at(20).at(1) == -1);
    REQUIRE(d3q27.velocities.at(21).at(1) == 0);
    REQUIRE(d3q27.velocities.at(22).at(1) == 0);
    REQUIRE(d3q27.velocities.at(23).at(1) == 0);
    REQUIRE(d3q27.velocities.at(24).at(1) == 1);
    REQUIRE(d3q27.velocities.at(25).at(1) == 1);
    REQUIRE(d3q27.velocities.at(26).at(1) == 1);

    // Velocity in direction 2
    // Top
    REQUIRE(d3q27.velocities.at(0).at(2) == -1);
    REQUIRE(d3q27.velocities.at(1).at(2) == -1);
    REQUIRE(d3q27.velocities.at(2).at(2) == -1);
    REQUIRE(d3q27.velocities.at(3).at(2) == -1);
    REQUIRE(d3q27.velocities.at(4).at(2) == -1);
    REQUIRE(d3q27.velocities.at(5).at(2) == -1);
    REQUIRE(d3q27.velocities.at(6).at(2) == -1);
    REQUIRE(d3q27.velocities.at(7).at(2) == -1);
    REQUIRE(d3q27.velocities.at(8).at(2) == -1);
    // Middle
    REQUIRE(d3q27.velocities.at(9).at(2) == 0);
    REQUIRE(d3q27.velocities.at(10).at(2) == 0);
    REQUIRE(d3q27.velocities.at(11).at(2) == 0);
    REQUIRE(d3q27.velocities.at(12).at(2) == 0);
    REQUIRE(d3q27.velocities.at(13).at(2) == 0);
    REQUIRE(d3q27.velocities.at(14).at(2) == 0);
    REQUIRE(d3q27.velocities.at(15).at(2) == 0);
    REQUIRE(d3q27.velocities.at(16).at(2) == 0);
    REQUIRE(d3q27.velocities.at(17).at(2) == 0);
    // Bottom
    REQUIRE(d3q27.velocities.at(18).at(2) == 1);
    REQUIRE(d3q27.velocities.at(19).at(2) == 1);
    REQUIRE(d3q27.velocities.at(20).at(2) == 1);
    REQUIRE(d3q27.velocities.at(21).at(2) == 1);
    REQUIRE(d3q27.velocities.at(22).at(2) == 1);
    REQUIRE(d3q27.velocities.at(23).at(2) == 1);
    REQUIRE(d3q27.velocities.at(24).at(2) == 1);
    REQUIRE(d3q27.velocities.at(25).at(2) == 1);
    REQUIRE(d3q27.velocities.at(26).at(2) == 1);
  }

  SECTION("D3Q27 opposite lattice velocities are opposite") {
    for (unsigned i = 0; i < NQ; ++i) {
      auto j = d3q27.opposite(i);
      for (unsigned k = 0; k < DIM; ++k)
        REQUIRE(d3q27.velocities.at(i).at(k) + d3q27.velocities.at(j).at(k) ==
                Approx(0.0));
    }
  }
}
