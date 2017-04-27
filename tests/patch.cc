#include "catch.hpp"

#include "patch.h"

TEST_CASE("patch object (2D)", "[LBM][Patch][2D]") {
  unsigned const Dim = 2;
  unsigned const Q = 9;
  lbmdem::Patch<Dim,Q> p;

  SECTION("lb.f has expected dims") {
    for (int i = 0; i < Dim; ++i)
      REQUIRE(p.lb.f.dimension(i) == 8);
    REQUIRE(p.lb.f.dimension(Dim) == Q);
  }

  SECTION("lb.force has expected dims") {
    for (int i = 0; i < Dim; ++i)
      REQUIRE(p.lb.force.dimension(i) == 8);
    REQUIRE(p.lb.force.dimension(Dim) == Dim);
  }

  SECTION("lb.f can be accessed") {
    for (int x = 0; x < 8; ++x)
      for (int y = 0; y < 8; ++y)
        for (int i = 0; i < Q; ++i)
          REQUIRE_NOTHROW(p.lb.f(x,y,i));
  }
}

TEST_CASE("patch object (3D)", "[LBM][Patch][3D]") {
  unsigned const Dim = 3;
  unsigned const Q = 27;
  lbmdem::Patch<Dim,Q> p;

  SECTION("lb.f has expected dims") {
    for (int i = 0; i < Dim; ++i)
      REQUIRE(p.lb.f.dimension(i) == 8);
    REQUIRE(p.lb.f.dimension(Dim) == Q);
  }

  SECTION("lb.force has expected dims") {
    for (int i = 0; i < Dim; ++i)
      REQUIRE(p.lb.force.dimension(i) == 8);
    REQUIRE(p.lb.force.dimension(Dim) == Dim);
  }

  SECTION("lb.f can be accessed") {
    for (int x = 0; x < 8; ++x)
      for (int y = 0; y < 8; ++y)
        for (int z = 0; z < 8; ++z)
          for (int i = 0; i < Q; ++i)
            REQUIRE_NOTHROW(p.lb.f(x,y,z,i));
  }
}
