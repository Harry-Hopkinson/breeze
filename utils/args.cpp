#include <utils/args.hpp>

void print_usage() {
  std::cout << "Usage: myprogram [options]\n"
            << "Options:\n"
            << "  -i, --input-file FILE  Specify the input file\n"
            << "  -o, --output-file FILE Specify the output file\n"
            << "  -v, --verbose          Enable verbose mode\n"
            << "  -h, --help             Print this message and exit\n";
}

int args(int argc, char** argv) {
  std::cout << "Hello, world!\n";
  return 0;
}
