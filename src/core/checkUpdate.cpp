#include <src/core/checkUpdate.hpp>
#include <utils/scripts.hpp>
#include <utils/installchoco.hpp>

int checkUpdate() {
  std::cout << "Checking for updates..." << std::endl;
  if (system("choco -v") != 0) {
    installChoco();
  } else {
    system("choco outdated ");
    update(); 
  }
  return 0;
}

