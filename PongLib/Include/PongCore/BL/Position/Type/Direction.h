#pragma once
#include "PongCore/BL/PongCore_API.h"

namespace Messerli::PongCore::BL::Position::Type {

struct PONGCORE_API Direction {
    Direction(double angle);
    auto GetAngle() const -> double;
    auto SetAngle(double newAngle) -> void;
    auto ToRadian() -> double;
private:
    double m_angle = 0.0;
};

}