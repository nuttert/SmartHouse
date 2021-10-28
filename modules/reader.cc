#include <string>
#include <iostream>

#include "logger.hh"
#include "reader.hh"
#include "data_parser.hh"

namespace smart_house::utils
{
  Data Reader::Read()
  {
    std::string buffer;
    std::getline(std::cin, buffer);
    LogDebug("New line={}", buffer);
    Data result;
    Parser::Parse(buffer, result);
    return result;
  }
}
