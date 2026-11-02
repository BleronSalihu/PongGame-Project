#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Collision/Type/CollisionPair.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class PONGCORE_API AbstractCollisionDetector {
public:
    virtual auto IsCollision(const Type::CollisionPair& pair) -> bool abstract;
};

}
