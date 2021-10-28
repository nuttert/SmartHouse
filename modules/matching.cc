#include "matching.hh"
#include "logger.hh"

namespace smart_house
{
  void Matching::PushDevice(DevicePtr &&device)
  {
    devices_.push_back(std::move(device));
  }
  void Matching::Start()
  {
    is_running_ = true;
    while (is_running_)
    {
      auto data = reader_.Read();
      data.time = time_;
      for (const auto &device_ptr : devices_)
      {
        device_ptr->flow_callback(data);
      }
      UpdateTime();
    }
  }
  void Matching::Stop()
  {
    is_running_ = false;
  }

  void Matching::UpdateTime()
  {
    time_.hours = (time_.hours + 1) % 24;
  }
}