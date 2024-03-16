#include "subsystems/Shooter.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Shooter::Shooter() {
    shooterMotor1.RestoreFactoryDefaults();
    shooterMotor2.RestoreFactoryDefaults();
    
    frc::SmartDashboard::PutNumber("P1", kp1);
    frc::SmartDashboard::PutNumber("I1", ki1);
    frc::SmartDashboard::PutNumber("D1", kd1);
    frc::SmartDashboard::PutNumber("iz1", kiz1);

    frc::SmartDashboard::PutNumber("P2", kp2);
    frc::SmartDashboard::PutNumber("I2", ki2);
    frc::SmartDashboard::PutNumber("D2", kd2);
    frc::SmartDashboard::PutNumber("iz2", kiz2);


    frc::SmartDashboard::PutNumber("FF", kFF);
    frc::SmartDashboard::PutNumber("FF", kFF);
    frc::SmartDashboard::PutNumber("FF", kFF);

}

void Shooter::setShooterMotors(double s1, double s2) {
    shooterMotor1.Set(s1);
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

void Shooter::PID1Calculate(double target) {
    shooterPID1.SetReference(target, rev::CANSparkMax::ControlType::kVelocity);
}

void Shooter::PID2Calculate(double target) {
    shooterPID2.SetReference(target, rev::CANSparkMax::ControlType::kVelocity);
}

void Shooter::stop() {
    shooterMotor1.Set(0);
    shooterMotor2.Set(0);
}

bool Shooter::inRange(double curr, double target) {
    if(target - 10 <= curr && target + 10 >= curr) {
        return true;
    }
    return false;
}

void Shooter::Periodic() {
    frc::SmartDashboard::PutNumber("Shooter1 Velocity", getEncoder1RPM());
    frc::SmartDashboard::PutNumber("Shooter2 Velocity", getEncoder2RPM());

    // shooterPID1.SetP(frc::SmartDashboard::GetNumber("kp1", 0));
    // shooterPID1.SetI(frc::SmartDashboard::GetNumber("ki1", 0));
    // shooterPID1.SetD(frc::SmartDashboard::GetNumber("kd1", 0));
    // shooterPID1.SetIZone(frc::SmartDashboard::GetNumber("kiz1", 0));
    // shooterPID1.SetFF(frc::SmartDashboard::GetNumber("kFF", 0));
    // shooterPID1.SetOutputRange(frc::SmartDashboard::GetNumber("kMin", 0), frc::SmartDashboard::GetNumber("kMax", 0));

    // shooterPID2.SetP(frc::SmartDashboard::GetNumber("kp2", 0));
    // shooterPID2.SetI(frc::SmartDashboard::GetNumber("ki2", 0));
    // shooterPID2.SetD(frc::SmartDashboard::GetNumber("kd2", 0));
    // shooterPID2.SetIZone(frc::SmartDashboard::GetNumber("kiz2", 0));
    // shooterPID2.SetFF(frc::SmartDashboard::GetNumber("kFF", 0));
    // shooterPID2.SetOutputRange(-1, 1);
}