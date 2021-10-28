#include "pipe_heating.hh"
#include "config.hh"
#include "logger.hh"

namespace smart_house
{
    void PipeHeating::flow_callback_impl(const Data &data)
    {
        if (data.temp_outside > config::kPipeHeatingMaxTemp)
        {
            turn(DeviceState::off);
        }
        else if (data.temp_outside < config::kPipeHeatingMinTemp)
        {
            turn(DeviceState::on);
        }
    }
}