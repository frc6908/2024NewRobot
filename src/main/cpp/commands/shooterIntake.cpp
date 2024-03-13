#include "commands/shooterIntake.h"

shooterIntake::shooterIntake(Shooter* shooter) : m_shooter{shooter} {
    AddRequirements(shooter);
    
}

void shooterIntake::Initialize() {
    this->m_shooter->stop();
}

void shooterIntake::Execute() {
    this->m_shooter->setShooterMotors(-0.5, -0.5);
}

void shooterIntake::End(bool interrupted) {
    this->m_shooter->stop();
}

bool shooterIntake::IsFinished() {
    return false;
}