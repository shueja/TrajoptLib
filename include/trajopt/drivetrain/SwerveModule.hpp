// Copyright (c) TrajoptLib contributors

#pragma once

#include "trajopt/util/SymbolExports.hpp"

namespace trajopt {

/**
 * @brief This class represents a single swerve module in a swerve drivetrain.
 * It is defined by the module diagonal, which is the line connecting the origin
 * of the robot coordinate system to the center of the module. The wheel radius,
 * max speed, and max torque must also be specified per module.
 */
struct TRAJOPT_DLLEXPORT SwerveModule {
  /**
   * @brief x-coordinate (meters) of swerve module relative to robot coordinate
   * system
   */
  double x;
  /**
   * @brief y-coordinate (meters) of swerve module relative to robot coordinate
   * system
   */
  double y;
  /**
   * @brief radius of wheel (meters)
   */
  double wheelRadius;
  /**
   * @brief maximum angular velocity of wheel (rad/s)
   */
  double wheelMaxAngularVelocity;
  /**
   * @brief maximum torque (N−m) applied to wheel
   */
  double wheelMaxTorque;
};

}  // namespace trajopt
