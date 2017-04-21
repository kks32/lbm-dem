// Nodebase test
#include <limits>

#include "catch.hpp"

#include "lb_node.h"
#include "settings.h"

//! \brief Check LB node class for 3D case
TEST_CASE("LB node is checked for 3D case with id & coordinates",
          "[3D][LBM][lbnode]") {
  const unsigned Dim = 3;
  std::array<lbmdem::Lint, Dim> coords = {{0}};

  //! Check for id = 0
  SECTION("Node id is zero") {
    lbmdem::Lint id = 0;
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
    REQUIRE(node->id() == 0);
  }

  SECTION("Node id is negative") {
    //! Check for negative node id
    lbmdem::Lint id = std::numeric_limits<lbmdem::Lint>::min();
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<lbmdem::Lint>::min());
  }

  SECTION("Node id is positive") {
    //! Check for id is a positive value
    lbmdem::Lint id = std::numeric_limits<lbmdem::Lint>::max();
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<lbmdem::Lint>::max());
  }

  //! Test coordinates function
  SECTION("coordinates function is checked") {
    lbmdem::Lint id = 0;
    //! Check for coordinates being zero
    SECTION("Coordinates are zero") {
      auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
      auto coordinates = node->coordinates();
      for (unsigned i = 0; i < coordinates.size(); ++i)
        REQUIRE(coordinates.at(i) == coords.at(i));
      REQUIRE(coordinates.size() == Dim);
    }

    //! Check for negative value of coordinates
    SECTION("Coordinates are negative values") {
      for (auto &coord : coords)
        coord = std::numeric_limits<lbmdem::Lint>::min();
      auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
      auto coordinates = node->coordinates();
      for (unsigned i = 0; i < coordinates.size(); ++i)
        REQUIRE(coordinates.at(i) == coords.at(i));

      REQUIRE(coordinates.size() == Dim);
    }

    //! Check for positive value of coordinates
    SECTION("Coordinates are positive values") {
      for (auto &coord : coords)
        coord = std::numeric_limits<lbmdem::Lint>::max();
      auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
      auto coordinates = node->coordinates();
      for (unsigned i = 0; i < coordinates.size(); ++i)
        REQUIRE(coordinates.at(i) == coords.at(i));

      REQUIRE(coordinates.size() == Dim);
    }
  }

  //! Test state of lb node
  SECTION("State of LB node is checked") {
    lbmdem::Lint id = 0;
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
    REQUIRE(node->isfluid() == true);

    node->isfluid(false);
    REQUIRE(node->isfluid() == false);
  }

  //! Test state of lb node
  SECTION("Force in LB node is checked") {
    lbmdem::Lint id = 0;
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
    auto force = node->force();
    REQUIRE(force.size() == Dim);
    for (auto fcomponent : force)
      REQUIRE(std::isnan(fcomponent) == true);

    std::array<lbmdem::Real, Dim> force_test = {
        -1. * std::numeric_limits<lbmdem::Real>::max(), 0.,
        std::numeric_limits<lbmdem::Real>::max()};
    node->force(force_test);
    force = node->force();
    REQUIRE(force.size() == force_test.size());
    for (unsigned i = 0; i < force_test.size(); ++i)
      REQUIRE(force.at(i) == force_test.at(i));
  }
}

//! \brief Check LB node class for 2D case
TEST_CASE("LB node is checked for 3D case with id, coordinates and isfluid",
          "[3D][LBM][lbnode]") {
  const unsigned Dim = 3;
  lbmdem::Lint id = 0;
  std::array<lbmdem::Lint, Dim> coords = {{0}};

  //! Test state of lb node
  SECTION("State of LB node is checked for fluid") {
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords, true);
    REQUIRE(node->isfluid() == true);

    node->isfluid(false);
    REQUIRE(node->isfluid() == false);

    //! Check if node id is zero
    SECTION("Node id is zero") { REQUIRE(node->id() == 0); }

    //! Check for coordinates being zero
    SECTION("coordinates function is checked") {
      auto coordinates = node->coordinates();
      for (unsigned i = 0; i < coordinates.size(); ++i)
        REQUIRE(coordinates.at(i) == coords.at(i));
      REQUIRE(coordinates.size() == Dim);
    }
  }

  //! Test state of lb node
  SECTION("State of LB node is checked for solid") {
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords, false);
    REQUIRE(node->isfluid() == false);

    node->isfluid(true);
    REQUIRE(node->isfluid() == true);

    //! Check if node id is zero
    SECTION("Node id is zero") { REQUIRE(node->id() == 0); }

    //! Check for coordinates being zero
    SECTION("coordinates function is checked") {
      auto coordinates = node->coordinates();
      for (unsigned i = 0; i < coordinates.size(); ++i)
        REQUIRE(coordinates.at(i) == coords.at(i));
      REQUIRE(coordinates.size() == Dim);
    }
  }

  //! Test state of lb node
  SECTION("Force in LB node is checked") {
    lbmdem::Lint id = 0;
    auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coords);
    auto force = node->force();
    REQUIRE(force.size() == Dim);
    for (auto fcomponent : force)
      REQUIRE(std::isnan(fcomponent) == true);

    std::array<lbmdem::Real, Dim> force_test = {
        -1. * std::numeric_limits<lbmdem::Real>::max(), 0.,
        std::numeric_limits<lbmdem::Real>::max()};
    node->force(force_test);
    force = node->force();
    REQUIRE(force.size() == force_test.size());
    for (unsigned i = 0; i < force_test.size(); ++i)
      REQUIRE(force.at(i) == force_test.at(i));
  }
}
