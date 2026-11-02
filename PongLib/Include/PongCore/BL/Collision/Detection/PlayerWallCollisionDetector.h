#pragma once
#include "PongCore/BL/Collision/Detection/AbstractCollisionDetector.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class PlayerWallCollisionDetector : public AbstractCollisionDetector {
public:
    auto IsCollision(const Type::CollisionPair& pair) -> bool override;
};

}