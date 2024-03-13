// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace drivetrain {
    //set vals
    const int kLeftDriveSparkPort1 = 16;
    const int kLeftDriveSparkPort2 = 19;
    
    const int kRightDriveSparkPort1 = 15;
    const int kRightDriveSparkPort2 = 18;

    const int wheelDiameter = 6; //inches 

}

namespace arm {
    const int kArmSparkPort1 = 2;
    const int kArmSparkPort2 = 3;
}

namespace intake {
    const int kIntakeTalonPort = 10;
}

namespace oi {
    const int kDriveJoystickPort = 0;   // drive joystick
    const int kArmJoystickPort = 1; // elbow joystick
}

namespace shooter {
    const int kShooterSparkPort1 = 5;
    const int kShooterSparkPort2 = 6;
}


