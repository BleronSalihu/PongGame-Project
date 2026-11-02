#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "AbstractMoveData.h"
#include "PongCore/BL/Data/AbstractType.h"
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::BL::Data::Position {

struct PONGCORE_API PlayerMoveData : public AbstractMoveData, public AbstractType {
    PlayerMoveData(CPoint pos1, CPoint pos2, int speed, BL::Position::Type::Direction direction, int size);
    CPoint Pos1 {};
    CPoint Pos2 {};
    int Size = 0;
    BL::Position::Type::Direction Direction;
    auto GetElement() const->GameElement override;
};

}