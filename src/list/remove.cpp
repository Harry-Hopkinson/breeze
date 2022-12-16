#include <src/list/remove.hpp>

int removePackage(std::string package) {
  #ifdef _WIN32
    std::ifstream file;
    file.open("file-list.txt");
    if (!file.is_open()) {
      Logger::Error("Error: file-list.txt was not found");
      return 1;
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line)) {
      lines.push_back(line);
    }
    file.close();

    std::string new_file_contents;
    for (const auto& line : lines) {
      if (line.find(package) == std::string::npos) {
        new_file_contents += line + "\n";
      }
    }

    std::ofstream temp_file("file-list.txt.tmp");
    temp_file << new_file_contents;
    temp_file.close();

    std::remove("file-list.txt");
    std::rename("file-list.txt.tmp", "file-list.txt");

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
}}