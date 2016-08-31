// Nodebase test
#include <limits>
#include <memory>

#include "catch.hpp"

#include "daqb.h"
#include "settings.h"

//! \brief Check 3D model D3Q19 case
TEST_CASE("D3Q19 model is checked", "[D3Q19][3D][lbm]") {
  const unsigned Dim = 3;
  const unsigned Dir = 19;
  const lbmdem::Real Tolerance = 1.E-16;

  auto d3q19 = std::make_shared<lbmdem::DaQb<Dim, Dir>>();

  //! Check weights
  SECTION("Weights are checked") {
    auto weights = d3q19->weights();
    // Check size
    REQUIRE(weights.size() == Dir);
    // Check weights
    REQUIRE(weights.at(0) == Approx(12. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(1) == Approx(2. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(2) == Approx(2. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(3) == Approx(2. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(4) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(5) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(6) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(7) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(8) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(9) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(10) == Approx(2. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(11) == Approx(2. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(12) == Approx(2. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(13) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(14) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(15) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(16) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(17) == Approx(1. / 36.).epsilon(Tolerance));
    REQUIRE(weights.at(18) == Approx(1. / 36.).epsilon(Tolerance));
  }

  //! Check predefined velocities
  SECTION("Velocities are checked") {
    auto velocities = d3q19->velocities();
    // Check dimension size
    REQUIRE(velocities.size() == Dim);
    // Check size for each component of dimension
    for (auto velocity_dir : velocities)
      REQUIRE(velocity_dir.size() == Dir);

    // Dir - 0
    REQUIRE(velocities.at(0).at(0) == 0);
    REQUIRE(velocities.at(1).at(0) == 0);
    REQUIRE(velocities.at(2).at(0) == 0);

    // Dir - 1
    REQUIRE(velocities.at(0).at(1) == -1);
    REQUIRE(velocities.at(1).at(1) == 0);
    REQUIRE(velocities.at(2).at(1) == 0);

    // Dir - 2
    REQUIRE(velocities.at(0).at(2) == 0);
    REQUIRE(velocities.at(1).at(2) == -1);
    REQUIRE(velocities.at(2).at(2) == 0);

    // Dir - 3
    REQUIRE(velocities.at(0).at(3) == 0);
    REQUIRE(velocities.at(1).at(3) == 0);
    REQUIRE(velocities.at(2).at(3) == -1);

    // Dir - 4
    REQUIRE(velocities.at(0).at(4) == -1);
    REQUIRE(velocities.at(1).at(4) == -1);
    REQUIRE(velocities.at(2).at(4) == 0);

    // Dir - 5
    REQUIRE(velocities.at(0).at(5) == -1);
    REQUIRE(velocities.at(1).at(5) == 1);
    REQUIRE(velocities.at(2).at(5) == 0);

    // Dir - 6
    REQUIRE(velocities.at(0).at(6) == -1);
    REQUIRE(velocities.at(1).at(6) == 0);
    REQUIRE(velocities.at(2).at(6) == -1);

    // Dir - 7
    REQUIRE(velocities.at(0).at(7) == -1);
    REQUIRE(velocities.at(1).at(7) == 0);
    REQUIRE(velocities.at(2).at(7) == 1);

    // Dir - 8
    REQUIRE(velocities.at(0).at(8) == 0);
    REQUIRE(velocities.at(1).at(8) == -1);
    REQUIRE(velocities.at(2).at(8) == -1);

    // Dir - 9
    REQUIRE(velocities.at(0).at(9) == 0);
    REQUIRE(velocities.at(1).at(9) == -1);
    REQUIRE(velocities.at(2).at(9) == 1);

    // Dir - 10
    REQUIRE(velocities.at(0).at(10) == 1);
    REQUIRE(velocities.at(1).at(10) == 0);
    REQUIRE(velocities.at(2).at(10) == 0);

    // Dir - 11
    REQUIRE(velocities.at(0).at(11) == 0);
    REQUIRE(velocities.at(1).at(11) == 1);
    REQUIRE(velocities.at(2).at(11) == 0);

    // Dir - 12
    REQUIRE(velocities.at(0).at(12) == 0);
    REQUIRE(velocities.at(1).at(12) == 0);
    REQUIRE(velocities.at(2).at(12) == 1);

    // Dir - 13
    REQUIRE(velocities.at(0).at(13) == 1);
    REQUIRE(velocities.at(1).at(13) == 1);
    REQUIRE(velocities.at(2).at(13) == 0);

    // Dir - 14
    REQUIRE(velocities.at(0).at(14) == 1);
    REQUIRE(velocities.at(1).at(14) == -1);
    REQUIRE(velocities.at(2).at(14) == 0);

    // Dir - 15
    REQUIRE(velocities.at(0).at(15) == 1);
    REQUIRE(velocities.at(1).at(15) == 0);
    REQUIRE(velocities.at(2).at(15) == 1);

    // Dir - 16
    REQUIRE(velocities.at(0).at(16) == 1);
    REQUIRE(velocities.at(1).at(16) == 0);
    REQUIRE(velocities.at(2).at(16) == -1);

    // Dir - 17
    REQUIRE(velocities.at(0).at(17) == 0);
    REQUIRE(velocities.at(1).at(17) == 1);
    REQUIRE(velocities.at(2).at(17) == 1);

    // Dir - 18
    REQUIRE(velocities.at(0).at(18) == 0);
    REQUIRE(velocities.at(1).at(18) == 1);
    REQUIRE(velocities.at(2).at(18) == -1);
  }
}
