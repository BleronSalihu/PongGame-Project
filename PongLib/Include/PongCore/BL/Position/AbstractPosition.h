#pragma once
#include "PongCore/BL/Data/Position/AbstractMoveData.h"

namespace Messerli::PongCore::BL::Position {

class AbstractPosition abstract {
public:
    virtual auto CalculatePosition(const Data::Position::AbstractMoveData& obj) -> std::unique_ptr<Data::Position::AbstractMoveData> abstract;
};

}