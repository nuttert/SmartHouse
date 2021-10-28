#pragma once
#include <cstddef>

#include "types.hh"

namespace smart_house::config
{
    // PipeHeating
    constexpr DegreesCels kPipeHeatingMinTemp = 0;
    constexpr DegreesCels kPipeHeatingMaxTemp = 5;
    // GardenLight
    constexpr Time kGardenLightMinTime{
        .hours = 16,
        .minutes = 0};
    constexpr Time kGardenLightMaxTime{
        .hours = 5,
        .minutes = 0};
    // HomeHeating
    constexpr DegreesCels kHomeHeatingMinTemp = 22;
    constexpr DegreesCels kHomeHeatingMaxTemp = 25;
    // Conditioner
    constexpr DegreesCels kConditionerMinTemp = 25;
    constexpr DegreesCels kConditionerMaxTemp = 30;
    // HomeLight
    constexpr Time kHomeLightMinTime{
        .hours = 16,
        .minutes = 0};
    constexpr Time kHomeLightMaxTime{
        .hours = 20,
        .minutes = 0};
    constexpr Time kHomeLightResetTime{
        .hours = 0,
        .minutes = 0};
    constexpr DegreesKelv kHomeLightReduceTemp = (5000 - 2700) / (20 - 16);
    constexpr DegreesKelv kHomeLightResetTemp = 5000;

    // Logger
    constexpr char kLogsPath[11] = "logs.log";
    constexpr size_t kLoggerFlushSec = 1;
    constexpr char kLoggerPattern[52] =
        "[time %H:%M:%S--%D %z] [type %^%l%$] [thread %t] %v";

} // namespace lib::config
