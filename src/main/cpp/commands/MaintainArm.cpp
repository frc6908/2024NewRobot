// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/MaintainArm.h"

MaintainArm::MaintainArm(Arm* arm)
    : m_arm{arm} {

    AddRequirements(arm); 
}

void MaintainArm::Initialize() {
    this->m_arm->stop();
}

void MaintainArm::Execute() {
    frc::SmartDashboard::PutNumber("Encoder", this->m_arm->getEncoderDist());
    this->m_arm->setArmMotors(-0.01);
}

void MaintainArm::End(bool interrupted) {
    this->m_arm->stop();
}

bool MaintainArm::IsFinished() {
    return false;
}
