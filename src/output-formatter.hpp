#ifndef GUPPY_OUPUT_FORMATTER_H_
#define GUPPY_OUPUT_FORMATTER_H_

#include <regex>

#include "command-line-parser.hpp"
#include "common.hpp"

namespace guppy {

#define RESET "\033[0m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

class OutputFormatter {
  std::unordered_set<GuppyOption> options_;

  std::string color_string_(std::string const& str, std::string const& color) const;
  std::string get_filename_(std::string const& filename) const;
  std::string get_colon_() const;
  std::string get_header_(std::string const& filename) const;

  std::string trim_whitespace_(std::string const& str) const;

 public:
  OutputFormatter(std::unordered_set<GuppyOption> const& options) : options_(options) {}

  std::string format_only_filename(std::string const& filename) const;
  std::string format_line(std::string const& filename, std::string const& line) const;
  std::string format_count(std::string const& filename, const size_t count) const;
};

}  // namespace guppy

#endif  // GUPPY_OUPUT_FORMATTER_H_
