// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <CANVenom.h>
#include <ctre/phoenix6/TalonFX.hpp>
//#include <ctre/phoenix6/VictorSFX.hpp>
#include <rev/CANSparkMax.h>
#include <rev/CANSparkLowLevel.h>
#include <rev/CANSparkBase.h>
#include <rev/SparkRelativeEncoder.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/controller/PIDController.h>
#include <frc/Encoder.h>

#include <frc/geometry/Rotation2d.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "Constants.h"

class Arm : public frc2::SubsystemBase {
 public:
  Arm();

  void setArmMotors(double);

  void resetEncoder();

  double getEncoderDist();

  double PIDCalculate(double);

  bool PIDfinished(); 

  void stop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  
  rev::CANSparkMax armSpark1{arm::kArmSparkPort1, rev::CANSparkLowLevel::MotorType::kBrushless}; // defining left side spark motor 1
  rev::CANSparkMax armSpark2{arm::kArmSparkPort2, rev::CANSparkLowLevel::MotorType::kBrushless}; // defining left side spark motor 2

  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("Test");
  
  frc::Encoder encoder{8, 9}; // change values for this, but prolly should work anyways
  frc::PIDController pid{0.01, 0, 0};
  
};