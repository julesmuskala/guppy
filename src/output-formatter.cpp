#include "output-formatter.hpp"

namespace guppy {

std::string OutputFormatter::color_string_(std::string const& str, std::string const& color) const {
  return color + str + RESET;
}

std::string OutputFormatter::get_filename_(std::string const& filename) const {
  return options_.contains(GuppyOption::kNoColor) ? filename : color_string_(filename, MAGENTA);
}

std::string OutputFormatter::get_colon_() const {
  return options_.contains(GuppyOption::kNoColor) ? ":" : color_string_(":", CYAN);
}

std::string OutputFormatter::get_header_(std::string const& filename) const {
  if (options_.contains(GuppyOption::kNoFilename)) {
    return "";
  }

  if (options_.contains(GuppyOption::kOnlyFilename)) {
    return get_filename_(filename);
  }

  return get_filename_(filename) + get_colon_();
}

std::string OutputFormatter::format_only_filename(std::string const& filename) const {
  return get_header_(filename);
}

std::string OutputFormatter::format_line(std::string const& filename, std::string const& line) const {
  return get_header_(filename) + (options_.contains(GuppyOption::kTrimPrecedingWhitespace) ? trim_whitespace_(line) : line);
}

std::string OutputFormatter::format_count(std::string const& filename, const size_t count) const {
  return get_header_(filename) + std::to_string(count);
}

std::string OutputFormatter::trim_whitespace_(std::string const& str) const {
  std::regex pattern("^\\s+");

  return std::regex_replace(str, pattern, "");
}

}  // namespace guppy
