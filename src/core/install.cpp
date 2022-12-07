#include <src/core/install.hpp>
#include <utils/System.hpp>

int install(std::string argv) {
  #ifdef __linux__
    linux(argv);
  #elif _WIN32
    windows(argv);
  #elif __APPLE__
    apple(argv);
  #endif

  return 0;
}
