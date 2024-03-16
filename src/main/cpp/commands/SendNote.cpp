#include "commands/SendNote.h"

SendNote::SendNote(Intake* intake, Shooter* shooter) : m_intake{intake}, m_shooter{shooter} {
    AddRequirements(intake);
    AddRequirements(shooter);
    t = 0;
}

void SendNote::Initialize() {
    this->m_intake->stop();
    this->m_shooter->stop();
}

void SendNote::Execute() {
    this->m_shooter->setShooterMotors(1, 1);
    if(t > 100) {
        this->m_intake->setIntakeMotor(1.0);
    }
    t++;
}

void SendNote::End(bool interrupted) {
    this->m_intake->stop();
    this->m_shooter->stop();
    t = 0;
}

bool SendNote::IsFinished() {
    return t == 130;
}