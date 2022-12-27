#include <utils/installChoco.hpp>

int installChoco() {
  std::string permission;
  std::cout << "Choco is not installed, do you want to install it? (y/n)" << std::endl;
  std::cin >> permission;
  if (permission == "y") {
    system("powershell -Command \"iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))\"");
  } else {
    std::cout << "Permission Denied" << std::endl;
    return 1;
  }
  return 0;
}
