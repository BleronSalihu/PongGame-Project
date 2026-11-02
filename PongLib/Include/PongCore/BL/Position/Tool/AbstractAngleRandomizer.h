#pragma once

namespace Messerli::PongCore::BL::Position::Tool {

class AbstractAngleRandomizer {
public:
    virtual auto GetRandomAngle() -> double abstract;
};

}