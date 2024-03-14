// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <CANVenom.h>

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

#include <frc/apriltag/AprilTagFieldLayout.h>
#include <frc/apriltag/AprilTagFields.h>


#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableValue.h>

#include <photon/PhotonCamera.h>

#include "Constants.h"

class Vision : public frc2::SubsystemBase {
    public: 
        Vision();
        
        double getHorizontalOffset();

        double getVerticalOffset();

        double getArea();

        double getSkew();

        double getDistance();

        double getPitch();

        bool hasValidTargetPose2d();

        /**
         * Will be called periodically whenever the CommandScheduler runs.
         */
        void Periodic() override;
    private: 
        std::shared_ptr<nt::NetworkTable> limelightTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
        frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("SmartDashboard");
        frc::AprilTagFieldLayout aprilTagFieldLayout = frc::LoadAprilTagLayoutField(frc::AprilTagField::k2024Crescendo);
};