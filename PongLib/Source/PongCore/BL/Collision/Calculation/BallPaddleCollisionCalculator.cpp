#include "pch.h"
#include "PongCore/BL/Collision/Calculation/BallPaddleCollisionCalculator.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

namespace {

auto GetBall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::BallMoveData&
{
    return dynamic_cast<const Data::Position::BallMoveData&>(ball);
}

auto GetPaddle(const Data::Position::AbstractMoveData& ball) -> const Data::Position::PlayerMoveData&
{
    return dynamic_cast<const Data::Position::PlayerMoveData&>(ball);
}

}

auto BallPaddleCollisionCalculator::CalculateCollision(const Type::CollisionPair& pair) -> std::unique_ptr<Data::Collision::AbstractCollisionData>
{
    let& ballFirstPosition = GetBall(pair.AFirstPosition);
    let& ballEndPosition = GetBall(pair.AEndPosition);
    let& paddleFirstPosition = GetPaddle(pair.PFirstPosition);
    let& paddleEndPosition = GetPaddle(pair.PEndPosition);
    
    let ballPosX = ballEndPosition.Center.x;
    let ballPosY = ballEndPosition.Center.y;
    let ballRadius = ballEndPosition.Size;
    
    let paddleTopEdge = paddleEndPosition.Pos1.y;
    let paddleBottomEdge = paddleEndPosition.Pos2.y;
    let paddleLeftEdge = paddleEndPosition.Pos1.x;
    let paddleRightEdge = paddleEndPosition.Pos2.x;

    auto newBallPosX = ballPosX;
    auto newBallPosY = ballPosY;
    auto newDirection = ballEndPosition.Direction;

    if (ballPosX < paddleLeftEdge) {
        newBallPosX = paddleLeftEdge - ballRadius;
    } else {
        newBallPosX = paddleRightEdge + ballRadius;
    }

    let paddleHeight = paddleBottomEdge - paddleTopEdge;
    let upperZoneLimit = paddleTopEdge + paddleHeight / 3;
    let lowerZoneLimit = paddleBottomEdge - paddleHeight / 3;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distMiddleZone(-44, 44);
    std::uniform_int_distribution<int> distUpperZone(-60, -45);
    std::uniform_int_distribution<int> distLowerZone(45, 60);

    if (ballPosY < upperZoneLimit) {
        newDirection = distUpperZone(gen);
    } else if (ballPosY > lowerZoneLimit) {
        newDirection = distLowerZone(gen); 
    } else {
        newDirection = distMiddleZone(gen);
    }

    if (ballPosX <= paddleLeftEdge) {
        newDirection.SetAngle(180.0 - newDirection.GetAngle());
    }

    auto collisionData = std::make_unique<Data::Collision::BallCollisionData>(CPoint(newBallPosX, newBallPosY), newDirection);

    return collisionData;
}

}