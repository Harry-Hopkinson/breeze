#include <src/core/update.hpp>

int update() {
  #ifdef __linux__
    system("sudo apt update && sudo apt upgrade");
  #elif _WIN32
    system("choco upgrade all");
  #elif __APPLE__
    system("brew upgrade");
  #endif
  return 0;
}

