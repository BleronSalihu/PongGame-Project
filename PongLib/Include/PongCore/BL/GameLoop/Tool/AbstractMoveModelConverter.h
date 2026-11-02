#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/PongDoc.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Data/Paint/AbstractViewData.h"
#include <vector>
#include <memory>

namespace Messerli::PongCore::BL::GameLoop::Tool {

class PONGCORE_API AbstractMoveModelConverter {
public:
    virtual auto ConvertMove(Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> abstract;
};

}