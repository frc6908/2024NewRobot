// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnDegrees.h"

TurnDegrees::TurnDegrees(Drivetrain* drivetrain, double t)
    : m_drivetrain{drivetrain}, target{t} {

    AddRequirements(drivetrain); 
}

void TurnDegrees::Initialize() {
    this->m_drivetrain->stop();
}

void TurnDegrees::Execute() {
    double a = this->m_drivetrain->TurnPIDCalculate(target);
    if(a < 0) {
        a -= 0.28;
        a = std::max(a, -1.0);
    }
    else {
        a += 0.28;
        a = std::min(a, 1.0);
    }
    this->m_drivetrain->arcadeDrive(0, -a);
}

void TurnDegrees::End(bool interrupted) {
    this->m_drivetrain->stop();
}

bool TurnDegrees::IsFinished() {
    return this->m_drivetrain->TurnPIDIsFinished();
}
