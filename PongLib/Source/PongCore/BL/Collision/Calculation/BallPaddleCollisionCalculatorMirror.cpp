#include "pch.h"
#include "PongCore/BL/Collision/Calculation/BallPaddleCollisionCalculatorMirror.h"
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

auto BallPaddleCollisionCalculatorMirror::CalculateCollision(const Type::CollisionPair& pair)->std::unique_ptr<Data::Collision::AbstractCollisionData>
{
    let& ballEndPosition = GetBall(pair.AEndPosition);
    let& paddleFirstPosition = GetPaddle(pair.PFirstPosition);
    let& paddleEndPosition = GetPaddle(pair.PEndPosition);
    
    let ballPosX = ballEndPosition.Center.x;
    let ballPosY = ballEndPosition.Center.y;
    let ballRadius = ballEndPosition.Size;
    
    let paddleLeftEdge = paddleEndPosition.Pos1.x;
    let paddleRightEdge = paddleEndPosition.Pos2.x;

    auto newBallPosX = ballPosX;
    auto newBallPosY = ballPosY;
    auto newDirection = ballEndPosition.Direction;

    if (ballPosX < paddleLeftEdge) {
        newBallPosX = paddleLeftEdge - ballRadius;
    }
    else {
        newBallPosX = paddleRightEdge + ballRadius;
    }

    let angle = newDirection.GetAngle();
    double reflectedAngle = 180.0 - angle;
    let paddleSpeedY = static_cast<double>(paddleEndPosition.Pos1.y - paddleFirstPosition.Pos2.y);
    let offset = std::clamp(paddleSpeedY * 2.0, -20.0, 20.0);

    reflectedAngle += offset;

    if (reflectedAngle < 0.0) {
        reflectedAngle += 360.0;
    }
    if (reflectedAngle >= 360.0) {
        reflectedAngle -= 360.0;
    }

    newDirection.SetAngle(reflectedAngle);
    auto collisionData = std::make_unique<Data::Collision::BallCollisionData>(
        CPoint(newBallPosX, newBallPosY),
        newDirection
    );

    return collisionData;
}

}