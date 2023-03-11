// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>

#include "subsystems/SwerveModule.h"

class Robot : public frc::TimedRobot 
{
 private:
  drive_train::SwerveModule front_left_swerve{drive_train::frontLeft, 1, 2, 3};
  drive_train::SwerveModule front_right_swerve{drive_train::frontRight, 4, 5, 6};
  drive_train::SwerveModule back_left_swerve{drive_train::backLeft, 7, 8, 9};
  drive_train::SwerveModule back_right_swerve{drive_train::backRight, 10, 11, 12};

 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;
};
