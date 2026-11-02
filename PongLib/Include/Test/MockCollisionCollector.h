#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Collision/Tool/AbstractCollisionCollector.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"

namespace Messerli::PongCore::Test {

class PONGCORE_API MockCollisionCollector : public BL::Collision::Tool::AbstractCollisionCollector {
public:
    MockCollisionCollector(const BL::Data::Position::BallMoveData& ball, const BL::Data::Position::PlayerMoveData& paddle);
    auto ConvertCollision(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModelfirstPosition,
        const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModelEndPosition) -> std::vector<BL::Collision::Type::CollisionPair> & override;
    //auto SetObjects(const BL::Data::Position::BallMoveData& ball, const BL::Data::Position::PlayerMoveData& paddle) -> void;
private:
    const PongCore::BL::Data::Position::AbstractMoveData* m_ball{};
    const PongCore::BL::Data::Position::AbstractMoveData* m_paddle{};
};

}