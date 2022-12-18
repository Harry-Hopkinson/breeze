#include <utils/SystemInstall.hpp>
#include <src/list/write.hpp>
#include <utils/CheckDupInstall.hpp>

int linuxInstall(std::string argv) {
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
  return 0;
}

int windowsInstall(std::string argv) {
  // std::cout << "Installing " << argv << " on Windows" << std::endl;
  // check for choco error
  // if (system("choco -v") != 0) {
  //  std::string permission;
  //  std::cout << "Choco is not installed, do you want to install it? (y/n)" << std::endl;
  //  std::cin >> permission;
  //  if (permission == "y") {
  //    system("powershell -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))\"");
  //  } else {
  //    std::cout << "Permission Denied" << std::endl;
  //   return 1;
  //  }
  //}
  // system(("choco install " + argv).c_str());
  if (checkDupInstall(argv) == 0) {
    write(argv);
  }
  return 1;
}

int appleInstall(std::string argv) {
  std::cout << "Installing " << argv << " on Mac" << std::endl;
  // check if brew error
  if (system("brew -v") != 0) {
    std::string permission;
    std::cout << "Brew is not installed, do you want to install it? (y/n)" << std::endl;
    std::cin >> permission;
    if (permission == "y") {
      system("/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\"");
    } else {
      std::cout << "Permission Denied" << std::endl;
      return 1;
    }
    return 1;
  }
  system(("brew install " + argv).c_str());
  write(argv);
  return 0; 
}
