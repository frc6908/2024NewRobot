// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PreloadedLeft.h"

PreloadedLeft::PreloadedLeft(Drivetrain* drivetrain, Shooter* shooter, Arm* arm, Intake* intake) : m_drivetrain{drivetrain}, m_shooter{shooter}, m_arm{arm}, m_intake{intake} {
    AddRequirements(drivetrain); 
    AddRequirements(shooter);
    AddRequirements(arm);
    AddRequirements(intake);
}

void PreloadedLeft::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_arm->stop();
    this->m_intake->stop();
}

void PreloadedLeft::Execute() {
    if(t >= 0 && t <= 100) {
        if(t <25){
            this->m_arm->setArmMotors(0.5);
        }
        else if(t <= 50) {
            this->m_arm->resetEncoder();
        }
        else{
            this->m_arm->stop();
        }
        
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
    }
    else {
        this->m_drivetrain->stop();
    }
    t++;
}

void PreloadedLeft::End(bool interrupted) {
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_arm->stop();
    this->m_intake->stop();
}

bool PreloadedLeft::IsFinished() {
    return false;
}