#include "subsystems/Vision.h"

Vision::Vision() {}

photon::PhotonPipelineResult Vision::getResult() {
    return camera.GetLatestResult();
}

void Vision::Periodic() {}