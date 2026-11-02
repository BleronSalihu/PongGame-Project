#pragma once
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::BL::Data::Tool {

struct PlayerDoc {
    int PlayerSize = 0;
    int PlayerSpeed = 0;
    int PlayerScore = 0;
    COLORREF PlayerColor {RGB(100, 100, 100)};
    BL::Position::Type::Direction PlayerDirection = BL::Position::Type::Direction(90);
};

}