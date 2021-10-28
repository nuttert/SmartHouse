#pragma once
#include <vector>
#include <memory>

#include "devices/devices_list.hh"
#include "reader.hh"

namespace smart_house
{
  class Matching
  {

  public:
    Matching() = default;

    void PushDevice(DevicePtr &&device);
    void Start();
    void Stop();

  private:
    void UpdateTime();

  private:
    Devices devices_;
    utils::Reader reader_;
    bool is_running_{false};
    Time time_{
        .hours = 0,
        .minutes = 0,
    };
  };
}
