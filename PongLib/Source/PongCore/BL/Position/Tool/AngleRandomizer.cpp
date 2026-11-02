#include "pch.h"
#include "PongCore/BL/Position/Tool/AngleRandomizer.h"

namespace Messerli::PongCore::BL::Position::Tool {

auto AngleRandomizer::GetRandomAngle() -> double
{
    srand(static_cast<unsigned int>(time(0)));

    int angle = rand() % 361;

    while ((angle >= 85 && angle <= 95) || (angle >= 265 && angle <= 275)) {
        angle = rand() % 361;
    }

    return static_cast<double>(angle);
}

}