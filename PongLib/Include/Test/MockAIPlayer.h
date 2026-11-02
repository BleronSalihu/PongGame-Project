#pragma once
#include "PongCore/BL/GameLoop/Tool/AbstractAIPlayer.h"

namespace Messerli::PongCore::Test {

class MockAIPlayer : public BL::GameLoop::Tool::AbstractAIPlayer {
public:
    MockAIPlayer();
    auto Move(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void override;
private:
    void UpdatePlayer(BL::Data::Position::AbstractMoveData* moveData, int targetY, int paddleCenterY, const BL::Data::PongDoc& doc) const;
};

}