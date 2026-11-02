#include "pch.h"
#include "Test/MockCollisionDetector.h"

namespace Messerli::PongCore::Test {

auto MockCollisionDetector::IsCollision(const std::vector<PongCore::BL::Collision::Type::CollisionPair>& pairs) -> std::vector<PongCore::BL::Collision::Type::CollisionPair>
{
    return pairs;
}

}