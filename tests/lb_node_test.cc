// Nodebase test
#include <limits>

#include "catch.hpp"

#include "lb_node.h"
#include "settings.h"

//! \brief Check LB node class for 2D case
TEST_CASE("LB node is checked for 2D case", "[lbnode][2D]") {
  const unsigned Dim = 2;
  std::array<lbmdem::Lint, Dim> coords = {{0}};

  //! Check for id = 0
  SECTION("Node id is zero") {
    lbmdem::Lint id = 0;
    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);
    REQUIRE(node->id() == 0);
  }

  SECTION("Node id is negative") {
    //! Check for negative node id
    lbmdem::Lint id = std::numeric_limits<lbmdem::Lint>::min();
    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<lbmdem::Lint>::min());
  }

  SECTION("Node id is positive") {
    //! Check for id is a positive value
    lbmdem::Lint id = std::numeric_limits<lbmdem::Lint>::max();
    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<lbmdem::Lint>::max());
  }

  //! Test coordinates function
  SECTION("coordinates function is checked") {
    lbmdem::Lint id = 0;

    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);

    //! Check for coordinates being zero
    auto coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == coords.at(i));
    REQUIRE(coordinates.size() == Dim);

    //! Check for negative value of coordinates
    for (auto &coord : coords)
      coord = -1. * std::numeric_limits<lbmdem::Lint>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == coords.at(i));

    REQUIRE(coordinates.size() == Dim);

    //! Check for positive value of coordinates
    for (auto &coord : coords)
      coord = std::numeric_limits<lbmdem::Lint>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == coords.at(i));

    REQUIRE(coordinates.size() == Dim);
  }
}

//! \brief Check LB node class for 3D case
TEST_CASE("LB node is checked for 3D case", "[lbnode][3D]") {
  const unsigned Dim = 3;
  std::array<lbmdem::Lint, Dim> coords = {{0}};

  //! Check for id = 0
  SECTION("Node id is zero") {
    lbmdem::Lint id = 0;
    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);
    REQUIRE(node->id() == 0);
  }

  SECTION("Node id is negative") {
    //! Check for negative node id
    lbmdem::Lint id = std::numeric_limits<lbmdem::Lint>::min();
    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<lbmdem::Lint>::min());
  }

  SECTION("Node id is positive") {
    //! Check for id is a positive value
    lbmdem::Lint id = std::numeric_limits<lbmdem::Lint>::max();
    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<lbmdem::Lint>::max());
  }

  //! Test coordinates function
  SECTION("coordinates function is checked") {
    lbmdem::Lint id = 0;

    auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coords);

    //! Check for coordinates being zero
    auto coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == coords.at(i));

    REQUIRE(coordinates.size() == Dim);

    //! Check for negative value of coordinates
    for (auto& coord : coords)
      coord = -1. * std::numeric_limits<lbmdem::Lint>::max();

    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == coords.at(i));

    REQUIRE(coordinates.size() == Dim);

    //! Check for positive value of coordinates
    for (auto& coord : coords) coord = std::numeric_limits<lbmdem::Lint>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == coords.at(i));

    REQUIRE(coordinates.size() == Dim);
  }
}
