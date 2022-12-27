#include <utils/SystemInstall.hpp>
#include <src/list/write.hpp>
#include <utils/CheckDupInstall.hpp>
#include <utils/installChoco.hpp>
#include <utils/installBrew.hpp>

int linuxInstall(std::string argv) {
  std::cout << "Installing " << argv << " on Linux" << std::endl;
  if (checkDupInstall(argv) == 1) {
    std::cerr << "Package already installed" << std::endl;
    return 1;
  }
  if (system(("sudo apt-get install -y " + argv).c_str()) != 0) {
    std::cout << "get-install failed, trying pacman " << std::endl;
    if (system(("sudo pacman -S " + argv).c_str()) == 0) {
      return 0;
    } else {
      std::cout << "sudo pacman -S " + argv + " failed" << std::endl;
      return 1;
    }
  } else {
    system(("sudo apt-get install -y " + argv).c_str());
    write(argv);
  }
  write(argv);
  return 0;
}

int windowsInstall(std::string argv) {
  std::cout << "Installing " << argv << " on Windows" << std::endl;
  if (checkDupInstall(argv) == 1) {
    std::cerr << "Package already installed" << std::endl;
    return 1;
  }
  if (system("choco -v") != 0) {
    installChoco();
    return 1;
  }
  system(("choco install " + argv).c_str());
  write(argv);
  return 0;
}

int appleInstall(std::string argv) {
  std::cout << "Installing " << argv << " on Apple" << std::endl;
  if (checkDupInstall(argv) == 1) {
    std::cerr << "Package already installed" << std::endl;
    return 1;
  }
  if (system(("brew install " + argv).c_str()) != 0) {
    installBrew();
    return 1;
  }
  system(("brew install " + argv).c_str());
  write(argv);
  return 0;
}
