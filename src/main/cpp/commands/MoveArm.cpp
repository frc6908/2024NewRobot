// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/MoveArm.h"

MoveArm::MoveArm(Arm* arm, bool d, double t)
    : m_arm{arm}, dir{d}, throttle{t} {

    AddRequirements(arm); 
}

void MoveArm::Initialize() {
    this->m_arm->stop();
}

void MoveArm::Execute() {
    frc::SmartDashboard::PutNumber("Encoder", this->m_arm->getEncoderDist());
    // Scale throttle based on distance from maximum (Implemented by Kavin 2024-04-23 @ 3:25PM)
    double delta = 10; // Buffer zone (in degrees)
    double min_error = this->m_arm->getEncoderDist() - 0; // Arm distance from minimum position
    double max_error = 97 - this->m_arm->getEncoderDist(); // Arm distance from maximum position
    if(dir && 0 <= min_error <= delta){
        this->m_arm->setArmMotors((min_error/delta)*throttle); // As arm approaches the minimum position, linearly scale the throttle input
    }
    else if(!dir && 0 <= max_error <= delta){
        this->m_arm->setArmMotors((max_error/delta)*throttle); // As arm approaches the maximum position, linearly scale the throttle input
    }
    // if(dir && this->m_arm->getEncoderDist() >= 0) {
    //     this->m_arm->setArmMotors(throttle);
    // }
    // else if(!dir && this->m_arm->getEncoderDist() <= 97) {
    //     this->m_arm->setArmMotors(-throttle);
    // }
}

void MoveArm::End(bool interrupted) {
    this->m_arm->stop();
}

bool MoveArm::IsFinished() {
    return false;
}
