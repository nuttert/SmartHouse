#include <string_view>
#include <stdexcept>

#include "logger.hh"
#include "data_parser.hh"

namespace smart_house::utils
{
    void Parser::Parse(const std::string &str, Data &data)
    {
        constexpr auto kTokens = 4;

        std::string_view str_v = str;

        auto begin = 0U;
        auto end = str_v.find(kDelimeter);
        size_t counter = 0;

        for (size_t counter = 0; counter < kTokens; ++counter)
        {
            const auto token = str_v.substr(begin, end - begin);

            begin = end + 1;
            end = str_v.find(kDelimeter, begin);
            if (end == std::string::npos)
            {
                end = str_v.size();
            }
            // clang-format off
            switch (counter)
            {
            case 0: Parse(token, data.temp_outside );break;
            case 1: Parse(token, data.temp_inside );break;
            case 2: Parse(token, data.movement_outside );break;
            case 3: Parse(token, data.light_inside );break;
            default:
                break;
            }
            // clang-format on
        }
    }

    void Parser::Parse(const std::string_view str, DegreesCels &data)
    {
        LogDebug("Parse data: {}", str);
        data = std::stol(str.data());
    }
    void Parser::Parse(const std::string_view str, MovementState &data)
    {
        LogDebug("Parse data: {}", str);
        if (str == "yes")
        {
            data = MovementState::yes;
        }
        else if (str == "no")
        {
            data = MovementState::no;
        }
        else
        {
            throw std::runtime_error("Can't parse movement state.");
        }
    }
    void Parser::Parse(const std::string_view str, LightState &data)
    {
        LogDebug("Parse data: {}", str);
        if (str == "on")
        {
            data = LightState::on;
        }
        else if (str == "off")
        {
            data = LightState::off;
        }
        else
        {
            throw std::runtime_error("Can't parse light state.");
        }
    }
}
