#include <src/core/install.hpp>
#include <utils/SystemInstall.hpp>

int install(std::string argv) {
  #ifdef __linux__
    linuxInstall(argv);
  #elif _WIN32
    windowsInstall(argv);
  #elif __APPLE__
    appleInstall(argv);
  #endif
  return 0;
}
