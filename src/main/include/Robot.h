// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>

#include "subsystems/SwerveModule.h"

class Robot : public frc::TimedRobot {
    private:
    // construct a swerve module like this.
    drive_train::SwerveModule front_left_swerve_{1, 2, 3, 55.810547};
    // or like this without the offset then ...
    // void Robot::RobotInit() {
    //     front_right_swerve_.encoder_.ConfigMagnetOffset(84.111328);
    // }
    // set it up in robot init
    drive_train::SwerveModule front_right_swerve_{4, 5, 6};

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
