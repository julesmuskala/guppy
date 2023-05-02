#include "filename-parser.hpp"

namespace guppy {

void FilenameParser::parse_filename_(std::string const& filename) {
  if (filename[0] == '~') {
    filename_ = get_home_directory_() + filename.substr(1);
  } else {
    filename_ = filename;
  }

  filename_ = std::filesystem::absolute(filename_).lexically_normal().string();
}

void FilenameParser::parse_pattern_() {
  cutoff_index_ = filename_.size();

  for (size_t i = 0; i < filename_.size(); ++i) {
    char c = filename_[i];

    switch (c) {
      case '?': {
        pattern_ += '.';

        if (cutoff_index_ == filename_.size()) {
          cutoff_index_ = i;
        }

        break;
      }
      case '*': {
        pattern_ += ".*";

        if (cutoff_index_ == filename_.size()) {
          cutoff_index_ = i;
        }

        break;
      }
      case '^':
      case '$':
      case '.':
      case '|':
      case '(':
      case ')':
      case '[':
      case ']':
      case '{':
      case '}':
      case '-':
      case '+':
      case '!':
      case '\\':
        pattern_ += '\\';
      default:
        pattern_ += c;
        break;
    }
  }
}

void FilenameParser::parse_starting_point_() {
  if (cutoff_index_ == filename_.size()) {
    starting_point_ = filename_;
  }

  starting_point_ = std::filesystem::path(filename_.substr(0, cutoff_index_)).parent_path().string();
}

std::string FilenameParser::get_home_directory_() {
  const char* home = std::getenv("HOME");

  if (home == nullptr) {
    return std::filesystem::current_path();
  }

  return home;
}

}  // namespace guppy
