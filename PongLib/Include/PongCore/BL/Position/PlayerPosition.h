#pragma once
#include "AbstractPosition.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"

namespace Messerli::PongCore::BL::Position {

class PlayerPosition : public AbstractPosition {
public:
    auto CalculatePosition(const Data::Position::AbstractMoveData& obj) -> std::unique_ptr<Data::Position::AbstractMoveData> override;
};

}