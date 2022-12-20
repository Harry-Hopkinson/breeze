#include <utils/SystemInstall.hpp>
#include <src/list/write.hpp>
#include <utils/CheckDupInstall.hpp>
#include <utils/installchoco.hpp>

int linuxInstall(std::string argv) {
  if (checkDupInstall(argv) == 1) {
    std::cout << "Package already installed" << std::endl;
    return 1;
  }
  std::cout << "Installing " << argv << " on Linux" << std::endl;
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
  if (system("choco -v") != 0) {
    installChoco(); 
  }
  if (checkDupInstall(argv) == 0) {
    // system(("choco install " + argv).c_str());
    write(argv);
  }
  return 1;
}

int appleInstall(std::string argv) {
  if (checkDupInstall(argv) == 1) {
    std::cout << "Package already installed" << std::endl;
    return 1;
  }
  std::cout << "Installing " << argv << " on Apple" << std::endl;
  if (system(("brew install " + argv).c_str()) != 0) {
    std::cout << "brew install " + argv + " failed" << std::endl;
    std::string permission;
    std::cout << "Do you want to install brew? (y/n)" << std::endl;
    std::cin >> permission;
    if (permission == "y") {
      system("/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)\"");
      system(("brew install " + argv).c_str());
      write(argv);
    } else {
      std::cout << "Permission Denied" << std::endl;
      return 1;
    }
  } else {
    system(("brew install " + argv).c_str());
    write(argv);
  }
  std::cout << "Installing " << argv << " on Mac" << std::endl;
  write(argv);
  return 0;
}
