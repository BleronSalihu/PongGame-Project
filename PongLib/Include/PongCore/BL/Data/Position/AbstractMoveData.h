#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/GameElements.h"

namespace Messerli::PongCore::BL::Data::Position {

struct PONGCORE_API AbstractMoveData {
    int Speed = 0;
    virtual ~AbstractMoveData() = default;
    virtual auto GetElement() const->GameElement abstract;
};

}