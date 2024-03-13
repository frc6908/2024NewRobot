// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <CANVenom.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <rev/CANSparkMax.h>
#include <rev/CANSparkLowLevel.h>
#include <rev/CANSparkBase.h>
#include <rev/SparkRelativeEncoder.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/SPI.h>
#include <AHRS.h>

#include <frc/geometry/Rotation2d.h>

#include <frc/drive/DifferentialDrive.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/util/HolonomicPathFollowerConfig.h>
#include <pathplanner/lib/util/PIDConstants.h>
#include <pathplanner/lib/util/ReplanningConfig.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/ChassisSpeeds.h>

#include <frc/controller/PIDController.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void setShooterMotors(double, double);

  void setShooterMotor1(double);

  void setShooterMotor2(double);

  void stop();

  double getEncoder1RPM();

  double getEncoder2RPM();

  double PID1Calculate(double);

  bool PID1finished(); 

  double PID2Calculate(double);

  bool PID2finished(); 

  void Periodic() override;

 private:
  rev::CANSparkMax shooterMotor1{shooter::kShooterSparkPort1, rev::CANSparkLowLevel::MotorType::kBrushless};   
  rev::CANSparkMax shooterMotor2{shooter::kShooterSparkPort2, rev::CANSparkLowLevel::MotorType::kBrushless}; 

  rev::SparkRelativeEncoder encoder1 = shooterMotor1.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor, 42);
  rev::SparkRelativeEncoder encoder2 = shooterMotor2.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor, 42);

  frc::PIDController shooterPID1{0.01, 0, 0};
  frc::PIDController shooterPID2{0.01, 0, 0};
};
