#include "subsystems/Intake.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Intake::Intake() {
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kOrangeTarget);
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
        colorstr = "Blue";
        return false;
    }
    else if(matchedColor == kGreenTarget) {
        colorstr = "Green";
    }
    else if(matchedColor == kRedTarget) {
        colorstr = "Red";
    }
    else if(matchedColor == kOrangeTarget) {
        colorstr = "Orange";
    }
    else {
        colorstr = "Unknown";
    }
    return true; 
}

void Intake::Periodic() {
    frc::SmartDashboard::PutBoolean("HasNote", hasNote());
    frc::SmartDashboard::PutString("Color", colorstr);
    // frc::SmartDashboard::PutNumber("Sensor Distance", m_colorSensor.GetIR());
}