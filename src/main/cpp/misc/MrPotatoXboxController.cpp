//
// Created by Nathan Cho on 2023-03-18.
//

#include <misc/MrPotatoXboxController.h>

using namespace misc;

double * MrPotatoXboxController::getAllJoystickValues() {

    static double values[4];

    values[0] = MrPotatoXboxController::GetLeftX();
    values[1] = MrPotatoXboxController::GetLeftY();
    values[2] = MrPotatoXboxController::GetRightX();
    values[3] = MrPotatoXboxController::GetRightY();
    
    return values;
}