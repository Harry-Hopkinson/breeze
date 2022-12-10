#include <src/list/write.hpp>

int write(std::string package) {
  std::fstream file;
  file.open("file-list.txt");
  if (!file.is_open()) {
    Logger::Error("Error: file-list.txt was not found");
    return 1;
  }

  // read the file
  file << package << "\n";
  file.close();
  return 0;
}