#include <iostream>
#include <memory>

#include "settings.h"
#include "lb_node.h"

int main(int argc, char** argv) {
  lbmdem::Lint id = 0;
  const unsigned Dim = 3;
  std::array<lbmdem::Lint, Dim> coord = {{0}};

  auto node = std::make_shared<lbmdem::LbNode<Dim>>(id, coord);
}
