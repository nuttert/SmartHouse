#pragma once
#include "types.hh"
#include "device_interface.hh"

namespace smart_house
{
  class GardenLight : public DeviceInterface
  {
  public:
    GardenLight() : DeviceInterface("GardenLight"){};

    void flow_callback_impl(const Data &data) override;
  };
}