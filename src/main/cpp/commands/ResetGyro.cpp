// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ResetGyro.h"

ResetGyro::ResetGyro(Drivetrain* drivetrain)
    : m_drivetrain{drivetrain} {

    AddRequirements(drivetrain); 
}

void ResetGyro::Initialize() {
    this->m_drivetrain->stop();
}

void ResetGyro::Execute() {
    this->m_drivetrain->stop();
}

void ResetGyro::End(bool interrupted) {
    this->m_drivetrain->resetGyro();
    this->m_drivetrain->stop();
}

bool ResetGyro::IsFinished() {
    return true;
}
