#include "conditioner.hh"
#include "config.hh"

namespace smart_house
{
    void Conditioner::flow_callback_impl(const Data &data)
    {
        if (data.temp_inside >= config::kConditionerMaxTemp)
        {
            turn(DeviceState::on);
        }
        else if (data.temp_inside <= config::kConditionerMinTemp)
        {
            turn(DeviceState::off);
        }
    }
}