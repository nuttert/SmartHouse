#pragma once
#include "conditioner.hh"
#include "garden_light.hh"
#include "home_energy.hh"
#include "home_heating.hh"
#include "home_light.hh"
#include "home_sockets.hh"
#include "home_heating.hh"
#include "pipe_heating.hh"

#include <vector>
#include <memory>
namespace smart_house
{
    using Devices = std::vector<DevicePtr>;

    Devices CreateDevices();
}