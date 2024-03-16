// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ResetDriveEncoders.h"

ResetDriveEncoders::ResetDriveEncoders(Drivetrain* drivetrain)
    : m_drivetrain{drivetrain} {

    AddRequirements(drivetrain); 
}

void ResetDriveEncoders::Initialize() {
    this->m_drivetrain->stop();
}

void ResetDriveEncoders::Execute() {
    this->m_drivetrain->stop();
}

void ResetDriveEncoders::End(bool interrupted) {
    this->m_drivetrain->resetEncoders();
    this->m_drivetrain->stop();
}

bool ResetDriveEncoders::IsFinished() {
    return true;
}
