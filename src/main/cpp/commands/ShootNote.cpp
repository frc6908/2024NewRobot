#include "commands/ShootNote.h"

ShootNote::ShootNote(Shooter* shooter) : m_shooter{shooter} {
    AddRequirements(shooter);
    
}

void ShootNote::Initialize() {
    this->m_shooter->stop();
}

void ShootNote::Execute() {
    this->m_shooter->setShooterMotors(1.0, 1.0);
}

void ShootNote::End(bool interrupted) {
    this->m_shooter->stop();
}

bool ShootNote::IsFinished() {
    return false;
}