#include "pch.h"
#include "PongCore/BL/Data/Collision/PlayerCollisionData.h"

namespace Messerli::PongCore::BL::Data::Collision {

PlayerCollisionData::PlayerCollisionData(CPoint pos1, CPoint pos2)
    : AbstractCollisionData(), AbstractType(GameElement::Player), Pos1(pos1), Pos2(pos2)
{
}

auto PlayerCollisionData::GetElement() -> GameElement
{
    return Element;
}

}