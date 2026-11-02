#pragma once
#include "PongCore/BL/Collision/Detection/AbstractCollisionDetector.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class BallObstacleCollisionDetector : public AbstractCollisionDetector {
public:
    auto IsCollision(const Type::CollisionPair& pair) -> bool override;
};

}