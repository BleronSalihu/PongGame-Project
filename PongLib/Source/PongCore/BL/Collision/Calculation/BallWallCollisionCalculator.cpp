#include "pch.h"
#include "PongCore/BL/Collision/Calculation/BallWallCollisionCalculator.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

namespace {

auto GetBall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::BallMoveData&
{
    return dynamic_cast<const Data::Position::BallMoveData&>(ball);
}

auto GetWall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::WallMoveData&
{
    return dynamic_cast<const Data::Position::WallMoveData&>(ball);
}

}

auto BallWallCollisionCalculator::CalculateCollision(const Type::CollisionPair& pair)->std::unique_ptr<Data::Collision::AbstractCollisionData>
{
    let& ballFirstPosition = GetBall(pair.AFirstPosition);
    let& ballEndPosition = GetBall(pair.AEndPosition);
    let& wall = GetWall(pair.PEndPosition);
    
    let ballPosX = static_cast<double>(ballEndPosition.Center.x);
    let ballPosY = static_cast<double>(ballEndPosition.Center.y);
    let ballRadius = static_cast<double>(ballEndPosition.Size);
    
    let wallUpperYPosition = 0.0;
    let wallLowerYPosition = static_cast<double>(wall.FieldHeight);

    auto newBallPosY = ballPosY;
    BL::Position::Type::Direction newDirection = ballEndPosition.Direction;

    if (ballPosY - ballRadius < wallUpperYPosition) {
        newBallPosY = wallUpperYPosition + ballRadius;
        newDirection = -newDirection.GetAngle();
    }

    if (ballPosY + ballRadius > wallLowerYPosition) {
        newBallPosY = wallLowerYPosition - ballRadius;
        newDirection = -newDirection.GetAngle();
    }

    auto collisionData = std::make_unique<Data::Collision::BallCollisionData>(CPoint(static_cast<LONG>(ballPosX), static_cast<LONG>(newBallPosY)), newDirection);

    return collisionData;
}

}