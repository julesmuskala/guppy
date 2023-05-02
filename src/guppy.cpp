#include "guppy.hpp"

namespace guppy {

void Guppy::run(int argc, char** argv) {
  try {
    CommandLineParser command_line_parser(argc, argv);

    auto const& exe = command_line_parser.exe();
    auto const& options = command_line_parser.options();

    OutputFormatter output_formatter(options);
    OutputWriter output_writer(output_formatter, command_line_parser.exe(), options);

    if (options.contains(GuppyOption::kShowUsage)) {
      output_writer.write_usage(exe);

      return;
    }

    if (options.contains(GuppyOption::kShowHelp)) {
      output_writer.write_help(exe);

      return;
    }

    if (options.contains(GuppyOption::kShowVersion)) {
      output_writer.write_version();

      return;
    }

    PatternMatcher pattern_matcher(command_line_parser.pattern(), options);

    FileManager file_manager(command_line_parser.filenames(), options);

    file_manager.scan_files(pattern_matcher, output_writer);
  } catch (std::exception const& e) {
    OutputWriter::write_error(e.what());

    exit(EXIT_FAILURE);
  } catch (...) {
    OutputWriter::write_error("unknown error");

    exit(EXIT_FAILURE);
  }
}

}  // namespace guppy
