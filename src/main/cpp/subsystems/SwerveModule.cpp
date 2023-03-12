//
// Created by team 6364 on 2023-03-01.
//

#include <subsystems/SwerveModule.h>

drive_train::SwerveModule::SwerveModule(const int& drive_motor_id, const int& steering_motor_id, const int& encoder_id) :
                drive_motor_{drive_motor_id},
                steering_motor_{steering_motor_id},
                encoder_{encoder_id}
{
    drive_motor_.SetNeutralMode(NeutralMode::Brake);
    drive_motor_.ConfigPeakOutputForward(0.2);
    drive_motor_.ConfigPeakOutputReverse(-0.2);
    
    steering_motor_.SetNeutralMode(NeutralMode::Brake);
    encoder_.ConfigAbsoluteSensorRange(Signed_PlusMinus180);
}
drive_train::SwerveModule::SwerveModule(const int& drive_motor_id, const int& steering_motor_id, const int& encoder_id, const double& encoder_offset) :
                drive_motor_{drive_motor_id},
                steering_motor_{steering_motor_id},
                encoder_{encoder_id}
{
    drive_motor_.SetNeutralMode(NeutralMode::Brake);
    drive_motor_.ConfigPeakOutputForward(0.2);
    drive_motor_.ConfigPeakOutputReverse(-0.2);
    
    steering_motor_.SetNeutralMode(NeutralMode::Brake);
    encoder_.ConfigAbsoluteSensorRange(Signed_PlusMinus180);

    encoder_.ConfigMagnetOffset(encoder_offset);
}
frc::SwerveModuleState drive_train::SwerveModule::getState()
{    
    // (sensor units to meters) * (10) becuase getSelectedSensorVelocity returns sensor units per 100 ms.
    // convert units::meter_t from getMetersFromSensorUnits to double using value() so it can be converted to units::meters_per_second_t
    units::meters_per_second_t speed{getMetersFromSensorUnits(drive_train::SwerveModule::drive_motor_.GetSelectedSensorVelocity()).value() * 10};
    units::radian_t angle{encoder_.GetAbsolutePosition()};
    
    return frc::SwerveModuleState{speed, angle};
}