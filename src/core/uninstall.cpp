#include <src/core/uninstall.hpp>
#include <utils/SystemUninstall.hpp>

int uninstall(std::string argv) {
  #ifdef __linux__
    linuxUninstall(argv);
  #elif _WIN32
    windowsUninstall(argv);
  #elif __APPLE__
    appleUninstall(argv);
  #endif
  return 0;
}
