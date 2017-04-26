#include "catch.hpp"

#include "patch.h"

TEST_CASE("patch object (2D)", "[LBM][Patch][2D]") {
  unsigned const Dim = 2;
  unsigned const Q = 9;
  lbmdem::Patch<Dim,Q> p;

  SECTION("lb.f has expected dims") {
    REQUIRE(p.lb.f.dimension(0) == 64);
    REQUIRE(p.lb.f.dimension(1) == 64);
    REQUIRE(p.lb.f.dimension(2) == Q);
  }

  SECTION("lb.force has expected dims") {
    REQUIRE(p.lb.force.dimension(0) == 64);
    REQUIRE(p.lb.force.dimension(1) == 64);
    REQUIRE(p.lb.force.dimension(2) == Dim);
  }

  SECTION("lb.f can be accessed") {
    for (int i = 0; i < Q; ++i)
      REQUIRE_NOTHROW(p.lb.f(0,0,i));
  }
}

TEST_CASE("patch object (3D)", "[LBM][Patch][3D]") {
  unsigned const Dim = 3;
  unsigned const Q = 27;
  lbmdem::Patch<Dim,Q> p;

  SECTION("lb.f has expected dims") {
    REQUIRE(p.lb.f.dimension(0) == 64);
    REQUIRE(p.lb.f.dimension(1) == 64);
    REQUIRE(p.lb.f.dimension(2) == 64);
    REQUIRE(p.lb.f.dimension(3) == Q);
  }

  SECTION("lb.force has expected dims") {
    REQUIRE(p.lb.force.dimension(0) == 64);
    REQUIRE(p.lb.force.dimension(1) == 64);
    REQUIRE(p.lb.force.dimension(2) == 64);
    REQUIRE(p.lb.force.dimension(3) == Dim);
  }

  SECTION("lb.f can be accessed") {
    for (int i = 0; i < Q; ++i)
      REQUIRE_NOTHROW(p.lb.f(0,0,0,i));
  }
}
