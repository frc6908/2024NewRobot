#include "commands/AlignArm.h"

AlignArm::AlignArm(Arm* arm, Vision* vision) : m_arm{arm}, m_vision{vision} {
    AddRequirements(arm);
}

void AlignArm::Initialize() {
    this->m_arm->stop();
}

void AlignArm::Execute() {
    photon::PhotonPipelineResult res = this->m_vision->getResult();
    double rotation_speed = 0;
    if(res.HasTargets()) {
        rotation_speed = this->m_arm->PIDCalculate(res.GetBestTarget().GetPitch()); // replace the interior of the method with data-derived function
    }
    this->m_arm->setArmMotors(rotation_speed);
}

void AlignArm::End(bool interrupted) {
    this->m_arm->stop();
}

bool AlignArm::IsFinished() {
    return this->m_arm->PIDfinished();
}