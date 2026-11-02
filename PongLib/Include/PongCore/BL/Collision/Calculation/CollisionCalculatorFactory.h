#pragma once
#include "PongCore/BL/Collision/Calculation/AbstractCollisionCalculator.h"
#include "PongCore/BL/Collision/Type/CollisionPair.h"
#include "PongCore/UI/Data/GameReflectation.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

class CollisionCalculatorFactory {
public:
    static auto Create(Type::CollisionPair pair, UI::Data::GameReflectation reflectation) -> std::unique_ptr<AbstractCollisionCalculator>;
};
}