//
// Created by Nathan Cho on 2023-03-18.
//

#pragma once

#include <frc/XboxController.h>

namespace misc
{
    class MrPotatoXboxController: public frc::XboxController {
        public:
        double * getAllJoystickValues();
    };
}