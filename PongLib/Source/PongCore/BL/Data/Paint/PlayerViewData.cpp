#include "pch.h"
#include "PongCore/BL/Data/Paint/PlayerViewData.h"

namespace Messerli::PongCore::BL::Data::Paint {

PlayerViewData::PlayerViewData(COLORREF color, CPoint pos1, CPoint pos2, int size)
    : AbstractViewData(), AbstractType(GameElement::Player)
{
    Pos1 = pos1;
    Pos2 = pos2;
    Color = color;
    Size = size;
}

auto PlayerViewData::GetElement() -> GameElement
{
    return Element;
}

}