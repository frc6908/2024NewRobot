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
    if(dir) {
        this->m_arm->setArmMotors(throttle);
    }
    else if(!dir && this->m_arm->getEncoderDist() <= 97) {
        this->m_arm->setArmMotors(-throttle);
    }
}

void MoveArm::End(bool interrupted) {
    this->m_arm->stop();
}

bool MoveArm::IsFinished() {
    return false;
}
