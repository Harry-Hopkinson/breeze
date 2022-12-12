#include <src/core/duplicateInstall.hpp>

int duplicateInstall(std::string package) {
  std::string line;
  std::fstream file;
  file.open("file-list.txt", std::ios::out | std::ios::app);
  while (std::getline(file, line)) {
    if (line == package) {
      Logger::Error("Error: Package is already installed");
      return 1;
    }
  }
  file.close();
  return 0;
}