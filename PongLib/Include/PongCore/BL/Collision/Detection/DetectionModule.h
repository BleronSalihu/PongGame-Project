#pragma once
#include "AbstractDetectionModule.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class DetectionModule : public AbstractDetectionModule {
public:
    auto IsCollision(const std::vector<Type::CollisionPair>& collisionModel) -> std::vector<Type::CollisionPair> override;
};

}