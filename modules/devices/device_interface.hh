#pragma once
#include <memory>

#include "types.hh"
namespace smart_house
{

    class DeviceInterface
    {
    public:
        DeviceInterface(const std::string &name);
        virtual void turn(const DeviceState state);
        virtual void flow_callback(const Data &data);
        virtual void print() const;

    protected:
        virtual void flow_callback_impl(const Data &data) = 0;

    public:
        const std::string name;

    private:
        DeviceState state_;
    };

    using DevicePtr = std::unique_ptr<DeviceInterface>;
}