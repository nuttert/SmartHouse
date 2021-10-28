#include "devices_list.hh"

namespace smart_house
{

    Devices CreateDevices()
    {
        Devices devices;
        devices.push_back(std::make_unique<PipeHeating>());
        devices.push_back(std::make_unique<GardenLight>());
        devices.push_back(std::make_unique<HomeHeating>());
        devices.push_back(std::make_unique<Conditioner>());
        devices.push_back(std::make_unique<HomeLight>());
        return devices;
    }
}