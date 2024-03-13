// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ResetArmEncoder.h"

ResetArmEncoder::ResetArmEncoder(Arm* arm)
    : m_arm{arm} {

    AddRequirements(arm); 
}

void ResetArmEncoder::Initialize() {
    this->m_arm->stop();
}

void ResetArmEncoder::Execute() {
    this->m_arm->stop();
}

void ResetArmEncoder::End(bool interrupted) {
    this->m_arm->resetEncoder();
    this->m_arm->stop();
    frc::SmartDashboard::PutNumber("Encoder", this->m_arm->getEncoderDist());
}

bool ResetArmEncoder::IsFinished() {
    return true;
}
