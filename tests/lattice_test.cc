#include <limits>
#include <memory>

#include "catch.hpp"

#include "lattice.h"
#include "settings.h"

//! \brief Check 2D lattice D2Q9 case
TEST_CASE("2D Lattice weights are checked", "[LBM][Lattice][D2Q9]") {
  const lbmdem::Real Tolerance = 1.E-16;

  SECTION("D2Q9 lattice weights are checked") {
    const auto d2q9 = lbmdem::Lattice<2, 9>();

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

  SECTION("D2Q9 lattice weights sum to 1") {
    const auto d2q9 = lbmdem::Lattice<2, 9>();

    lbmdem::Real sum = 0;
    for (int i = -1; i <= 1; ++i)
      for (int j = -1; j <= 1; ++j)
        sum += d2q9.weight(i,j);
    REQUIRE(sum == Approx(1.0));

    sum = 0;
    for (int i = 0; i < 9; ++i)
      sum += d2q9.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D2Q9 lattice weights are zero outside the stencil") {
    const auto d2q9 = lbmdem::Lattice<2, 9>();

    lbmdem::Real sum = 0;
    for (int i = -100; i <= 100; ++i)
      for (int j = -100; j <= 100; ++j)
        sum += d2q9.weight(i,j);
    REQUIRE(sum == Approx(1.0));
  }
}

TEST_CASE("D3Q27 Lattice weights are checked", "[LBM][Lattice][D3Q19]") {
  SECTION("D3Q27 lattice weights sum to 1") {
    const auto d3q19 = lbmdem::Lattice<3, 19>();

    lbmdem::Real sum = 0;
    for (int i = -1; i <= 1; ++i)
      for (int j = -1; j <= 1; ++j)
        for (int k = -1; k <= 1; ++k)
          sum += d3q19.weight(i,j,k);
    REQUIRE(sum == Approx(1.0));

    sum = 0;
    for (int i = 0; i < 19; ++i)
      sum += d3q19.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D3Q19 lattice weights are zero outside the stencil") {
    const auto d3q19 = lbmdem::Lattice<3, 19>();

    lbmdem::Real sum = 0;
    for (int i = -100; i <= 100; ++i)
      for (int j = -100; j <= 100; ++j)
        for (int k = -100; k <= 100; ++k)
          sum += d3q19.weight(i,j,k);
    REQUIRE(sum == Approx(1.0));
  }
}

//! \brief Check 3D lattice D3Q27 case
TEST_CASE("DQ27 Lattice weights are checked", "[LBM][Lattice][D3Q27]") {
  const lbmdem::Real Tolerance = 1.E-16;

  SECTION("D3Q27 lattice weights are checked") {
    const auto d3q27 = lbmdem::Lattice<3, 27>();

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
    const auto d3q27 = lbmdem::Lattice<3, 27>();

    lbmdem::Real sum = 0;
    for (int i = -1; i <= 1; ++i)
      for (int j = -1; j <= 1; ++j)
        for (int k = -1; k <= 1; ++k)
          sum += d3q27.weight(i,j,k);
    REQUIRE(sum == Approx(1.0));

    sum = 0;
    for (int i = 0; i < 27; ++i)
      sum += d3q27.weights.at(i);
    REQUIRE(sum == Approx(1.0));
  }

  SECTION("D3Q27 lattice weights are zero outside the stencil") {
    const auto d3q27 = lbmdem::Lattice<3, 27>();

    lbmdem::Real sum = 0;
    for (int i = -100; i <= 100; ++i)
      for (int j = -100; j <= 100; ++j)
        for (int k = -100; k <= 100; ++k)
          sum += d3q27.weight(i,j,k);
    REQUIRE(sum == Approx(1.0));
  }
}
