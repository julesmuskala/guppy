#include "pattern-matcher.hpp"

namespace guppy {

std::regex PatternMatcher::create_pattern_(std::string const& pattern_str) {
  if (options_.contains(GuppyOption::kIgnoreCase)) {
    return std::regex(pattern_str, std::regex_constants::icase);
  }

  return std::regex(pattern_str);
}

bool PatternMatcher::match(std::string const& str) const {
  bool result = std::regex_search(str, pattern_);

  if (options_.contains(GuppyOption::kInvertMatch)) {
    return !result;
  }

  return result;
}

}  // namespace guppy
