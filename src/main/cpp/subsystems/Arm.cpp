#include "subsystems/Arm.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Arm::Arm() {
    pid.SetTolerance(2);
    encoder.SetDistancePerPulse(360.0/2048);
}

void Arm::setArmMotors(double speed) {
    armSpark1.Set(speed);
    armSpark2.Set(speed);
}

void Arm::resetEncoder() { 
    encoder.Reset();
}

double Arm::getEncoderDist() {
    return encoder.GetDistance();
}

double Arm::PIDCalculate(double target) {
    return -pid.Calculate(getEncoderDist(), target);
}

bool Arm::PIDfinished() {
    return pid.AtSetpoint();
}

void Arm::stop() {
    armSpark1.Set(0);
    armSpark2.Set(0);
}

void Arm::Periodic() {}