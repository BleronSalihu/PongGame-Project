#include "pch.h"
#include "PongCore/BL/Data/Paint/ObstacleViewData.h"

namespace Messerli::PongCore::BL::Data::Paint {

ObstacleViewData::ObstacleViewData(CRect rect)
    : AbstractViewData(), AbstractType(GameElement::Obstacle), Rect(rect)
{}

auto ObstacleViewData::GetElement() -> GameElement {
    return Element;
}

}