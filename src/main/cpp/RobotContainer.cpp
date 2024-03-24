// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <pathplanner/lib/auto/NamedCommands.h>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <pathplanner/lib/util/ReplanningConfig.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <iostream>


#include <frc/shuffleboard/Shuffleboard.h>

#include <memory>

using namespace pathplanner;


RobotContainer::RobotContainer() : m_drivetrain(), m_arm(), m_shooter(), m_intake(), m_vision() {
  // Initialize all of your commands and subsystems here
  // Configure the button bindings
  
  NamedCommands::registerCommand("Intake Note", std::move(IntakeNote(&m_intake)).ToPtr());
  NamedCommands::registerCommand("Shoot Note", std::move(SendNote(&m_intake, &m_shooter)).ToPtr());
  NamedCommands::registerCommand("Arm Down", std::move(MoveArmAngle(&m_arm, 0).ToPtr()));
  NamedCommands::registerCommand("Reset Arm Encoder", std::move(ResetArmEncoder(&m_arm).ToPtr()));
  NamedCommands::registerCommand("Reset Gyro", std::move(ResetGyro(&m_drivetrain).ToPtr()));
  NamedCommands::registerCommand("Reset Drive Encoders", std::move(ResetDriveEncoders(&m_drivetrain).ToPtr()));


  ConfigureButtonBindings();
  // need lambda function to capture the value of the double function for continuous data getting 
  m_drivetrain.SetDefaultCommand(ArcadeDrive(&m_drivetrain, [this] { return -m_joystick.GetY(); }, [this] { return m_joystick.GetX(); }, [this] { return m_joystick.GetThrottle(); }));
  // Configure the button bindings

    
}

void RobotContainer::ConfigureButtonBindings() {
  //drivetrain
  frc2::JoystickButton flip(&m_joystick, 8);
  flip.OnTrue(new FlipDrivetrain(&m_drivetrain));
  frc2::JoystickButton turnAmp(&m_joystick, 7);
  turnAmp.WhileTrue(new TurnDegrees(&m_drivetrain, -90));
  //Intake
  frc2::JoystickButton Intake(&m_joystick, 1);
  Intake.WhileTrue(new IntakeNote(&m_intake));

  //Outtake
  frc2::JoystickButton Outtake(&m_joystickArm, 2);
  Outtake.WhileTrue(new OuttakeNote(&m_intake, &m_shooter));



  //Shooter
  frc2::JoystickButton Shooter(&m_joystickArm, 1);
  // Shooter.WhileTrue(new ShootNote(&m_shooter));
  Shooter.WhileTrue(new SendNote(&m_intake, &m_shooter));
  frc2::JoystickButton AmpShooter(&m_joystickArm, 10);
  AmpShooter.WhileTrue(new ScoreAmp(&m_intake, &m_shooter));

  //Arm Manual UNTESTED
  frc2::JoystickButton armDown(&m_joystickArm, 3);
  armDown.WhileTrue(new MoveArm(&m_arm, true, 0.5)); 
  frc2::JoystickButton armUp(&m_joystickArm, 5);
  armUp.WhileTrue(new MoveArm(&m_arm, false, 0.5));
  frc2::JoystickButton resetEncoder(&m_joystickArm, 12);
  resetEncoder.WhileTrue(new ResetArmEncoder(&m_arm));

  frc2::JoystickButton maintainArm(&m_joystickArm, 8);
  maintainArm.WhileTrue(new MaintainArm(&m_arm));
  // Alignment

  
  // frc2::JoystickButton alignArm(&m_joystick, 7);
  // alignArm.WhileTrue(new AlignArm(&m_arm, &m_vision));
  //frc2::JoystickButton alignDT(&m_joystick, 11);
  //alignDT.WhileTrue(new AlignDrivetrain(&m_drivetrain, &m_vision));
  //frc2::JoystickButton alignAmp(&m_joystickArm, 6);
  //alignAmp.WhileTrue(new MoveArmAngle(&m_arm, 96));
  //frc2::JoystickButton alignIntake(&m_joystickArm, 4);
  //alignIntake.WhileTrue(new MoveArmAngle(&m_arm, 0));
  //frc2::JoystickButton alignStart(&m_joystickArm, 9);
  //alignStart.WhileTrue(new MoveArmAngle(&m_arm, 70)); // change value


  m_chooser.SetDefaultOption("Slow Auto", &m_slowauto);
  m_chooser.AddOption("Preloaded", &m_preloaded);
  m_chooser.AddOption("Preloaded Mobility", &m_preloadedmobility);
  m_chooser.AddOption("Two Piece Auto - Center", &m_twonotecenter);
  // m_chooser.AddOption("Amp Auton", &m_ampauto);
  // m_chooser.AddOption("Two Piece Auto - Right", &m_twopieceR);
  // m_chooser.AddOption("Three Piece Auto - Center", &m_threepiece);

  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);
}

/*
frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}
*/

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}