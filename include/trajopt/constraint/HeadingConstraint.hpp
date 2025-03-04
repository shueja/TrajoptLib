// Copyright (c) TrajoptLib contributors

#pragma once

#include "trajopt/set/IntervalSet1d.hpp"
#include "trajopt/util/SymbolExports.hpp"

namespace trajopt {

/**
 * Heading constraint.
 */
struct TRAJOPT_DLLEXPORT HeadingConstraint {
  /// The heading bound (radians)
  IntervalSet1d headingBound;
};

}  // namespace trajopt
