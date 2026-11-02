#include "pch.h"
#include "Test/MockCollisionCalculator.h"

namespace Messerli::PongCore::Test
{
    std::vector<std::unique_ptr<PongCore::BL::Data::Collision::AbstractCollisionData>> MockCollisionCalculator::CalculateCollision(const std::vector<PongCore::BL::Collision::Type::CollisionPair>&, PongCore::UI::Data::GameReflectation)
    {
        std::vector<std::unique_ptr<PongCore::BL::Data::Collision::AbstractCollisionData>> result;
        result.push_back(std::make_unique<PongCore::BL::Data::Collision::BallCollisionData>(
            CPoint(50, 50),
            PongCore::BL::Position::Type::Direction(90.0)
        ));
        return result;
    }

}