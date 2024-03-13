#include "subsystems/Intake.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Intake::Intake() {}

void Intake::setIntakeMotor(double speed) {
    IntakeMotor.Set(speed);
}

void Intake::stop() {
    IntakeMotor.Set(0);
}
/*
double Intake::getDistance() {
    return distSensor.GetRange();
}
*/
void Intake::Periodic() {}