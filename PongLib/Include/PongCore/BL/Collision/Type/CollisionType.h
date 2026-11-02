#pragma once
#include "PongCore/BL/Data/GameElements.h"

namespace Messerli::PongCore::BL::Collision::Type {

enum class CollisionType {
    None,
    Reflection,
    Standstill
};

}