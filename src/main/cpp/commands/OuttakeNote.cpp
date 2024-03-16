#include "commands/OuttakeNote.h"

OuttakeNote::OuttakeNote(Intake* intake, Shooter* shooter) : m_intake{intake}, m_shooter{shooter} {
    AddRequirements(intake);
    AddRequirements(shooter);
}

void OuttakeNote::Initialize() {
    this->m_intake->stop();
    this->m_shooter->stop();
}

void OuttakeNote::Execute() {
    this->m_intake->setIntakeMotor(-0.5);
    this->m_shooter->setShooterMotors(-0.5, -0.5);
}

void OuttakeNote::End(bool interrupted) {
    this->m_intake->stop();
    this->m_shooter->stop();
}

bool OuttakeNote::IsFinished() {
    
    return false;
/*
    if(this->m_intake->getDistance() < 300) {
        return true;
    } 
    else {
        return false;
    }

*/
}