//
// Created by Nathan Cho on 2023-03-01.
//

#include <subsystems/SwerveModule.h>

using namespace drive_train;

SwerveModule::SwerveModule(const int& drive_motor_id, const int& steering_motor_id, const int& encoder_id) :
                drive_motor_{drive_motor_id},
                steering_motor_{steering_motor_id},
                encoder_{encoder_id}
{
    // Universal set up functions. Apply to all.
    drive_motor_.SetNeutralMode(NeutralMode::Brake);
    drive_motor_.ConfigPeakOutputForward(0.2);
    drive_motor_.ConfigPeakOutputReverse(-0.2);
    
    steering_motor_.SetNeutralMode(NeutralMode::Brake);
    encoder_.ConfigAbsoluteSensorRange(Signed_PlusMinus180);
}

SwerveModule::SwerveModule(const int& drive_motor_id, const int& steering_motor_id, const int& encoder_id, const double& encoder_offset) :
                drive_motor_{drive_motor_id},
                steering_motor_{steering_motor_id},
                encoder_{encoder_id}
{
    // Universal set up functions. Apply to all.
    drive_motor_.SetNeutralMode(NeutralMode::Brake);
    drive_motor_.ConfigPeakOutputForward(0.2);
    drive_motor_.ConfigPeakOutputReverse(-0.2);
    
    steering_motor_.SetNeutralMode(NeutralMode::Brake);
    encoder_.ConfigAbsoluteSensorRange(Signed_PlusMinus180);

    encoder_.ConfigMagnetOffset(encoder_offset);
}

frc::SwerveModuleState SwerveModule::getState()
{    
    // Convert sensor units to meters.
    // Multiply meters by 10 becuase getSelectedSensorVelocity returns sensor units per 100 ms.
    // Note: .value() used to allow for math.
    units::meters_per_second_t speed{getMetersFromSensorUnits(SwerveModule::drive_motor_.GetSelectedSensorVelocity()).value() * 10};
    units::radian_t angle{encoder_.GetAbsolutePosition()};
    
    return frc::SwerveModuleState{speed, angle};
}

frc::SwerveModulePosition SwerveModule::getPosition()
{
    units::meter_t distance{getMetersFromSensorUnits(SwerveModule::drive_motor_.GetSelectedSensorPosition())};
    units::radian_t angle{encoder_.GetAbsolutePosition()};

    return frc::SwerveModulePosition{distance, angle};
}

void SwerveModule::setDesiredState(const frc::SwerveModuleState& desired_state)
{
    // Optimize state to avoid spinning further than 90 degrees.
    auto optimized_state = frc::SwerveModuleState::Optimize(desired_state, units::radian_t{encoder_.GetAbsolutePosition()});

    // Convert meters per second into sensor units per 100ms.
    double driveOutputVelocity = 0.0;   // TODO.

    // Steering motor gear ratios require calculations.
    double steeringOutputPosition = 0.0;    // TODO.

    SwerveModule::drive_motor_.Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, driveOutputVelocity);
    SwerveModule::steering_motor_.Set(ctre::phoenix::motorcontrol::ControlMode::Position, steeringOutputPosition);
}