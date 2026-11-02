#include "pch.h"
#include "PongCore/BL/Position/BallPosition.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"

namespace Messerli::PongCore::BL::Position {

namespace {

auto GetCast(const Data::Position::AbstractMoveData& obj) -> Data::Position::BallMoveData
{
    return *dynamic_cast<const Data::Position::BallMoveData*>(&obj);
}


}

auto BallPosition::CalculatePosition(const Data::Position::AbstractMoveData& obj) -> std::unique_ptr<Data::Position::AbstractMoveData>
{
    let radian = GetCast(obj).Direction.ToRadian();
    let forwardX = static_cast<int>(GetCast(obj).Speed * cos(radian));
    let forwardY = static_cast<int>(GetCast(obj).Speed * sin(radian));
    CPoint newCenter(GetCast(obj).Center.x + forwardX, GetCast(obj).Center.y + forwardY);
    auto newBallMove = std::make_unique<Data::Position::BallMoveData>(newCenter, GetCast(obj).Speed, GetCast(obj).Direction, GetCast(obj).Size);
    return std::move(newBallMove);
}

}