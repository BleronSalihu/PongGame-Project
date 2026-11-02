#include "pch.h"
#include "PongCore/BL/Data/Paint/BallViewData.h"

namespace Messerli::PongCore::BL::Data::Paint {

BallViewData::BallViewData(COLORREF color, CPoint center, int size)
    : AbstractViewData(), AbstractType(GameElement::Ball)
{
    Center = center;
    Color = color;
    Size = size;
}

auto BallViewData::GetElement() -> GameElement
{
    return Element;
}

}