//
// Created by team 6364 on 2023-02-28.
//

#pragma once

#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <ctre/Phoenix.h>

namespace drive_train {
    enum Corner { frontLeft, frontRight, backLeft, backRight };

    class SwerveModule
    {
        public:
            TalonFX drive_motor;
            TalonFX steering_motor;
            CANCoder encoder;

            /// @brief SwerveModule constructor. Represents one of 4 swerve modules on robot.
            /// @param corner frontLeft or frontRight or backLeft or backRight. Used to set offsets.
            /// @param drive_motor_id Drive Motor ID
            /// @param steering_motor_id Steering Motor ID
            /// @param encoder_id CANCoder ID
            SwerveModule(Corner corner, int drive_motor_id, int steering_motor_id, int encoder_id);

            frc::SwerveModuleState GetState();

        private:
            static constexpr double kFrontLeftEncoderOffset{55.810547};
            static constexpr double kFrontRightEncoderOffset{84.111328};
            static constexpr double kBackLeftEncoderOffset{56.074219};
            static constexpr double kBackRightEncoderOffset{-116.015625};
    };
}