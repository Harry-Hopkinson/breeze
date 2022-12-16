#include <src/list/write.hpp>
#include <src/core/duplicateInstall.hpp>

int write(std::string package) {
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
    outputFile << package << "\n";
    outputFile.close();
  #elif __linux__
    std::string filePath = "/home/" + std::string(std::getenv("USER")) + "/file-list.txt";
    // write the package to the file
    std::ofstream outputFile(filePath, std::ios::app);
    if (!outputFile.is_open()) {
      std::cerr << "Failed to open the file: " << filePath << std::endl;
      return 1;
    }
    outputFile << package << "\n";
    outputFile.close();
  #elif __APPLE__
    std::string filePath = "/Users/" + std::string(std::getenv("USER")) + "/file-list.txt";
    // write the package to the file
    std::ofstream outputFile(filePath, std::ios::app);
    if (!outputFile.is_open()) {
      std::cerr << "Failed to open the file: " << filePath << std::endl;
      return 1;
    }
    outputFile << package << "\n";
    outputFile.close();
  #endif
  return 0;
}

