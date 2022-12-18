#include <utils/getOs.hpp>

std::string getOperatingSystem() {
  std::string output;
  std::stringstream result;
  result << std::system("ver");

  std::string osName;
  std::string osVersion;

  std::getline(result, osName, ' ');

  std::getline(result, output);

  std::stringstream version(output);
  std::getline(version, osVersion, '[');
  std::getline(version, osVersion, ']');


  return osName + " " + osVersion;
}
