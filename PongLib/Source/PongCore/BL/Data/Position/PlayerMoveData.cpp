#include "pch.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"

namespace Messerli::PongCore::BL::Data::Position {

PlayerMoveData::PlayerMoveData(CPoint pos1, CPoint pos2, int speed, BL::Position::Type::Direction direction, int size)
    : AbstractMoveData(), AbstractType(GameElement::Player), Direction(direction)
{
    Pos1 = pos1;
    Pos2 = pos2;
    Speed = speed;
    Size = size;
}

auto PlayerMoveData::GetElement() const -> GameElement
{
    return Element;
}

}