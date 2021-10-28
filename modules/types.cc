#include "types.hh"

namespace smart_house
{

    bool Time::operator<(const Time &rhs) const
    {
        return hours < rhs.hours || (hours == rhs.hours && minutes < rhs.minutes);
    }
    bool Time::operator>(const Time &rhs) const
    {
        return hours > rhs.hours || (hours == rhs.hours && minutes > rhs.minutes);
    }
    bool Time::operator>=(const Time &rhs) const
    {
        return hours >= rhs.hours || (hours == rhs.hours && minutes >= rhs.minutes);
    }
    bool Time::operator<=(const Time &rhs) const
    {
        return hours <= rhs.hours || (hours == rhs.hours && minutes <= rhs.minutes);
    }

    std::string to_string(const DeviceState state)
    {
        if (state == DeviceState::on)
        {
            return "on";
        }
        else
        {
            return "off";
        }
    }
    std::string to_string(const MovementState state)
    {
        if (state == MovementState::yes)
        {
            return "yes";
        }
        else
        {
            return "no";
        }
    }
}