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

  if (!file) {
    // create the file if it doesn't exist
    std::cerr << "Error: Could not open file-list.txt" << "\n";
    std::cout << "Creating file-list.txt" << "\n";
    std::ofstream outputFile(filePath, std::ios::out);
    outputFile.close();
    return 1;
  }

  
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
  char *username = std::getenv("USERNAME");
  if (username == nullptr) {
    std::cerr << "Error: Could not get username" << "\n";
    return 1;
  }
  // Construct the path to the file using the username
  std::string filePath = "/home/" + std::string(username) + "/file-list.txt";
  std::string tempPath = "/home/" + std::string(username) + "/file-list-temp.txt";
  std::string line;

  std::fstream file(filePath, std::ios::in | std::ios::out);
  std::ofstream tempFile(tempPath);

  if (!file) {
    // create the file if it doesn't exist
    std::cerr << "Error: Could not open file-list.txt" << "\n";
    std::cout << "Creating file-list.txt" << "\n";
    std::ofstream outputFile(filePath, std::ios::out);
    outputFile.close();
    return 1;
  }

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


  #elif __APPLE__
  char *username = std::getenv("USERNAME");
  if (username == nullptr) {
    std::cerr << "Error: Could not get username" << "\n";
    return 1;
  }
  // Construct the path to the file using the username
  std::string filePath = "/Users/" + std::string(username) + "/file-list.txt";
  std::string tempPath = "/Users/" + std::string(username) + "/file-list-temp.txt";
  std::string line;

  std::fstream file(filePath, std::ios::in | std::ios::out);
  std::ofstream tempFile(tempPath);

  if (!file) {
    // create the file if it doesn't exist
    std::cerr << "Error: Could not open file-list.txt" << "\n";
    std::cout << "Creating file-list.txt" << "\n";
    std::ofstream outputFile(filePath, std::ios::out);
    outputFile.close();
    return 1;
  }

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
  #endif
  return 0;
}
