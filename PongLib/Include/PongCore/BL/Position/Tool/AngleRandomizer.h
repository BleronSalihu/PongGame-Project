#pragma once
#include "AbstractAngleRandomizer.h"

namespace Messerli::PongCore::BL::Position::Tool {

class AngleRandomizer : public AbstractAngleRandomizer {
public:
    auto GetRandomAngle() -> double override;
};

}