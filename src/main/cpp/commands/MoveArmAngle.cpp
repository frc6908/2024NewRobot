// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/MoveArmAngle.h"

MoveArmAngle::MoveArmAngle(Arm* arm, double t)
    : m_arm{arm}, target{t} {

    AddRequirements(arm); 
}

void MoveArmAngle::Initialize() {
    this->m_arm->stop();
}

void MoveArmAngle::Execute() {
    frc::SmartDashboard::PutNumber("Encoder", this->m_arm->getEncoderDist());
    this->m_arm->setArmMotors(this->m_arm->PIDCalculate(target));
}

void MoveArmAngle::End(bool interrupted) {
    this->m_arm->stop();
}

bool MoveArmAngle::IsFinished() {
    if(this->m_arm->PIDfinished()) {
        return true;
    }
    return false;
}
