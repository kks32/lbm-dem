#ifndef LBMDEM_PATCH_H_
#define LBMDEM_PATCH_H_

#include "lb_grid.h"

namespace lbmdem {
template <unsigned Tdim, unsigned Tq>
class Patch;

template <unsigned Tdim, unsigned Tq>
class Patch {
public:
  lbmdem::LB_Grid<Tdim,Tq> lb;
};

} //namespace lbmdem

#endif  // LBMDEM_PATCH_H_
