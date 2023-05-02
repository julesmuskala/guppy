#ifndef GUPPY_PATTERN_MATCHER_H_
#define GUPPY_PATTERN_MATCHER_H_

#include <regex>

#include "command-line-parser.hpp"
#include "common.hpp"

namespace guppy {

class PatternMatcher {
  std::unordered_set<GuppyOption> options_;

  std::regex pattern_;

  std::regex create_pattern_(std::string const& pattern_str);

 public:
  PatternMatcher(std::string const& pattern, std::unordered_set<GuppyOption> const& options)
      : options_(options),
        pattern_(create_pattern_(pattern)) {}

  bool match(std::string const& str) const;
};

}  // namespace guppy

#endif  // GUPPY_PATTERN_MATCHER_H_
