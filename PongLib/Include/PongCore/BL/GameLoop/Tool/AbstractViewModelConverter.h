#pragma once
#include "PongCore/BL/Data/PongDoc.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Data/Paint/AbstractViewData.h"
#include <vector>
#include <memory>

namespace Messerli::PongCore::BL::GameLoop::Tool {

class AbstractViewModelConverter {
public:
    virtual auto ConvertView(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& positions, Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Paint::AbstractViewData>> abstract;
};

}