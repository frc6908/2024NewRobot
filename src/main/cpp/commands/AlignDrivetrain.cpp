#include "commands/AlignDrivetrain.h"

AlignDrivetrain::AlignDrivetrain(Drivetrain* drivetrain, Vision* vision) : m_drivetrain{drivetrain}, m_vision{vision} {
    pid.SetTolerance(2);
    AddRequirements(drivetrain);
}

void AlignDrivetrain::Initialize() {
    this->m_drivetrain->stop();
}

void AlignDrivetrain::Execute() {
    double yaw = this->m_drivetrain->getHeadingAsAngle() + this->m_vision->getHorizontalOffset();
    bool flipped = this->m_drivetrain->isFlipped();
    double rotation_speed = 0;
    if(this->m_vision->hasValidTargetPose2d()) {
        rotation_speed = (flipped ? 1 : -1) * pid.Calculate(this->m_drivetrain->getHeadingAsAngle(), yaw); // adjust values as needed.
    }
    else {
        rotation_speed = 0.2;
    }
    frc::SmartDashboard::PutNumber("Rotation Speed", rotation_speed);
    this->m_drivetrain->arcadeDrive(0, rotation_speed);
}
 
void AlignDrivetrain::End(bool interrupted) {
    this->m_drivetrain->stop();
}

bool AlignDrivetrain::IsFinished() {
    return pid.AtSetpoint();
}