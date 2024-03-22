// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SlowAuto.h"

SlowAuto::SlowAuto(Drivetrain* drivetrain, Arm* arm) : m_drivetrain{drivetrain}, m_arm{arm} {
    AddRequirements(drivetrain); 
    AddRequirements(arm);
}

void SlowAuto::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
    this->m_arm->stop();
}

void SlowAuto::Execute() {
    if(t <= 100) {
        if(t < 25) { // ****** TUNE THIS VALUE SO THAT ARM GOES ALL THE WAY DOWN ******
            this->m_arm->setArmMotors(0.5);
        }
        else {
            this->m_arm->stop();
        }
        this->m_drivetrain->setDriveMotors(0.4, 0.4);
    }
    else {
        this->m_drivetrain->stop();
    }
    t++;
}

void SlowAuto::End(bool interrupted) {
    this->m_arm->resetEncoder();
    this->m_drivetrain->stop();
}

bool SlowAuto::IsFinished() {
    return false;
}