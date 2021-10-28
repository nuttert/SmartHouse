#include "garden_light.hh"
#include "config.hh"
#include "logger.hh"

namespace smart_house
{
    void GardenLight::flow_callback_impl(const Data &data)
    {
        const auto time_ok = data.time > config::kGardenLightMinTime ||
                             data.time < config::kGardenLightMaxTime;
        LogDebug("Movement: {}, Time ok: {}, hours={}, minutes={}", 
                    data.movement_outside, time_ok, 
                    data.time.hours, data.time.minutes);
        if (data.movement_outside == MovementState::yes && time_ok)
        {
            turn(DeviceState::on);
        }
        else
        {
            turn(DeviceState::off);
        }
    }
}