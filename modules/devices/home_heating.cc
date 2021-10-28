#include "home_heating.hh"
#include "config.hh"
#include "logger.hh"

namespace smart_house
{
    void HomeHeating::flow_callback_impl(const Data &data)
    {
        if (data.temp_inside < config::kHomeHeatingMinTemp)
        {
            turn(DeviceState::on);
        }
        else if (data.temp_inside >= config::kHomeHeatingMaxTemp)
        {
            turn(DeviceState::off);
        }
    }
}