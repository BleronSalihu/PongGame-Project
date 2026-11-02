#pragma once
#include "AbstractCalculationModule.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

class CalculationModule : public AbstractCalculationModule {
public:
    auto CalculateCollision(const std::vector<Type::CollisionPair>& collisionModel, UI::Data::GameReflectation reflectation) -> std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>> override;
};

}