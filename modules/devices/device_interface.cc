#include "device_interface.hh"
#include "logger.hh"

namespace smart_house
{
    DeviceInterface::DeviceInterface(const std::string &name) : name{name} {}
    void DeviceInterface::turn(const DeviceState state)
    {
        const auto old_state = state_;
        state_ = state;
        if (state_ != old_state)
        {
            print();
        }
    }
    void DeviceInterface::flow_callback(const Data &data)
    {
        flow_callback_impl(data);
    }
    void DeviceInterface::print() const
    {
        LogInfo("{} turn {}", name, to_string(state_));
    }
}