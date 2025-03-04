// Copyright (c) TrajoptLib contributors

#pragma once

#include <vector>

#include "trajopt/util/SymbolExports.hpp"

namespace trajopt {

/**
 * The trajectory optimization solution.
 */
struct TRAJOPT_DLLEXPORT Solution {
  /// Times between samples.
  std::vector<double> dt;

  /// X positions.
  std::vector<double> x;

  /// Y positions.
  std::vector<double> y;

  /// Headings.
  std::vector<double> theta;
};

}  // namespace trajopt
