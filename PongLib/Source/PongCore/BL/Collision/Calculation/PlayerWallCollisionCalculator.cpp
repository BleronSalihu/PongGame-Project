#include "pch.h"
#include "PongCore/BL/Collision/Calculation/PlayerWallCollisionCalculator.h"
#include "PongCore/BL/Data/Collision/PlayerCollisionData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"

namespace Messerli::PongCore::BL::Collision::Calculation {


namespace {

auto GetPaddle(const Data::Position::AbstractMoveData& ball) -> const Data::Position::PlayerMoveData&
{
    return dynamic_cast<const Data::Position::PlayerMoveData&>(ball);
}

auto GetWall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::WallMoveData&
{
    return dynamic_cast<const Data::Position::WallMoveData&>(ball);
}

}

auto PlayerWallCollisionCalculator::CalculateCollision(const Type::CollisionPair& pair) -> std::unique_ptr<Data::Collision::AbstractCollisionData>
{
    const auto& paddle = GetPaddle(pair.AEndPosition);
    const auto& wall = GetWall(pair.PEndPosition);

    double fieldH = static_cast<double>(wall.FieldHeight);
    double pad = static_cast<double>(paddle.Size);
    double top = static_cast<double>(paddle.Pos1.y);    
    double bot = static_cast<double>(paddle.Pos2.y);

    double newTop = top;
    double newBot = bot;

    if (newTop - pad < 0.0) {
        double corr = pad - newTop;
        newTop += corr;
        newBot += corr;
    }

    if (newBot + pad > fieldH) {
        double corr = (newBot + pad) - fieldH;
        newTop -= corr;
        newBot -= corr;
    }

    return std::make_unique<Data::Collision::PlayerCollisionData>(
        CPoint(paddle.Pos1.x, static_cast<LONG>(std::lround(newTop))),
        CPoint(paddle.Pos2.x, static_cast<LONG>(std::lround(newBot)))
    );
}

}