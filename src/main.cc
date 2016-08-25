#include "fluid_node.h"

#include <iostream>
#include <memory>

int main(int argc, char** argv) {
  long long id = 0;
  const unsigned Dim = 3;
  std::array<long, Dim> coord = {{0}};

  auto node = std::make_shared<lbmdem::FluidNode<Dim>>(id, coord);
  node->info();
}
