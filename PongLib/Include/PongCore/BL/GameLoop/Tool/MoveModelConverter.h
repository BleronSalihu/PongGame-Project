#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "AbstractMoveModelConverter.h"

namespace Messerli::PongCore::BL::GameLoop::Tool {

class PONGCORE_API MoveModelConverter : public AbstractMoveModelConverter {
public:
    auto ConvertMove(Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> override;
};

}