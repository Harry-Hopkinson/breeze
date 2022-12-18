#include <src/list/remove.hpp>

int removePackage(std::string package) {
  #ifdef _WIN32
  char *username = std::getenv("USERNAME");
  if (username == nullptr) {
    std::cerr << "Error: Could not get username" << "\n";
    return 1;
  }
  // Construct the path to the file using the username
  std::string filePath = "C:\\Users\\" + std::string(username) + "\\file-list.txt";
  std::string tempPath = "C:\\Users\\" + std::string(username) + "\\file-list-temp.txt";
  std::string line;

  std::fstream file(filePath, std::ios::in | std::ios::out);
  std::ofstream tempFile(tempPath);

  while (std::getline(file, line)) {
    if (line.find(package) == std::string::npos) {
      tempFile << line << "\n";
    }
  }

  file.close();
  tempFile.close();

  // delete the original file-list
  // and replace with temporary one
  remove(filePath.c_str());
  rename(tempPath.c_str(), filePath.c_str());

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
