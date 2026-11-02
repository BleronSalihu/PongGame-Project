#pragma once
#include "AbstractPosition.h"

namespace Messerli::PongCore::BL::Position {

class ObstaclePosition : public AbstractPosition {
public:
    auto CalculatePosition(const Data::Position::AbstractMoveData& obj) -> std::unique_ptr<Data::Position::AbstractMoveData> override;
};

}