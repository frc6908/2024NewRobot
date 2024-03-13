#include "commands/OuttakeNote.h"

OuttakeNote::OuttakeNote(Intake* intake) : m_intake{intake} {
    AddRequirements(intake);
}

void OuttakeNote::Initialize() {
    this->m_intake->stop();
}

void OuttakeNote::Execute() {
    this->m_intake->setIntakeMotor(-0.5);
}

void OuttakeNote::End(bool interrupted) {
    this->m_intake->stop();
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