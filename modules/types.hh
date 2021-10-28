#pragma once
#include <chrono>
#include <iostream>

namespace smart_house
{
    using DegreesCels = long int;
    using DegreesKelv = size_t;

    struct Time
    {
        size_t hours;
        size_t minutes;

        bool operator<(const Time &rhs) const;
        bool operator>(const Time &rhs) const;
        bool operator>=(const Time &rhs) const;
        bool operator<=(const Time &rhs) const;
    };

    enum class DeviceState
    {
        off,
        on,
    };
    enum class MovementState
    {
        no,
        yes,
    };
    enum class LightState
    {
        off,
        on,
    };

    struct Data
    {
        Time time;
        DegreesCels temp_inside;
        DegreesCels temp_outside;
        MovementState movement_outside;
        LightState light_inside;
    };

    std::string to_string(const DeviceState state);
}