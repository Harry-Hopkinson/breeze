#include <utils/SystemUninstall.hpp>
#include <utils/installchoco.hpp>

int linuxUninstall(std::string argv) {
  std::cout << "Uninstalling " << argv << " on Linux" << std::endl;
    if (system(("sudo apt-get remove -y " + argv).c_str()) != 0) {
      std::cout << "get-remove failed, trying pacman " << std::endl;
      if (system(("sudo pacman -R " + argv).c_str()) == 0) {
        return 0;
      } else {
        std::cout << "sudo pacman -R " + argv + " failed" << std::endl;
        return 1;
      }
    } else {
      system(("sudo apt-get remove -y " + argv).c_str());
    }
  removePackage(argv.c_str());
  return 0;
}

int windowsUninstall(std::string argv) {
  std::cout << "Unistalling " << argv << " on Windows" << std::endl;
  if (system("choco -v") != 0) {
   installChoco();
  }
  system(("choco uninstall " + argv).c_str());
  removePackage(argv.c_str());
  return 0;
}

int appleUninstall(std::string argv) {
  std::cout << "Uninstalling " << argv << " on Mac" << std::endl;
  if (system("brew -v") != 0) {
    std::cout << "Brew is not installed, please install it first" << std::endl;
    return 1;
  }
  system(("brew uninstall " + argv).c_str());
  removePackage(argv.c_str());
  return 0; 
}
