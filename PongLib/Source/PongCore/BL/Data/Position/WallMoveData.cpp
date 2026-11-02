#include "pch.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"

namespace Messerli::PongCore::BL::Data::Position {

WallMoveData::WallMoveData(double fieldWidth, double fieldHeight)
    : AbstractMoveData(), AbstractType(GameElement::Wall), FieldHeight(fieldHeight), FieldWidth(fieldWidth)
{
}

auto WallMoveData::GetElement() const -> GameElement
{
    return Element;
}

}