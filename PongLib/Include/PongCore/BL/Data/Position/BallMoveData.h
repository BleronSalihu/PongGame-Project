#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "AbstractMoveData.h"
#include "PongCore/BL/Data/AbstractType.h"
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::BL::Data::Position {

struct PONGCORE_API BallMoveData : public AbstractMoveData, public AbstractType {
    BallMoveData(CPoint center, int speed, BL::Position::Type::Direction angle, int size);
    auto GetElement() const->GameElement override;
    CPoint Center;
    int Size = 0;
    BL::Position::Type::Direction Direction;
};

}