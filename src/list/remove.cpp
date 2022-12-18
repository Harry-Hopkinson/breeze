#include <src/list/remove.hpp>
#include <stdlib.h>

int removePackage(std::string package) {
  #ifdef _WIN32
  char *username = std::getenv("USERNAME");
  if (username == nullptr) {
    std::cerr << "Error: Could not get username" << "\n";
    return 1;
  }

  std::string filePath = "C:\\Users\\" + std::string(username) + "\\file-list.txt";
  // write the package to the file
  std::ofstream outputFile(filePath, std::ios::app);
  if (!outputFile.is_open()) {
    std::cerr << "Failed to open the file: " << filePath << std::endl;
    return 1;
  }

  // remove the package from the file
  std::ifstream inputFile(filePath);

  std::string line;
  std::string newFile;
  while (std::getline(inputFile, line)) {
    if (line != package) {
      newFile += line + " ";
  }}

  outputFile << newFile;
  outputFile.close();
  inputFile.close();

  return 0;

  #elif __linux__
    std::fstream file;
    file.open("file-list.txt");
    if (!file.is_open()) {
      Logger::Error("Error: file-list.txt was not found");
      return 1;
    }

    // scan the file for the package, and then remove it
    std::string line;
    while (std::getline(file, line)) {
      if (line.find(package)) {
        std::cout << "Found the package: " << package << "\n";
        // remove the package
      }
    }

    file.close();
    return 0;
  #elif __APPLE__
    std::fstream file;
    file.open("file-list.txt");
    if (!file.is_open()) {
      Logger::Error("Error: file-list.txt was not found");
      return 1;
    }

    // scan the file for the package, and then remove it
    std::string line;
    while (std::getline(file, line)) {
      if (line.find(package)) {
        std::cout << "Found the package: " << package << "\n";
        // remove the package
      }
    }

    file.close();
    return 0;
  #endif
  return 0;
}
