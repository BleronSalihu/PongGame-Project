#pragma once
#include "PongCore/BL/Data/GameElements.h"
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::BL::Data::Collision {

struct AbstractCollisionData {
    virtual auto GetElement() -> GameElement abstract;
    virtual ~AbstractCollisionData() = default;
};

}