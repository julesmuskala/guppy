#ifndef GUPPY_GUPPY_H_
#define GUPPY_GUPPY_H_

#include "command-line-parser.hpp"
#include "common.hpp"
#include "file-manager.hpp"
#include "output-formatter.hpp"
#include "output-writer.hpp"
#include "pattern-matcher.hpp"

namespace guppy {

class Guppy {
 public:
  static void run(int argc, char** argv);
};

}  // namespace guppy

#endif  // GUPPY_GUPPY_H_
