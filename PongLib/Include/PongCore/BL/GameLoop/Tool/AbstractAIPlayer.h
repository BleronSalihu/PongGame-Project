#pragma once
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Data/PongDoc.h"
#include <vector>

namespace Messerli::PongCore::BL::GameLoop::Tool {

class AbstractAIPlayer {
public:
    virtual auto Move(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel, Data::PongDoc& doc) -> void abstract;
};

}