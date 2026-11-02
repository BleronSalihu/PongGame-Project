#pragma once
#include "PongCore/BL/Collision/Type/CollisionPair.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class AbstractDetectionModule {
public:
    virtual auto IsCollision(const std::vector<Type::CollisionPair>& collisionModel) -> std::vector<Type::CollisionPair> abstract;
};

}