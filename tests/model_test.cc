// Nodebase test
#include <limits>
#include <memory>

#include "catch.hpp"

#include "model.h"
#include "settings.h"

//! \brief Check 3D model D3Q19 case
TEST_CASE("Model weights are checked", "[LBM][Model]") {
  const lbmdem::Real Tolerance = 1.E-16;

  SECTION("D2Q9 model weights are checked") {
    const auto d2q9 = lbmdem::Model<2, 9>();

    REQUIRE(d2q9.weight( 0, 0) == Approx(4.0/9.0));

    REQUIRE(d2q9.weight( 1, 0) == Approx(1.0/9.0));
    REQUIRE(d2q9.weight( 0, 1) == Approx(1.0/9.0));
    REQUIRE(d2q9.weight(-1, 0) == Approx(1.0/9.0));
    REQUIRE(d2q9.weight( 0,-1) == Approx(1.0/9.0));

    REQUIRE(d2q9.weight( 1, 1) == Approx(1.0/36.0));
    REQUIRE(d2q9.weight( 1,-1) == Approx(1.0/36.0));
    REQUIRE(d2q9.weight(-1, 1) == Approx(1.0/36.0));
    REQUIRE(d2q9.weight(-1,-1) == Approx(1.0/36.0));
  }

  SECTION("D3Q27 model weights are checked") {
    const auto d3q27 = lbmdem::Model<3, 27>();

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
}
