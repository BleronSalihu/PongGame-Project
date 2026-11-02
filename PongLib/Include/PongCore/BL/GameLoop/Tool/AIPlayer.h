#pragma once
#include "AbstractAIPlayer.h"

namespace Messerli::PongCore::BL::GameLoop::Tool {

class AIPlayer : public AbstractAIPlayer {
public:
    auto Move(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel, Data::PongDoc& doc) -> void override;
};

}