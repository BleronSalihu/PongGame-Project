#include "pch.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"

namespace Messerli::PongCore::BL::Data::Collision {

BallCollisionData::BallCollisionData(CPoint center, BL::Position::Type::Direction direction)
    : AbstractCollisionData(), AbstractType(GameElement::Ball), Center(center), Direction(direction)
{
}

auto BallCollisionData::GetElement() -> GameElement
{
    return Element;
}

}