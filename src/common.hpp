#ifndef GUPPY_COMMON_H_
#define GUPPY_COMMON_H_

#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

namespace guppy {

#define GUPPY_VERSION "0.1.0"

enum class GuppyOption {
  kShowUsage,
  kShowHelp,
  kShowVersion,
  kInvertMatch,
  kCount,
  kOnlyFilename,
  kNoFilename,
  kNoColor,
  kIgnoreCase,
  kTrimPrecedingWhitespace,
  kRecursive,
};

}  // namespace guppy

#endif  // GUPPY_COMMON_H_
