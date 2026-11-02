#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Position/Tool/AbstractAngleRandomizer.h"

namespace Messerli::PongCore::Test {

class PONGCORE_API MockAngleRandomizer : public BL::Position::Tool::AbstractAngleRandomizer {
public:
    MockAngleRandomizer(double angle);
    auto GetRandomAngle() -> double override;
private:
    double m_angle = 0.0;
};

}