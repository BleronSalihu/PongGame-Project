#include "pch.h"
#include "PongCore/BL/Position/WallPosition.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"

namespace Messerli::PongCore::BL::Position {

auto WallPosition::CalculatePosition(const Data::Position::AbstractMoveData& obj)->std::unique_ptr<Data::Position::AbstractMoveData>
{
    let& wall = dynamic_cast<const Data::Position::WallMoveData&>(obj);
    return std::make_unique<Data::Position::WallMoveData>(wall.FieldWidth, wall.FieldHeight);
}

}