//
// Created by team 6364 on 2023-02-28.
//

#pragma once

#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <ctre/Phoenix.h>
#include <numbers>
#include <cmath>
#include <frc/geometry/Rotation2d.h>

namespace drive_train
{
    class SwerveModule {
        public:
        TalonFX drive_motor_;
        TalonFX steering_motor_;
        CANCoder encoder_;
        
        SwerveModule(const int& drive_motor_id, const int& steering_motor_id, const int& encoder_id);

        SwerveModule(const int& drive_motor_id, const int& steering_motor_id, const int& encoder_id, const double& encoder_offset);
        
        frc::SwerveModuleState getState();
        frc::SwerveModulePosition getPosition() const;
        void setDesiredState(const frc::SwerveModuleState& state);

        private:
        units::meter_t getMetersFromSensorUnits(const double& units)
        {
            // (units per rotation) * (gear ratio) * (circumference) * (inches to meters)
            // (x / 2048) * (1 / 8.14) * (4 * M_PI) * (1 / 39.37)
            // simplified
            return units::meter_t{units / 164081.5616 * M_PI};
        }
    };
}