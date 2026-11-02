#pragma once
#include "AbstractCollisionDetector.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class PONGCORE_API BallPaddleCollisionDetector : public AbstractCollisionDetector {
public:
    auto IsCollision(const Type::CollisionPair& pair) -> bool override;
};

}