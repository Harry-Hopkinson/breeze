#include <src/args.hpp>

void print_usage() {
  std::cout << "Usage: breeze [options]\n"
            << "Options:\n"
            << "  -i, install   PACKAGE  Install the Specified Package\n"
            << "  -u, uninstall PACKAGE  Uninstall the Specified Package\n"
            << " -up, update    PACKAGE  Update the Specified Package\n"
            << "  -l, list               List all installed packages\n"
            << "  -h, --help             Show help messsage\n";
}

int args(int argc, char** argv) {
  // check if there are no args
  if (argc == 1) {
    print_usage();
    return 0;
  }
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      print_usage();
    } else if (arg == "-i" || arg == "--install" || arg == "install") {
      if (i + 1 < argc) {
        std::string package = argv[++i];
        install(package);
      } else {
        Logger::Error("No package specified");
        print_usage();
      }
    } else if (arg == "-u" || arg == "--uninstall" || arg == "uninstall") {
      if (i + 1 < argc) {
        std::string package = argv[++i];
        uninstall(package);
      } else {
        Logger::Error("No package specified");
        print_usage();
      }
    } else if (arg == "-up" || arg == "--update" || arg == "update") {
      if (i + 1 < argc) {
        std::string package = argv[++i];
        update(package);
      } else {
        Logger::Error("No package specified");
        print_usage();
      }
    } else if (arg == "-l" || arg == "--list" || arg == "list") {
      list();
    }
    else {
      Logger::Error("Unknown argument: " + arg);
      print_usage();
      return 0;
    }
  }
  return 0;
}
