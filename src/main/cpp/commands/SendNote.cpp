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
    this->m_shooter->setShooterMotors(0.5, 0.5);
    if(t > 30) {
        this->m_intake->setIntakeMotor(0.5);
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