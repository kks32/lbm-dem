#include <iostream>
#include <memory>

#include "lattice.h"
#include "factory.h"
#include "settings.h"
#include "patch.h"

int main(int argc, char** argv) {
  const unsigned Dim = 3;
  auto patch = lbmdem::Patch<3,27>();
}
