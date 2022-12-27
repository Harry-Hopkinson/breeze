#include <stdlib.h>
#include <utils/installBrew.hpp>

int installBrew() {
  std::string permission;
  std::cout << "Brew is not installed, do you want to install it? (y/n)" << std::endl;
  std::cin >> permission;
  if (permission == "y") {
    system("/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)\"");
  } else {
    std::cout << "Permission Denied" << std::endl;
    return 1;
  }
  return 0;
}
