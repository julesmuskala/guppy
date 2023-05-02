#include "file-reader.hpp"

namespace guppy {

void FileReader::scan() {
  std::vector<std::string> matching_lines;
  std::string current_line;

  file_.open(filename_);

  if (!file_.is_open()) {
    std::string err_msg = "'" + filename_ + "' could not be opened";
    throw std::runtime_error(err_msg);
  }

  while (std::getline(file_, current_line)) {
    if (current_line.empty()) continue;

    if (pattern_matcher_.match(current_line)) {
      matching_lines.emplace_back(current_line);
    }
  }

  output_writer_.write_file(filename_, matching_lines);

  file_.close();
}

}  // namespace guppy
