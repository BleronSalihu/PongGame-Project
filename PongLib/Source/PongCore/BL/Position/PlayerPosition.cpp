#include "pch.h"
#include "PongCore/BL/Position/PlayerPosition.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"

namespace Messerli::PongCore::BL::Position {

namespace {

auto GetCast(const Data::Position::AbstractMoveData& obj) -> Data::Position::PlayerMoveData
{
    return *dynamic_cast<const Data::Position::PlayerMoveData*>(&obj);
}

}

auto PlayerPosition::CalculatePosition(const Data::Position::AbstractMoveData& obj) -> std::unique_ptr<Data::Position::AbstractMoveData>
{
    let radian = GetCast(obj).Direction.ToRadian();
    let forwardX = static_cast<int>(GetCast(obj).Speed * cos(radian));
    let forwardY = static_cast<int>(GetCast(obj).Speed * sin(radian));
    CPoint newPos1(GetCast(obj).Pos1.x + forwardX, GetCast(obj).Pos1.y + forwardY);
    CPoint newPos2(GetCast(obj).Pos2.x + forwardX, GetCast(obj).Pos2.y + forwardY);
    auto newPlayerMove = std::make_unique<Data::Position::PlayerMoveData>(newPos1, newPos2, GetCast(obj).Speed, GetCast(obj).Direction, GetCast(obj).Size);
    return std::move(newPlayerMove);
}

}