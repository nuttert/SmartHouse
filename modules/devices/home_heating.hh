#pragma once
#include "types.hh"
#include "device_interface.hh"

namespace smart_house
{
    class HomeHeating : public DeviceInterface
    {
    public:
        HomeHeating() : DeviceInterface("HomeHeating"){};

        void flow_callback_impl(const Data &data) override;
    };
}