#include "subsystems/Shooter.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Shooter::Shooter() {
    shooterMotor2.SetInverted(1);
    shooterPID1.SetTolerance(2);
    shooterPID2.SetTolerance(2);
}

void Shooter::setShooterMotors(double s1, double s2) {
    shooterMotor1.Set(-s1);
    shooterMotor2.Set(s2);
}

void Shooter::setShooterMotor1(double s) {
    shooterMotor1.Set(s);
}

void Shooter::setShooterMotor2(double s) {
    shooterMotor2.Set(s);
}

double Shooter::getEncoder1RPM() {
    return encoder1.GetVelocity();
}

double Shooter::getEncoder2RPM() {
    return encoder2.GetVelocity();
}

double Shooter::PID1Calculate(double target) {
    return shooterPID1.Calculate(getEncoder1RPM(), target);
}

bool Shooter::PID1finished() {
    return shooterPID1.AtSetpoint();
}
double Shooter::PID2Calculate(double target) {
    return shooterPID2.Calculate(getEncoder2RPM(), target);
}

bool Shooter::PID2finished() {
    return shooterPID2.AtSetpoint();
}

void Shooter::stop() {
    shooterMotor1.Set(0);
    shooterMotor2.Set(0);
}

void Shooter::Periodic() {}