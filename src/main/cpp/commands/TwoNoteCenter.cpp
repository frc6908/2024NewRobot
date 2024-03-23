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
    if(t >= 0 && t < 25) { // ****** TUNE THIS SECOND T VALUE SO THAT ARM GOES ALL THE WAY DOWN ****** 
        this->m_arm->setArmMotors(1);
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t >= 65 && t <= 165) {
        this->m_arm->stop();
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t > 165 && t <= 215) {
        this->m_intake->setIntakeMotor(1.0);
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t > 215 && t <= 265) {
        this->m_intake->stop();
        this->m_shooter->setShooterMotors(-0.1, -0.1);
    }
    else if(t > 265 && t <= 365) {
        this->m_shooter->stop();
        this->m_drivetrain->setDriveMotors(0.5, 0.5);
        this->m_intake->setIntakeMotor(1);
    }
    else if(t > 365 && t <= 375) {
        this->m_drivetrain->stop();
        this->m_intake->setIntakeMotor(-0.3);
        this->m_shooter->setShooterMotors(-0.5, -0.5);
    }
    else if(t > 375 && t <= 485) {
        this->m_intake->stop();
        this->m_shooter->stop();
        this->m_drivetrain->setDriveMotors(-0.5, -0.5);
    }
    else if(t > 485 && t <= 585) {
        this->m_drivetrain->stop();
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t > 585 && t <= 635) {
        this->m_intake->setIntakeMotor(1);
    }
    else if(t > 635 && t <= 735) {
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
    this->m_arm->resetEncoder();
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_arm->stop();
    this->m_intake->stop();
}

bool TwoNoteCenter::IsFinished() {
    return false;
}