#include "commands/TwoPieceR.h"

TwoPieceR::TwoPieceR(Drivetrain* drivetrain, Shooter* shooter, Arm* arm, Intake* intake) : m_drivetrain{drivetrain}, m_shooter{shooter}, m_arm{arm}, m_intake{intake} {
    AddRequirements(drivetrain); 
    AddRequirements(shooter);
    AddRequirements(arm);
    AddRequirements(intake);
}

void TwoPieceR::Initialize() {
    t = 0, k = 0;
    this->m_drivetrain->stop();
    this->m_arm->stop();
    this->m_intake->stop();
    this->m_shooter->stop();
}

void TwoPieceR::Execute() {
    // set arm down, reset encoder
    if(t <= 25 && k == 0) {
        this->m_arm->setArmMotors(0.5);
    }
    else if(t <= 50 && k == 0) {
        this->m_arm->resetEncoder();
    }
    // turn to speaker, shoot note
    
    // turn back
    
    // move forward specified distance while intaking

    // move back to start 

    // turn to speaker, shoot note

    // move out of zone
    t++;
}
void TwoPieceR::End(bool interrupted) {
    this->m_drivetrain->stop();
    this->m_shooter->stop();
    this->m_intake->stop();
    this->m_arm->stop();
}

bool TwoPieceR::IsFinished() {
    return false;
}