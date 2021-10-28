#pragma once
#include "types.hh"

namespace smart_house::utils
{
  class Reader
  {
  public:
    Reader() = default;

    Data Read();
  };
}
