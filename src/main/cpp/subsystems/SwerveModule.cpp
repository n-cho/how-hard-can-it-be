//
// Created by team 6364 on 2023-03-01.
//

#include <subsystems/SwerveModule.h>

drive_train::SwerveModule::SwerveModule(Corner corner, int drive_motor_id, int steering_motor_id, int encoder_id) :
                drive_motor{drive_motor_id},
                steering_motor{steering_motor_id},
                encoder{encoder_id}
    {
        drive_motor.SetNeutralMode(NeutralMode::Brake);
        drive_motor.ConfigPeakOutputForward(0.2);
        drive_motor.ConfigPeakOutputReverse(-0.2);
        
        steering_motor.SetNeutralMode(NeutralMode::Brake);
        encoder.ConfigAbsoluteSensorRange(Signed_PlusMinus180);
        switch (corner)
        {
            case drive_train::frontLeft:
                encoder.ConfigMagnetOffset(kFrontLeftEncoderOffset);
                break;
            case drive_train::frontRight:
                encoder.ConfigMagnetOffset(kFrontRightEncoderOffset);
                break;
            case drive_train::backLeft:
                encoder.ConfigMagnetOffset(kBackLeftEncoderOffset);
                break;
            case drive_train::backRight:
                encoder.ConfigMagnetOffset(kBackRightEncoderOffset);
                break;
        }
    }
frc::SwerveModuleState drive_train::SwerveModule::GetState() 
{    
    return frc::SwerveModuleState();
}