#pragma once
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::BL::Data::Tool {

struct BallDoc {
    int BallSpeed = 0;
    int BallSize = 0;
    COLORREF BallColor {RGB(100, 100, 100)};
    BL::Position::Type::Direction BallDirection = BL::Position::Type::Direction(90);
};

}