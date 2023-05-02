#ifndef GUPPY_COMMAND_LINE_PARSER_H_
#define GUPPY_COMMAND_LINE_PARSER_H_

#include "common.hpp"

namespace guppy {

class CommandLineParser {
  std::string exe_;
  std::unordered_set<GuppyOption> options_;
  std::string pattern_;
  std::vector<std::string> filenames_;

  std::vector<std::string> tokenize_(int argc, char* argv[]);
  void parse_(std::vector<std::string> const& tokens);
  void parse_options_(std::string const& token);

  void parse_long_option_(std::string const& token);
  void parse_short_option_(std::string const& token);

 public:
  CommandLineParser(int argc, char** argv) {
    auto tokens = tokenize_(argc, argv);

    parse_(tokens);
  }

  inline std::string const& exe() const { return exe_; }
  inline std::unordered_set<GuppyOption> const& options() const { return options_; }
  inline std::string const& pattern() const { return pattern_; }
  inline std::vector<std::string> const& filenames() const { return filenames_; }
};

}  // namespace guppy

#endif  // GUPPY_COMMAND_LINE_PARSER_H_
