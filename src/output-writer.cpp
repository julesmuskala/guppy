#include "output-writer.hpp"

namespace guppy {

void OutputWriter::write_usage(std::string const& exe) {
  std::cout << "Usage: " + exe + " [OPTION]... PATTERN [FILE]..." << std::endl;
  std::cout << "Try '" + exe + " --help' for more information." << std::endl;
}

void OutputWriter::write_version() {
  std::cout << "guppy version: " << GUPPY_VERSION << std::endl;
}

void OutputWriter::write_help(std::string const& exe) {
  std::cout << "Usage: " << exe << " [OPTION]... PATTERN [FILE]..." << std::endl;
  std::cout << "Search for PATTERN in each FILE." << std::endl;
  std::cout << "Example: " << exe << " -i 'hello world' menu.h main.c" << std::endl;
  std::cout << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-h, --help"
            << "display this help text and exit" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-v, --version"
            << "display version information and exit" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-I, --invert-match"
            << "select non-matching lines" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-c, --count"
            << "print only a count of selected lines per FILE" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-f, --only-filename"
            << "print only names of FILEs with selected lines" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-F, --no-filename"
            << "suppress the filename prefix on output" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-C, --no-color"
            << "suppress colored output" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-i, --ignore-case"
            << "ignore PATTERN case when matching" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-t, --trim"
            << "trim preceding whitespace when outputting line" << std::endl;
  std::cout << std::setw(OPTION_WIDTH) << std::left << "-r, --recursive"
            << "search directories and their contents recursively" << std::endl;
}

void OutputWriter::write_error(std::string const& message) {
  std::cerr << "Program exited with error: " << message << std::endl;
}

void OutputWriter::write_file(std::string const& filename, std::vector<std::string> const& lines) const {
  if (options_.contains(GuppyOption::kCount)) {
    std::cout << formatter_.format_count(filename, lines.size()) + "\n";
    return;
  }

  if (options_.contains(GuppyOption::kOnlyFilename)) {
    std::cout << formatter_.format_only_filename(filename) + "\n";
    return;
  }

  std::string result = "";

  for (auto const& line : lines) {
    result += formatter_.format_line(filename, line);
    result += "\n";
  }

  std::cout << result;
}

}  // namespace guppy
