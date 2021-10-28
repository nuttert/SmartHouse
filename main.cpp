#include <iostream>
#include <vector>

#include <iostream>

#include "matching.hh"
#include "devices/devices_list.hh"
#include "logger.hh"

int main()
{
    smart_house::Matching matching;
    auto devices = smart_house::CreateDevices();
    for (auto &device_ptr : devices)
    {
        matching.PushDevice(std::move(device_ptr));
    }
    matching.Start();
    return 0;
}