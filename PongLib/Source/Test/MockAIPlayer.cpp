#include "pch.h"
#include "Test/MockAIPlayer.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::Test {

MockAIPlayer::MockAIPlayer() = default;

auto MockAIPlayer::Move(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void
{
    const int fixedPredictedBallY = 120;
    const int fixedPaddleCenterY = 150;

    if (moveModel.size() > 1) {
        UpdatePlayer(moveModel[1].get(), fixedPredictedBallY, fixedPaddleCenterY, doc);
    }
}

void MockAIPlayer::UpdatePlayer(BL::Data::Position::AbstractMoveData* moveData, int targetY, int paddleCenterY, const BL::Data::PongDoc& doc) const 
{
    auto* playerMove = dynamic_cast<BL::Data::Position::PlayerMoveData*>(moveData);
    if (!playerMove) {
        return;
    }

    if (targetY > paddleCenterY) {
        playerMove->Direction = BL::Position::Type::Direction(90.0);
        playerMove->Speed = doc.DefaultValues->Player1Speed;
    }
    else if (targetY < paddleCenterY) {
        playerMove->Direction = BL::Position::Type::Direction(270.0);
        playerMove->Speed = doc.DefaultValues->Player1Speed;
    }
    else {
        playerMove->Speed = 0;
    }
}

}