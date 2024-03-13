#include "commands/AmpAuto.h"

AmpAuto::AmpAuto(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    AddRequirements(drivetrain); 
}

void AmpAuto::Initialize() {}

void AmpAuto::Execute() {}

void AmpAuto::End(bool interrupted) {}

bool AmpAuto::IsFinished() {return true;}