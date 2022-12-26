#include <src/list/list.hpp>

int list() {
  #ifdef _WIN32
    char *username = std::getenv("USERNAME");
    if (username == nullptr) {
      std::cerr << "Error: Could not get username" << "\n";
      return 1;
    }
    // Construct the path to the file using the username
    std::string filePath = "C:\\Users\\" + std::string(username) + "\\file-list.txt";

    // print everything in the file
    std::ifstream readFile;
    readFile.open(filePath);

    if (!readFile) {
      // create the file if it doesn't exist
      std::cerr << "Error: Could not open file-list.txt" << "\n";
      std::cout << "Creating file-list.txt" << "\n";
      std::ofstream outputFile(filePath, std::ios::out);
      outputFile.close();
      return 1;
    }

    std::string line;

    for (std::string line; std::getline(readFile, line);) {
      if (line == "") {
        std::cout << "You have no packages installed" << "\n";
        return 1;
      }
      std::cout << line << std::endl;
    }

    readFile.clear();
  
  #elif __linux__
    char* username = std::getenv("USER");
    if (username == nullptr) {
      std::cerr << "Error: Could not get username" << "\n";
      return 1;
    } else {
      std::cout << username << "\n";
    }
    // Construct the path to the file using the username
    std::string filePath = "/home/" + std::string(username) + "/file-list.txt";

    std::ifstream readFile;
    readFile.open(filePath);

    if (!readFile) {
      // create the file if it doesn't exist
      std::ofstream outputFile(filePath, std::ios::out);
      outputFile.close();
      return 1;
    }

    std::string line;

    for (std::string line; std::getline(readFile, line);) {
      if (line == "") {
        std::cout << "You have no packages installed" << "\n";
        return 1;
      }
      std::cout << line << std::endl;
    }

    readFile.clear();
    
  #elif __APPLE__
    char* username = std::getenv("USER");
    if (username == nullptr) {
      std::cerr << "Error: Could not get username" << "\n";
      return 1;
    } else {
      std::cout << username << "\n";
    }
    // Construct the path to the file using the username
    std::string filePath = "/Users/" + std::string(username) + "/file-list.txt";

    std::ifstream readFile;
    readFile.open(filePath);

    if (!readFile) {
      // create the file if it doesn't exist
      std::ofstream outputFile(filePath, std::ios::out);
      outputFile.close();
      return 1;
    }

    std::string line;

    for (std::string line; std::getline(readFile, line);) {
      if (line == "") {
        std::cout << "You have no packages installed" << "\n";
        return 1;
      }
      std::cout << line << std::endl;
    }

    readFile.clear();
  #endif
  return 0;
}
