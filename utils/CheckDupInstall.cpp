#include <utils/CheckDupInstall.hpp>
#include <utils/Logger.hpp>

int checkDupInstall(std::string package) {
  #ifdef _WIN32
  char *username = std::getenv("USERNAME");
  if (username == nullptr) {
    std::cerr << "Error: Could not get username" << "\n";
    return 1;
  }
  // Construct the path to the file using the username
  std::string filePath = "C:\\Users\\" + std::string(username) + "\\file-list.txt";
  std::string line;

  // Open the file
  std::fstream file(filePath, std::ios::in);
  if (!file) {
    std::cerr << "Error: Could not open file" << "\n";
    return 1;
  }

  while (std::getline(file, line)) {
    if (line == package) {
      std::cerr << "Error: " << package << " already installed" << "\n";
      return 1;
    }
  }
  return 0;
  #elif __linux__
  char *username = std::getenv("USERNAME");
  if (username == nullptr) {
    std::cerr << "Error: Could not get username" << "\n";
    return 1;
  }
  // Construct the path to the file using the username
  std::string filePath = "/home/" + std::string(std::getenv("USER")) + "/file-list.txt";
  std::string line;

  // Open the file
  std::fstream file(filePath, std::ios::in);
  if (!file) {
    std::cerr << "Error: Could not open file" << "\n";
    return 1;
  }

  while (std::getline(file, line)) {
    if (line == package) {
      std::cerr << "Error: " << package << " already installed" << "\n";
      return 1;

    }
  }
  return 0;
  #elif __APPLE__
  char *username = std::getenv("USERNAME");
  if (username == nullptr) {
    std::cerr << "Error: Could not get username" << "\n";
    return 1;
  }
  // Construct the path to the file using the username
  std::string filePath = "/Users/" + std::string(std::getenv("USER")) + "/file-list.txt";
  std::string line;

  // Open the file
  std::fstream file(filePath, std::ios::in);
  if (!file) {
    std::cerr << "Error: Could not open file" << "\n";
    return 1;
  }

  while (std::getline(file, line)) {
    if (line == package) {
      std::cerr << "Error: " << package << " already installed" << "\n";
      return 1;
    }
  }
  return 0;
  #endif
}


