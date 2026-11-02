#pragma once
#include "AbstractCollisionCalculator.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

class BallPaddleCollisionCalculator : public AbstractCollisionCalculator {
public:
    auto CalculateCollision(const Type::CollisionPair& pair) -> std::unique_ptr<Data::Collision::AbstractCollisionData> override;
};

}