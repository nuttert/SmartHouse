#include "home_light.hh"
#include "config.hh"
#include "logger.hh"

namespace smart_house
{
    void HomeLight::flow_callback_impl(const Data &data)
    {
        const auto time_ok = data.time > config::kHomeLightMinTime &&
                             data.time <= config::kHomeLightMaxTime;
        const auto time_to_reset = data.time >= config::kHomeLightResetTime &&
                                   data.time < config::kHomeLightMinTime;
        LogDebug("Time ok: {}, hours={}, minutes={}, reduce={}",
                 time_ok,
                 data.time.hours, data.time.minutes,
                 config::kHomeLightReduceTemp);

        if (data.light_inside == LightState::on)
        {
            if (time_ok)
            {
                const auto stage = data.time.hours - config::kHomeLightMinTime.hours;
                UpdateTemp(stage);
            }
            else if (time_to_reset)
            {
                ResetTemp();
            }
            print();
        }
    }

    void HomeLight::UpdateTemp(const size_t stage)
    {
        temp_ = config::kHomeLightResetTemp - stage * config::kHomeLightReduceTemp;
    }
    void HomeLight::ResetTemp()
    {
        temp_ = config::kHomeLightResetTemp;
    }

    void HomeLight::print() const
    {
        LogInfo("HomeLight temperature {}", temp_);
    }
}