#pragma once
#include <string>

#include "types.hh"

namespace smart_house::utils
{
    class Parser
    {
        static constexpr char kDelimeter = ' ';

    private:
        Parser() = delete;
        Parser(const Parser &) = delete;
        Parser &operator=(Parser &) = delete;

        static void Parse(const std::string_view str, DegreesCels &data);
        static void Parse(const std::string_view str, MovementState &data);
        static void Parse(const std::string_view str, LightState &data);

    public:
        static void Parse(const std::string &str, Data &data);
    };
}
