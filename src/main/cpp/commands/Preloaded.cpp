// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Preloaded.h"

Preloaded::Preloaded(Drivetrain* drivetrain, Shooter* shooter, Intake* intake) : m_drivetrain{drivetrain}, m_shooter{shooter}, m_intake{intake} {
    AddRequirements(drivetrain); 
    AddRequirements(shooter);
    AddRequirements(intake);
}

void Preloaded::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_intake->stop();
}

void Preloaded::Execute() {

       if(t >= 0 && t < 25) { // ****** TUNE THIS SECOND T VALUE SO THAT ARM GOES ALL THE WAY DOWN ****** 
        this->m_shooter->setShooterMotors(1, 1);
    }
    else if(t >= 65 && t <= 165) {
        this->m_shooter->setShooterMotors(1, 1);
        
    }
    else if(t > 165 && t <= 215) {
        this->m_shooter->setShooterMotors(1, 1);
        this->m_intake->setIntakeMotor(1.0);
    }
    else if(t > 215 && t <= 275) {
        this->m_intake->stop();
    }
    else {
        this->m_drivetrain->stop();
        this->m_intake->stop();
        this->m_shooter->stop();
    }
    t++;
}

void Preloaded::End(bool interrupted) {
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_intake->stop();
}

bool Preloaded::IsFinished() {
    return false;
}
