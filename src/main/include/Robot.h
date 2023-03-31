// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>

#include "subsystems/SwerveModule.h"

class Robot : public frc::TimedRobot
{
  public:
    void RobotInit() override;
    void RobotPeriodic() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

  private:
    SwerveModule front_left_swerve_{3, 7, 11};
    SwerveModule front_right_swerve_{1, 5, 9};
    SwerveModule back_left_swerve_{2, 6, 10};
    SwerveModule back_right_swerve_{4, 8, 12};
};
