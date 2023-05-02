#ifndef GUPPY_FILE_MANAGER_H_
#define GUPPY_FILE_MANAGER_H_

#include <filesystem>
#include <regex>

#include "common.hpp"
#include "file-reader.hpp"
#include "filename-parser.hpp"
#include "output-writer.hpp"
#include "pattern-matcher.hpp"

namespace guppy {

class FileManager {
  std::unordered_set<GuppyOption> options_;

  std::vector<FilenameParser> filename_parsers_;

  std::vector<FilenameParser> create_parsers_(std::vector<std::string> const& filenames);

 public:
  FileManager(std::vector<std::string> const& filenames, std::unordered_set<GuppyOption> const& options)
      : options_(options), filename_parsers_(create_parsers_(filenames)) {}

  void scan_files(PatternMatcher pattern_matcher, OutputWriter output_writer);
};

}  // namespace guppy

#endif  // GUPPY_FILE_MANAGER_H_
