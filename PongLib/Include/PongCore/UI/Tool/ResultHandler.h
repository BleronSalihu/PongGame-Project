#pragma once
#include "AbstractResultHandler.h"

namespace Messerli::PongCore::UI::Tool {

class ResultHandler : public AbstractResultHandler {
public:
    auto HandleResult(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void override;
private:
    auto ResetBall(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void override;
};

}