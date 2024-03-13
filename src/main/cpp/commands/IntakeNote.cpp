#include "commands/IntakeNote.h"

IntakeNote::IntakeNote(Intake* intake) : m_intake{intake} {
    AddRequirements(intake);
}

void IntakeNote::Initialize() {
    this->m_intake->stop();
}

void IntakeNote::Execute() {
    this->m_intake->setIntakeMotor(0.7);
}

void IntakeNote::End(bool interrupted) {
    this->m_intake->stop();
}

bool IntakeNote::IsFinished() {
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