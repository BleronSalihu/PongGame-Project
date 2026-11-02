#pragma once
#include "PongCore/BL/Data/PongDoc.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"

namespace Messerli::PongCore::UI::Tool {

class AbstractResultHandler {
public:
    virtual auto HandleResult(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void abstract;
private:
    virtual auto ResetBall(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void abstract;
};

}