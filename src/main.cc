#include <iostream>
#include <memory>

#include "lattice.h"
#include "factory.h"
#include "lb_node.h"
#include "settings.h"

int main(int argc, char** argv) {
  lbmdem::Lint id = 0;
  const unsigned Dim = 3;
  std::array<lbmdem::Lint, Dim> coord = {{0}};
  auto node = std::make_shared<lbmdem::LBNode<Dim>>(id, coord);
  std::cout << node->isfluid() << '\t';
}
