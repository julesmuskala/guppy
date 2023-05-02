#ifndef GUPPY_FILENAME_PARSER_H_
#define GUPPY_FILENAME_PARSER_H_

#include <filesystem>

#include "common.hpp"

namespace guppy {

class FilenameParser {
  std::string filename_;
  std::string pattern_;

  size_t cutoff_index_;
  std::string starting_point_;

  void parse_filename_(std::string const& filename);
  void parse_pattern_();
  void parse_starting_point_();

  std::string get_home_directory_();

 public:
  FilenameParser(const std::string& filename) {
    parse_filename_(filename);
    parse_pattern_();
    parse_starting_point_();
  }

  std::string const& filename() const { return filename_; }
  std::string const& starting_point() const { return starting_point_; }
  std::string const& pattern() const { return pattern_; }
};

}  // namespace guppy

#endif  // GUPPY_FILENAME_PARSER_H_
