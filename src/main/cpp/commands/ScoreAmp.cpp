#include "commands/ScoreAmp.h"

ScoreAmp::ScoreAmp(Intake* intake, Shooter* shooter) : m_intake{intake}, m_shooter{shooter} {
    AddRequirements(intake);
    AddRequirements(shooter);
}

void ScoreAmp::Initialize() {
    this->m_intake->stop();
    this->m_shooter->stop();
}

void ScoreAmp::Execute() {
    this->m_shooter->setShooterMotors(-0.75, -0.75);
    this->m_intake->setIntakeMotor(1.0);
}

void ScoreAmp::End(bool interrupted) {
    this->m_intake->stop();
    this->m_shooter->stop();
}

bool ScoreAmp::IsFinished() {
    return false;
}