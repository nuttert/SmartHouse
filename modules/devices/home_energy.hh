#pragma once
#include "types.hh"
#include "device_interface.hh"

namespace smart_house
{
  class HomeEnergy : public DeviceInterface
  {
  public:
    HomeEnergy() : DeviceInterface("HomeEnergy"){};

    void flow_callback_impl(const Data &data) override;
  };
}