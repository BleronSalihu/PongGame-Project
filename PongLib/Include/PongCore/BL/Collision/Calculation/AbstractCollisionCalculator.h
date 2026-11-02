#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/Collision/AbstractCollisionData.h"
#include "PongCore/BL/Collision/Type/CollisionPair.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

class PONGCORE_API AbstractCollisionCalculator abstract {
public:
    virtual auto CalculateCollision(const Type::CollisionPair& pair) -> std::unique_ptr<Data::Collision::AbstractCollisionData> abstract;
};

}