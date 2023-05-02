#include "command-line-parser.hpp"

namespace guppy {

std::vector<std::string> CommandLineParser::tokenize_(int argc, char* argv[]) {
  std::vector<std::string> tokens;

  exe_ = argv[0];

  for (int i = 1; i < argc; ++i) {
    tokens.push_back(argv[i]);
  }

  return tokens;
}

void CommandLineParser::parse_(std::vector<std::string> const& tokens) {
  enum class ParseState {
    kOptions,
    kPattern,
    kFilename,
    kNextFilename,
  } state = ParseState::kOptions;

  for (auto const& token : tokens) {
    switch (state) {
      case ParseState::kOptions: {
        if (token[0] != '-') {
          pattern_ = token;
          state = ParseState::kFilename;
          break;
        }

        parse_options_(token);
        break;
      }
      case ParseState::kPattern:
        pattern_ = token;
        state = ParseState::kFilename;
        break;
      case ParseState::kFilename:
        filenames_.push_back(token);
        state = ParseState::kNextFilename;
        break;
      case ParseState::kNextFilename:
        filenames_.push_back(token);
        break;
    }
  }

  if (state == ParseState::kOptions) {
    if (options_.empty()) options_.insert(GuppyOption::kShowUsage);

    return;
  }

  if (state != ParseState::kNextFilename) {
    std::string err_msg;

    switch (state) {
      case ParseState::kPattern:
        err_msg = "missing pattern";
        break;
      case ParseState::kFilename:
        err_msg = "missing filename";
        break;
      default:
        break;
    }

    throw std::logic_error(err_msg);
  }
}

void CommandLineParser::parse_options_(std::string const& token) {
  if (token.size() < 2 || token[0] != '-') {
    std::string err_msg = "malformed option token: '" + token + '\'';
    throw std::logic_error(err_msg);
  }

  if (token[1] == '-') {
    parse_long_option_(token.substr(2));
  } else {
    parse_short_option_(token.substr(1));
  }
}

void CommandLineParser::parse_long_option_(std::string const& token) {
  if (token == "help") {
    options_.insert(GuppyOption::kShowHelp);
  } else if (token == "version") {
    options_.insert(GuppyOption::kShowVersion);
  } else if (token == "invert-match") {
    options_.insert(GuppyOption::kInvertMatch);
  } else if (token == "count") {
    options_.insert(GuppyOption::kCount);
  } else if (token == "only-filename") {
    options_.insert(GuppyOption::kOnlyFilename);
  } else if (token == "no-filename") {
    options_.insert(GuppyOption::kNoFilename);
  } else if (token == "no-color") {
    options_.insert(GuppyOption::kNoColor);
  } else if (token == "ignore-case") {
    options_.insert(GuppyOption::kIgnoreCase);
  } else if (token == "trim") {
    options_.insert(GuppyOption::kTrimPrecedingWhitespace);
  } else if (token == "recursive") {
    options_.insert(GuppyOption::kRecursive);
  } else {
    std::string err_msg = "invalid option: '--" + token + "'";
    throw std::logic_error(err_msg);
  }
}

void CommandLineParser::parse_short_option_(std::string const& token) {
  for (auto c : token) {
    switch (c) {
      case 'h':
        options_.insert(GuppyOption::kShowHelp);
        break;
      case 'v':
        options_.insert(GuppyOption::kShowVersion);
        break;
      case 'I':
        options_.insert(GuppyOption::kInvertMatch);
        break;
      case 'c':
        options_.insert(GuppyOption::kCount);
        break;
      case 'f':
        options_.insert(GuppyOption::kOnlyFilename);
        break;
      case 'F':
        options_.insert(GuppyOption::kNoFilename);
        break;
      case 'C':
        options_.insert(GuppyOption::kNoColor);
        break;
      case 'i':
        options_.insert(GuppyOption::kIgnoreCase);
        break;
      case 't':
        options_.insert(GuppyOption::kTrimPrecedingWhitespace);
        break;
      case 'r':
        options_.insert(GuppyOption::kRecursive);
        break;
      default:
        std::string err_msg = "invalid option: -" + std::string(1, c);
        throw std::logic_error(err_msg);
    }
  }
}

}  // namespace guppy
