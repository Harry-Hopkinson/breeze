#include <utils/Logger.hpp>

#include <iostream>

namespace Logger {
  std::ostream &Error(std::string message)
  {
    return std::cerr << "Error: " << message << std::endl;
  }
}
