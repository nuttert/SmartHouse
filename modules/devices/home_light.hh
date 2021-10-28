#pragma once
#include "types.hh"
#include "device_interface.hh"

namespace smart_house
{
  class HomeLight : public DeviceInterface
  {
  public:
    HomeLight() : DeviceInterface("HomeLight")
    {
      ResetTemp();
    };

    void flow_callback_impl(const Data &data) override;
    void print() const override;
  private:
    void UpdateTemp(const size_t stage);
    void ResetTemp();

  private:
    DegreesKelv temp_;
  };
}