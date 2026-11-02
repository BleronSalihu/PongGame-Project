#pragma once
#include "PongCore/BL/Data/Position/AbstractMoveData.h"

namespace Messerli::PongCore::BL::Position {

class PositionModule {
public:
    auto CalculatePosition(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModell) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>;
};

}