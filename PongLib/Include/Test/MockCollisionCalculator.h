#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Collision/Calculation/AbstractCalculationModule.h"
#include "PongCore/BL/Data/Collision/AbstractCollisionData.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"
#include "PongCore/BL/Collision/Type/CollisionPair.h"
#include "PongCore/UI/Data/GameReflectation.h"

namespace Messerli::PongCore::Test {

class PONGCORE_API MockCollisionCalculator : public BL::Collision::Calculation::AbstractCalculationModule {
public:
    std::vector<std::unique_ptr<PongCore::BL::Data::Collision::AbstractCollisionData>> CalculateCollision(const std::vector<PongCore::BL::Collision::Type::CollisionPair>&, PongCore::UI::Data::GameReflectation) override;
};

}