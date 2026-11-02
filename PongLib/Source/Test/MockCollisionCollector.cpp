#include "pch.h"
#include "Test/MockCollisionCollector.h"

namespace Messerli::PongCore::Test {

MockCollisionCollector::MockCollisionCollector(const PongCore::BL::Data::Position::BallMoveData& ball, const PongCore::BL::Data::Position::PlayerMoveData& paddle)
    : m_ball(&ball), m_paddle(&paddle)
{}

auto MockCollisionCollector::ConvertCollision(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModelfirstPosition,
    const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModelEndPosition)->std::vector<BL::Collision::Type::CollisionPair>&
{
    std::vector<PongCore::BL::Collision::Type::CollisionPair> pairs;
    pairs.push_back(PongCore::BL::Collision::Type::CollisionPair{
        *m_ball,
        *m_ball,
        PongCore::BL::Collision::Type::CollisionType::Reflection,
        *m_paddle,
        *m_paddle,
        PongCore::BL::Collision::Type::CollisionType::Standstill
        });
    return pairs;
}

//auto MockCollisionCollector::SetObjects(const PongCore::BL::Data::Position::BallMoveData& ball, const PongCore::BL::Data::Position::PlayerMoveData& paddle) -> void
//{
//    m_ball = &ball;
//    m_paddle = &paddle;
//}

}