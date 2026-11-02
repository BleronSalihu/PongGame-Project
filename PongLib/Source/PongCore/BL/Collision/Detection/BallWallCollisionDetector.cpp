#include "pch.h"
#include "PongCore/BL/Collision/Detection/BallWallCollisionDetector.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"


namespace Messerli::PongCore::BL::Collision::Detection {

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

auto BallWallCollisionDetector::IsCollision(const Type::CollisionPair& pair) -> bool
{
    let& ballFirstPosition = GetBall(pair.AFirstPosition);
    let& ballEndPosition = GetBall(pair.AEndPosition);
    let& wall = GetWall(pair.PEndPosition);
    
    let ballRadius = ballEndPosition.Size;
    let ballYPosition = ballEndPosition.Center.y;
    let lowerWallYPosition = wall.FieldHeight;
    let upperWallYPosition = 0;
    
    let hitsUpperWall = (ballYPosition - ballRadius <= upperWallYPosition);
    let hitsLowerWall = (ballYPosition + ballRadius >= lowerWallYPosition);

    return hitsUpperWall || hitsLowerWall;
}

}