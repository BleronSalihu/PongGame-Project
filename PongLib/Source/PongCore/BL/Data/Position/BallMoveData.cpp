#include "pch.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"

namespace Messerli::PongCore::BL::Data::Position {

BallMoveData::BallMoveData(CPoint center, int speed, BL::Position::Type::Direction angle, int size)
    : AbstractMoveData(), AbstractType(GameElement::Ball), Direction(angle), Size(size)
{
    Center = center;
    Speed = speed;
}

auto BallMoveData::GetElement() const -> GameElement
{
    return Element;
}

}