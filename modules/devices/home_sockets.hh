#pragma once
#include "types.hh"
#include "device_interface.hh"

namespace smart_house
{
  class HomeSockets : public DeviceInterface
  {
  public:
    HomeSockets() : DeviceInterface("HomeSockets"){};

    void flow_callback_impl(const Data &data) override;
  };
}