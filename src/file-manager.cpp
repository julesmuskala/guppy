#include "file-manager.hpp"

namespace guppy {

std::vector<FilenameParser> FileManager::create_parsers_(std::vector<std::string> const& filenames) {
  std::vector<FilenameParser> filename_parsers;

  for (auto const& filename : filenames) {
    filename_parsers.emplace_back(filename);
  }

  return filename_parsers;
}

void FileManager::scan_files(PatternMatcher pattern_matcher, OutputWriter output_writer) {
  for (auto const& filename_parser : filename_parsers_) {
    bool starting_point_exists = std::filesystem::exists(filename_parser.starting_point());

    if (!starting_point_exists) {
      std::string err_msg = "'" + filename_parser.starting_point() + "' does not exist";
      throw std::runtime_error(err_msg);
    }

    if (options_.contains(GuppyOption::kRecursive)) {
      const auto iterator = std::filesystem::recursive_directory_iterator(filename_parser.starting_point());

      for (auto const& entry : iterator) {
        std::string path = entry.path().string();

        if (!std::regex_search(path, std::regex(filename_parser.pattern()))) continue;

        FileReader file_reader(path, pattern_matcher, output_writer);

        file_reader.scan();
      }
    } else {
      const auto iterator = std::filesystem::directory_iterator(filename_parser.starting_point());

      for (auto const& entry : iterator) {
        std::string path = entry.path().string();

        if (!std::regex_search(path, std::regex(filename_parser.pattern()))) continue;

        FileReader file_reader(path, pattern_matcher, output_writer);

        file_reader.scan();
      }
    }
  }
}

}  // namespace guppy
