#ifndef LBMDEM_SETTINGS_H_
#define LBMDEM_SETTINGS_H_

#include <type_traits>
#include <typeinfo>

namespace lbmdem {
  //! Define single or double precision
  using Real = double;
  //! Switch between 64bit and 32bit integers
  using Lint = long long;
}

#endif  //LBMDEM_SETTINGS_H_
