#include "pch.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"

namespace Messerli::PongCore::BL::Data::Position
{

ObstacleMoveData::ObstacleMoveData(CPoint center, int size)
    : AbstractType(GameElement::Obstacle), AbstractMoveData(), Center(center), Size(size)
{}

auto ObstacleMoveData::GetElement() const -> GameElement
{
    return Element;

}

}