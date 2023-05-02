#ifndef GUPPY_OUPUT_WRITER_H_
#define GUPPY_OUPUT_WRITER_H_

#include <iomanip>
#include <iostream>

#include "command-line-parser.hpp"
#include "common.hpp"
#include "output-formatter.hpp"

namespace guppy {

#define OPTION_WIDTH 28

class OutputWriter {
  std::unordered_set<GuppyOption> const& options_;

  OutputFormatter const& formatter_;
  std::string const& exe_;

 public:
  OutputWriter(OutputFormatter const& formatter,
               std::string const& exe,
               std::unordered_set<GuppyOption> const& options)
      : options_(options),
        formatter_(formatter),
        exe_(exe) {}

  void write_file(std::string const& filename, std::vector<std::string> const& lines) const;

  static void write_version();

  static void write_help(std::string const& exe);

  static void write_usage(std::string const& exe);

  static void write_error(std::string const& message);
};

}  // namespace guppy

#endif  // GUPPY_OUPUT_WRITER_H_
