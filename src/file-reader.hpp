#ifndef GUPPY_FILE_READER_H_
#define GUPPY_FILE_READER_H_

#include <fstream>

#include "common.hpp"
#include "output-writer.hpp"
#include "pattern-matcher.hpp"

namespace guppy {

class FileReader {
  std::string const& filename_;
  std::ifstream file_;

  PatternMatcher const& pattern_matcher_;
  OutputWriter const& output_writer_;

 public:
  FileReader(std::string const& filename,
             PatternMatcher const& pattern_matcher,
             OutputWriter const& output_writer)
      : filename_(filename), pattern_matcher_(pattern_matcher), output_writer_(output_writer) {}

  void scan();
};

}  // namespace guppy

#endif  // GUPPY_FILE_READER_H_
