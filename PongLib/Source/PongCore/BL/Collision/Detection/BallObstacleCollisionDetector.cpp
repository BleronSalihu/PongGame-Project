#include "pch.h"
#include "PongCore/BL/Collision/Detection/BallObstacleCollisionDetector.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"

namespace Messerli::PongCore::BL::Collision::Detection {

namespace {

auto GetBall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::BallMoveData&
{
    return dynamic_cast<const Data::Position::BallMoveData&>(ball);
}

auto GetObstacle(const Data::Position::AbstractMoveData& obstacle) -> const Data::Position::ObstacleMoveData&
{
    return dynamic_cast<const Data::Position::ObstacleMoveData&>(obstacle);
} 

}

auto BallObstacleCollisionDetector::IsCollision(const Type::CollisionPair& pair) -> bool
{
    let& ballData = GetBall(pair.AEndPosition);
    let& obsData = GetObstacle(pair.PEndPosition);

    let ballX = static_cast<double>(ballData.Center.x);
    let ballY = static_cast<double>(ballData.Center.y);
    let ballRadius = static_cast<double>(ballData.Size);

    let obsHalf = static_cast<double>(obsData.Size) / 2.0;
    let obsCenterX = static_cast<double>(obsData.Center.x);
    let obsCenterY = static_cast<double>(obsData.Center.y);

    let rectLeft = obsCenterX - obsHalf;
    let rectRight = obsCenterX + obsHalf;
    let rectTop = obsCenterY - obsHalf;
    let rectBottom = obsCenterY + obsHalf;

    double nearestX = ballX;
    if (ballX < rectLeft) {
        nearestX = rectLeft;
    }
    else if (ballX > rectRight) {
        nearestX = rectRight;
    }

    double nearestY = ballY;
    if (ballY < rectTop) {
        nearestY = rectTop;
    }
    else if (ballY > rectBottom) {
        nearestY = rectBottom;
    }

    let dx = ballX - nearestX;
    let dy = ballY - nearestY;
    return (dx * dx + dy * dy) <= (ballRadius * ballRadius);
}

}