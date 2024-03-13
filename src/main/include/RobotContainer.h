// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc2/command/InstantCommand.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandJoystick.h>
#include <frc2/command/button/JoystickButton.h>

#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"


#include "subsystems/Drivetrain.h"
#include "subsystems/Arm.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Vision.h"


#include "commands/SlowAuto.h"
#include "commands/TwoPiece.h"
#include "commands/Preloaded.h"
#include "commands/AmpAuto.h"
#include "commands/TwoPieceR.h"
#include "commands/ThreePiece.h"


#include "commands/ArcadeDrive.h"
#include "commands/FlipDrivetrain.h"
#include "commands/IntakeNote.h"
#include "commands/MaintainArm.h"
#include "commands/MoveArm.h"
#include "commands/MoveArmAngle.h"
#include "commands/ResetArmEncoder.h"
#include "commands/ShootNote.h"
#include "commands/AlignArm.h"
#include "commands/AlignDrivetrain.h"
#include "commands/ScoreAmp.h"
#include "commands/SendNote.h"
#include "commands/OuttakeNote.h"
#include "commands/TurnDegrees.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  void GetSmartDashboard();
  frc2::Command* GetAutonomousCommand();

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;

  //drivetrain
  Drivetrain m_drivetrain;

  Arm m_arm;

  Shooter m_shooter;

  Intake m_intake;

  

  Vision m_vision;
  //

   // chooser for autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;
  SlowAuto m_slowauto{&m_drivetrain};
  TwoPiece m_twopiece{&m_drivetrain, &m_shooter, &m_arm, &m_intake};
  Preloaded m_preloaded{&m_drivetrain, &m_shooter, &m_arm, &m_intake};
  AmpAuto m_ampauto{&m_drivetrain};
  TwoPieceR m_twopieceR{&m_drivetrain, &m_shooter, &m_arm, &m_intake};
  ThreePiece m_threepiece{&m_drivetrain, &m_shooter, &m_arm, &m_intake};
  

  
  //joystick
  frc::Joystick m_joystick{oi::kDriveJoystickPort};
  frc::Joystick m_joystickArm{oi::kArmJoystickPort};


  void ConfigureButtonBindings();

  
};
