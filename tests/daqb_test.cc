// Nodebase test
#include <limits>
#include <memory>

#include "catch.hpp"

#include "daqb.h"
#include "settings.h"

//! \brief Check 3D model D3Q19 case
TEST_CASE("D3Q19 model is checked",
          "[D3Q19][3D][lbm]") {
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
}
