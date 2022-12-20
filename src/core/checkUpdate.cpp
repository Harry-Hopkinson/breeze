#include <src/core/checkUpdate.hpp>
#include <utils/scripts.hpp>
#include <utils/installchoco.hpp>

int checkUpdate() {
   std::cout << "Checking for updates..." << std::endl;
   if (system("choco -v") != 0) {
   installChoco();
  }
  system("choco outdated ");
  std::string permission;
  std::cout << "Do you want to update? (y/n)" << std::endl;
  std::cin >> permission;
  if (permission == "y") {
    update();
  } else {
    std::cout << "Permission Denied" << std::endl;
   return 1;   
  }
  return 0;
}

