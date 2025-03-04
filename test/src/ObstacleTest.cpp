// Copyright (c) TrajoptLib contributors

#include <vector>

#include <catch2/catch_test_macros.hpp>
#include <trajopt/OptimalTrajectoryGenerator.hpp>
#include <trajopt/path/InitialGuessPoint.hpp>
#include <trajopt/path/SwervePathBuilder.hpp>

TEST_CASE("Obstacle - Linear initial guess", "[Obstacle]") {
  SKIP("Fails");

  using namespace trajopt;

  SwerveDrivetrain swerveDrivetrain{.mass = 45,
                                    .moi = 6,
                                    .modules = {{+0.6, +0.6, 0.04, 70, 2},
                                                {+0.6, -0.6, 0.04, 70, 2},
                                                {-0.6, +0.6, 0.04, 70, 2},
                                                {-0.6, -0.6, 0.04, 70, 2}}};

  trajopt::SwervePathBuilder path;
  path.PoseWpt(0, 0.0, 0.0, 0.0);
  path.PoseWpt(1, 2.0, 2.0, 0.0);

  constexpr double length = 0.7;
  constexpr double width = 0.7;
  path.AddBumpers(trajopt::Bumpers{.safetyDistance = 0.1,
                                   .points = {{+length / 2, +width / 2},
                                              {-length / 2, +width / 2},
                                              {-length / 2, -width / 2},
                                              {+length / 2, -width / 2}}});

  path.SgmtObstacle(
      0, 1, trajopt::Obstacle{.safetyDistance = 1.0, .points = {{1.0, 1.0}}});

  path.ControlIntervalCounts({10});
  CHECK_NOTHROW(trajopt::OptimalTrajectoryGenerator::Generate(path));
}
