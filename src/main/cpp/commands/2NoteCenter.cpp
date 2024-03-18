// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TwoNoteCenter.h"

TwoNoteCenter::TwoNoteCenter(Drivetrain* drivetrain, Shooter* shooter, Arm* arm, Intake* intake) : m_drivetrain{drivetrain}, m_shooter{shooter}, m_arm{arm}, m_intake{intake} {
    AddRequirements(drivetrain); 
    AddRequirements(shooter);
    AddRequirements(arm);
    AddRequirements(intake);
}

void TwoNoteCenter::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
}

void TwoNoteCenter::Execute() {
    if(t >= 0 && t <= 100) {
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t > 100 && t <= 150) {
        this->m_intake->setIntakeMotor(1.0);
    }
    else if(t > 150 && t <= 250) {
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_drivetrain->setDriveMotors(0.2, 0.2);
        this->m_intake->setIntakeMotor(1);
    }
    else if(t > 250 && t <= 260) {
        this->m_drivetrain->stop();
        this->m_intake->setIntakeMotor(-0.3);
        this->m_shooter->setShooterMotors(-0.5, -0.5);
    }
    else if(t > 260 && t <= 360) {
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_drivetrain->setDriveMotors(-0.2, -0.2);
    }
    else if(t > 360 && t <= 460) {
        this->m_drivetrain->stop();
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t > 460 && t <= 510) {
        this->m_intake->setIntakeMotor(1);
    }
    else if(t > 510) {
        this->m_drivetrain->stop();
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_arm->stop();
    }
}

void TwoNoteCenter::End(bool interrupted) {
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_arm->stop();
    this->m_intake->stop();
}

bool TwoNoteCenter::IsFinished() {
    return false;
}