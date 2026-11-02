#include "pch.h"
#include "PongCore/BL/Collision/CollisionModule.h"

namespace Messerli::PongCore::BL::Collision {

CollisionModule::CollisionModule(Tool::AbstractCollisionCollector& collisionCollector, Calculation::AbstractCalculationModule& calculationModule, Detection::AbstractDetectionModule& detectionModule)
    : m_collisionCollector(collisionCollector), m_calculationModule(calculationModule), m_detectionModule(detectionModule)
{}

auto CollisionModule::Calculate(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelFirstPosition,
    const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelEndPosition, 
    UI::Data::GameReflectation reflectation) -> std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>>
{
    let allCollisionPairs = m_collisionCollector.ConvertCollision(moveModelFirstPosition, moveModelEndPosition);
    let currentCollisions = m_detectionModule.IsCollision(allCollisionPairs);
    auto newMovements = m_calculationModule.CalculateCollision(currentCollisions, reflectation);
    return newMovements;
}

}