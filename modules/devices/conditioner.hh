#pragma once
#include "types.hh"
#include "device_interface.hh"

namespace smart_house
{
    class Conditioner : public DeviceInterface
    {
    public:
        Conditioner() : DeviceInterface("Conditioner"){};

        void flow_callback_impl(const Data &data) override;
    };
}
