#include <utils/System.hpp>

int linux(std::string argv) {
  std::cout << "Installing " << argv << " on Linux" << std::endl;
    if (system(("sudo apt-get install -y " + argv).c_str()) != 0) {
      std::cout << "Error installing " << argv << std::endl;
      return 1;
    } else {
      system(("sudo apt-get install -y " + argv).c_str());
    }
  return 0;
}

int windows(std::string argv) {
  std::cout << "Installing " << argv << " on Windows" << std::endl;
  // check for choco error
  if (system("choco -v") != 0) {
    std::string permission;
    std::cout << "Choco is not installed, do you want to install it? (y/n)" << std::endl;
    std::cin >> permission;
    if (permission == "y") {
      system("powershell -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))\"");
    } else {
      std::cout << "Permission Denied" << std::endl;
      return 1;
    }
    return 1;
  }
  system(("choco install " + argv).c_str());
  return 0;
}

int apple(std::string argv) {
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
  return 0; 
}