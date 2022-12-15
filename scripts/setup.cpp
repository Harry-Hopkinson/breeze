#include <scripts/setup.hpp>

int main() {
  #ifdef _WIN32
    // Create an output filestream object
    char *username = std::getenv("USERNAME");
    if (username == nullptr) {
      std::cerr << "Error: Could not get username" << "\n";
      return 1;
    } else {
      std::cout << username << "\n";
    }
    // Construct the path to the file using the username
    std::string filePath = "C:\\Users\\" + std::string(username) + "\\file-list.txt";

    // create the file and open it in write mode
    std::ofstream outputFile(filePath, std::ios::out);

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
      std::cerr << "Failed to open the file: " << filePath << std::endl;
      return 1;
    }

    outputFile.clear();
  
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

    // create the file and open it in write mode
    std::ofstream outputFile(filePath, std::ios::out);

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
      std::cerr << "Failed to open the file: " << filePath << std::endl;
      return 1;
    }

    outputFile.clear();
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

    // create the file and open it in write mode
    std::ofstream outputFile(filePath, std::ios::out);

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
      std::cerr << "Failed to open the file: " << filePath << std::endl;
      return 1;
    }

    outputFile.clear();
  #endif
}