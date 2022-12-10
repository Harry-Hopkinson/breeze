#include <src/list/remove.hpp>

int remove(std::string package) {
  std::fstream file;
  file.open("file-list.txt");
  if (!file.is_open()) {
    Logger::Error("Error: file-list.txt was not found");
    return 1;
  }

  // scan the file for the package, and then remove it
  std::string line;
  while (std::getline(file, line)) {
    if (line == package) {
      // remove the line
      package = "";
    }
  }

  file.close();
  return 0;
}