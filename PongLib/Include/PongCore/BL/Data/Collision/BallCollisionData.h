#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "AbstractCollisionData.h"
#include "PongCore/BL/Data/AbstractType.h"

namespace Messerli::PongCore::BL::Data::Collision {

struct PONGCORE_API BallCollisionData : public AbstractCollisionData, public AbstractType {
    BallCollisionData(CPoint center, BL::Position::Type::Direction direction);
    CPoint Center;
    BL::Position::Type::Direction Direction;
    auto GetElement() -> GameElement override;
};

}