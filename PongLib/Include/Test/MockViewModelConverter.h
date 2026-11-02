#pragma once
#include "PongCore/BL/GameLoop/Tool/AbstractViewModelConverter.h"

namespace Messerli::PongCore::Test {

class MockViewModelConverter : public BL::GameLoop::Tool::AbstractViewModelConverter {
public:
    MockViewModelConverter();
    auto ConvertView(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& positions, BL::Data::PongDoc& doc) -> std::vector<std::unique_ptr<BL::Data::Paint::AbstractViewData>> override;
private:

};

}