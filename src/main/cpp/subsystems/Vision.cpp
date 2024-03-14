#include "subsystems/Vision.h"

Vision::Vision() {}

double Vision::getHorizontalOffset() {
  return limelightTable->GetNumber("tx", 6908.0);
}

double Vision::getVerticalOffset() {
  return limelightTable->GetNumber("ty", 6908.0);
}

double Vision::getArea() {
  return limelightTable->GetNumber("ta", 6908.0);
}

double Vision::getSkew() {
  return limelightTable->GetNumber("ts", 6908.0);
}

double Vision::getPitch() {
    return vision::kCameraAngle + getVerticalOffset();
}

double Vision::getDistance() {
  return (vision::kTargetHeight - vision::kCameraHeight) / ( tan( (M_PI / 180) * (vision::kCameraAngle + getVerticalOffset()) ) );
}

bool Vision::hasValidTargetPose2d() {
  if (getArea() == 6908.0) {
    return false;
  }
  if (getDistance() == 6908.0) {
    return false;
  }
  if (getVerticalOffset() == 6908.0) {
    return false;
  }
  if (getHorizontalOffset() == 6908.0) {
    return false;
  }
  if (getSkew() == 6908.0) {
    return false;
  }
  return true;
}


void Vision::Periodic() {
    frc::SmartDashboard::PutNumber("Limelight Horizontal Offset", getHorizontalOffset());
    frc::SmartDashboard::PutNumber("Limelight Vertical Offset", getVerticalOffset());
}