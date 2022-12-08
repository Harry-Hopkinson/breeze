#include <src/core/install.hpp>
#include <utils/SystemInstall.hpp>

int install(std::string argv) {
  #ifdef __linux__
    linux(argv);
  #elif _WIN32
    windowsInstall(argv);
  #elif __APPLE__
    apple(argv);
  #endif

  return 0;
}
