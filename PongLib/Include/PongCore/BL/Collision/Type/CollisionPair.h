#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "CollisionType.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"

namespace Messerli::PongCore::BL::Collision::Type {

namespace {

using ActiveGameElement = const Data::Position::AbstractMoveData&;
using PassiveGameElement = const Data::Position::AbstractMoveData&;

}

struct PONGCORE_API CollisionPair {
    ActiveGameElement AFirstPosition;
    ActiveGameElement AEndPosition;
    CollisionType ActiveType;
    PassiveGameElement PFirstPosition;
    PassiveGameElement PEndPosition;
    CollisionType PassiveType;
};

}