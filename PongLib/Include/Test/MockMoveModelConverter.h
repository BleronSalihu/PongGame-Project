#pragma once
#include "PongCore/BL/GameLoop/Tool/AbstractMoveModelConverter.h"

namespace Messerli::PongCore::Test {

class MockMoveModelConverter : public BL::GameLoop::Tool::AbstractMoveModelConverter {
public:
    MockMoveModelConverter();
    auto ConvertMove(BL::Data::PongDoc& doc) -> std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>> override;
private:
};

}