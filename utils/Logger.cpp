#include <utils/Logger.hpp>

#include <iostream>

namespace Logger {
  std::ostream &Error(std::string message)
  {
    #ifdef _WIN32
        return std::cout << message << "\n";
    #else
        return std::cout << "\033[1;31m";
    #endif
    #ifndef _WIN32
        return std::cout << "\033[0m" << message << "\n";
    #endif
  }
}
