#include "pch.h"
#include "PongCore/BL/Collision/Detection/BallPaddleCollisionDetector.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"

namespace Messerli::PongCore::BL::Collision::Detection {

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

auto BallPaddleCollisionDetector::IsCollision(const Type::CollisionPair& pair) -> bool
{
    let& ballFirstPosition = GetBall(pair.AFirstPosition);
    let& ballEndPosition = GetBall(pair.AEndPosition);
    let& paddleFirstPosition = GetPaddle(pair.PFirstPosition);
    let& paddleEndPosition = GetPaddle(pair.PEndPosition);
    
    let ballRadius = ballEndPosition.Size;
    let ballYPosition = ballEndPosition.Center.y;
    let ballXPosition = ballEndPosition.Center.x;
    
    let paddleRightX = paddleEndPosition.Pos2.x;
    let paddleBottom = paddleEndPosition.Pos2.y;
    let paddleLeftX = paddleEndPosition.Pos1.x;
    let paddleTop = paddleEndPosition.Pos1.y;
    
    let isBoundWithinX = (ballXPosition + ballRadius >= paddleLeftX) && (ballXPosition - ballRadius <= paddleRightX);
    let isBoundWithinY = (ballYPosition + ballRadius >= paddleTop) && (ballYPosition - ballRadius <= paddleBottom);

    return isBoundWithinX && isBoundWithinY;
}

}