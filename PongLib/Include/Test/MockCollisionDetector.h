#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Collision/Detection/AbstractDetectionModule.h"
#include "PongCore/BL/Collision/Detection/AbstractCollisionDetector.h"

namespace Messerli::PongCore::Test {

class PONGCORE_API MockCollisionDetector : public BL::Collision::Detection::AbstractDetectionModule {
public:
    auto IsCollision(const std::vector<PongCore::BL::Collision::Type::CollisionPair>& pairs) -> std::vector<PongCore::BL::Collision::Type::CollisionPair> override;
};

}