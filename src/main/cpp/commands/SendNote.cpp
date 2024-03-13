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
    this->m_shooter->setShooterMotor1(this->m_shooter->PID1Calculate(80) + 0.00017);
    this->m_shooter->setShooterMotor2(this->m_shooter->PID2Calculate(80) + 0.00017);
    if(this->m_shooter->PID1finished() && this->m_shooter->PID2finished()) {
        this->m_intake->setIntakeMotor(1.0);
    }
}

void SendNote::End(bool interrupted) {
    this->m_intake->stop();
    this->m_shooter->stop();
    t = 0;
}

bool SendNote::IsFinished() {
    return false;
}