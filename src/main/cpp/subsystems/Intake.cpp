#include "subsystems/Intake.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Intake::Intake() {
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);
}

void Intake::setIntakeMotor(double speed) {
    IntakeMotor.Set(speed);
}

void Intake::stop() {
    IntakeMotor.Set(0);
}

bool Intake::hasNote() {
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(m_colorSensor.GetColor(), confidence);
    if (matchedColor == kBlueTarget) {
        return false;
    }
    return true; 
}

void Intake::Periodic() {}