#include <src/list/remove.hpp>

int removePackage(std::string package, int operatingSystem) {
  std::fstream file;
  file.open("file-list.txt");
  if (!file.is_open()) {
    Logger::Error("Error: file-list.txt was not found");
    return 1;
  }

  // scan the file for the package, and then remove it
  std::string line;
  while (std::getline(file, line)) {
    if (line != package) {
      // write the line back to the file if it does not match the package
      file << line << std::endl;
    }
  }

  file.close();
  return 0;
}