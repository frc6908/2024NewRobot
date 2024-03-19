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
    else if(t > 150 && t <= 200) {
        this->m_shooter->setShooterMotors(-0.1, -0.1);
    }
    else if(t > 200 && t <= 300) {
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_drivetrain->setDriveMotors(0.5, 0.5);
        this->m_intake->setIntakeMotor(1);
    }
    else if(t > 300 && t <= 310) {
        this->m_drivetrain->stop();
        this->m_intake->setIntakeMotor(-0.3);
        this->m_shooter->setShooterMotors(-0.5, -0.5);
    }
    else if(t > 310 && t <= 410) {
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_drivetrain->setDriveMotors(-0.5, -0.5);
    }
    else if(t > 410 && t <= 510) {
        this->m_drivetrain->stop();
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t > 510 && t <= 560) {
        this->m_intake->setIntakeMotor(1);
    }
    else if(t > 560 && t <= 660) {
        this->m_drivetrain->setDriveMotors(0.5, 0.5);
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_arm->stop();
    }
    else {
        this->m_drivetrain->stop();
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_arm->stop();
    }
    t++;
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