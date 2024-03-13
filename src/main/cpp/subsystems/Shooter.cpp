#include "subsystems/Shooter.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Shooter::Shooter() {
    shooterMotor2.SetInverted(1);
}

void Shooter::setShooterMotors(double s1, double s2) {
    shooterMotor1.Set(-s1);
    shooterMotor2.Set(s2);
}

void Shooter::stop() {
    shooterMotor1.Set(0);
    shooterMotor2.Set(0);
}

void Shooter::Periodic() {}