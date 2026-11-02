#include "pch.h"
#include "PongCore/BL/Data/Collision/WallCollisionData.h"

namespace Messerli::PongCore::BL::Data::Collision {

WallCollisionData::WallCollisionData(int fieldWidth, int fieldHeight, CPoint pos1, CPoint pos2)
    : AbstractCollisionData(), AbstractType(GameElement::Wall), Pos1(pos1), Pos2(pos2)
{
    FieldHeight = fieldHeight;
    FieldWidth = fieldWidth;
}

auto WallCollisionData::GetElement() -> GameElement
{
    return Element;
}

}