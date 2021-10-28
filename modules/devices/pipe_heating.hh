#pragma once
#include "types.hh"
#include "device_interface.hh"

namespace smart_house
{
  class PipeHeating : public DeviceInterface
  {
  public:
    PipeHeating() : DeviceInterface("PipeHeating"){};

    void flow_callback_impl(const Data &data) override;
  };
}