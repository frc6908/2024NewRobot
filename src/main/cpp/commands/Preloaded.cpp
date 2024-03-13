// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Preloaded.h"

Preloaded::Preloaded(Drivetrain* drivetrain, Shooter* shooter, Arm* arm, Intake* intake) : m_drivetrain{drivetrain}, m_shooter{shooter}, m_arm{arm}, m_intake{intake} {
    AddRequirements(drivetrain); 
    AddRequirements(shooter);
    AddRequirements(arm);
    AddRequirements(intake);
}

void Preloaded::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_arm->stop();
    this->m_intake->stop();
}

void Preloaded::Execute() {
    if(t <= 60) {
        this->m_arm->setArmMotors(0.5);
    }
    if(t >= 150 && t <= 200) {
        this->m_arm->stop();
        if(t == 150) {
            this->m_arm->resetEncoder();
        }
        this->m_shooter->setShooterMotors(-1, -1);
    }
    else if(t <= 225) {
        this->m_intake->setIntakeMotor(1.0);
    }
    else if(t <= 275) {
        this->m_shooter->stop();
        this->m_intake->stop();
        this->m_drivetrain->setDriveMotors(0.4, 0.4);
    }
    else{
        this->m_drivetrain->stop();
    }
    t++;
}

void Preloaded::End(bool interrupted) {
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_arm->stop();
    this->m_intake->stop();
}

bool Preloaded::IsFinished() {
    return false;
}