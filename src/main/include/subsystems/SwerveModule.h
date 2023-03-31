//
// Created by Nathan Cho on 2023-02-28.
//

#pragma once

#include <cmath>
#include <ctre/Phoenix.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <numbers>

class SwerveModule
{
  public:
    TalonFX drive_motor_;
    TalonFX steering_motor_;
    CANCoder encoder_;

    SwerveModule(const int& drive_motor_id, const int& steering_motor_id, const int& encoder_id);

    frc::SwerveModuleState getState();
    frc::SwerveModulePosition getPosition();
    void setDesiredState(const frc::SwerveModuleState& state);
    void setDesitedStateFromControllerOutput(); // TODO

  private:
    units::meter_t sensorUnitsToMeters(const double& sensor_units)
    {
        // Math:    (units per rotation) * (gear ratio) * (circumference) *
        // (inches to meters).
        //          (sensor_units / 2048) * (1 / 8.14) * (4 * pi) * (1 / 39.37)
        return units::meter_t{(sensor_units / 2048) * (1 / 8.14) * (4 * M_PI) * (1 / 39.37)};
    }
};