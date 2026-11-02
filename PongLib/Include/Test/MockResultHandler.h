#pragma once
#include "PongCore/UI/Tool/AbstractResultHandler.h"

namespace Messerli::PongCore::Test {

class MockResultHandler : public UI::Tool::AbstractResultHandler {
public:
    MockResultHandler();
    auto HandleResult(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void override;
private:
    auto ResetBall(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void override;
};

}