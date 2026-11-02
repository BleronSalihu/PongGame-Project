#include "pch.h"
#include "PongCore/BL/Collision/Calculation/CalculationModule.h"
#include "PongCore/BL/Collision/Calculation/CollisionCalculatorFactory.h"
#include "PongCore/UI/Data/GameReflectation.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

auto CalculationModule::CalculateCollision(const std::vector<Type::CollisionPair>& collisionModel, UI::Data::GameReflectation reflectation) -> std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>>
{
    std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>> tempCollisionModel;
    for (let& obj : collisionModel) {
        let calculator = Calculation::CollisionCalculatorFactory::Create(obj, reflectation);
        tempCollisionModel.push_back(std::move(calculator->CalculateCollision(obj)));
    }
    return tempCollisionModel;
}


}