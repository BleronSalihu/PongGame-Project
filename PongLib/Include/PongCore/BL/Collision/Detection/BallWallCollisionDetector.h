#pragma once
#include "AbstractCollisionDetector.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class BallWallCollisionDetector : public AbstractCollisionDetector {
public:
    auto IsCollision(const Type::CollisionPair& pair) -> bool override;
};

}