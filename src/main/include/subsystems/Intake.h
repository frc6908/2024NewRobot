// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <CANVenom.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <rev/CANSparkMax.h>
#include <rev/CANSparkLowLevel.h>
#include <rev/CANSparkBase.h>
#include <rev/SparkRelativeEncoder.h>
//#include "rev/Rev2mDistanceSensor.h"

#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/SPI.h>
#include <AHRS.h>

#include <frc/geometry/Rotation2d.h>

#include <frc/drive/DifferentialDrive.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>


#include "Constants.h"

class Intake : public frc2::SubsystemBase {
    public: 
        Intake();
        void setIntakeMotor(double);
        void stop();
        double getDistance();
        void Periodic() override;

    private: 
        ctre::phoenix::motorcontrol::can::WPI_VictorSPX IntakeMotor{intake::kIntakeTalonPort};
        //rev::Rev2mDistanceSensor distSensor{rev::Rev2mDistanceSensor::Port::kOnboard, rev::Rev2mDistanceSensor::DistanceUnit::kMilliMeters};
};