#pragma once
#include "PongCore/BL/Collision/Type/CollisionPair.h"
#include "PongCore/BL/Data/Collision/AbstractCollisionData.h"
#include "PongCore/UI/Data/GameReflectation.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

class AbstractCalculationModule {
public:
    virtual auto CalculateCollision(const std::vector<Type::CollisionPair>& collisionModel, UI::Data::GameReflectation reflectation) -> std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>> abstract;
};

}