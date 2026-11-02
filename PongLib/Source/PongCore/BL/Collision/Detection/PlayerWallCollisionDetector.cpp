#include "pch.h"
#include "PongCore/BL/Collision/Detection/PlayerWallCollisionDetector.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"

namespace Messerli::PongCore::BL::Collision::Detection {

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

auto PlayerWallCollisionDetector::IsCollision(const Type::CollisionPair& pair) -> bool
{
    let & paddleFirstPosition = GetPaddle(pair.AFirstPosition);
    let & paddleEndPosition = GetPaddle(pair.AEndPosition);
    let & wall = GetWall(pair.PEndPosition);
     
    let  lowerWallYPosition = wall.FieldHeight;
    let  upperWallYPosition = 0;
    
    let  paddleTopEdge = paddleEndPosition.Pos1.y;
    let  paddleBottomEdge = paddleEndPosition.Pos2.y;
    
    let  hitsUpperWall = (paddleTopEdge <= upperWallYPosition);
    let  hitsLowerWall = (paddleBottomEdge >= lowerWallYPosition);

    return hitsUpperWall || hitsLowerWall;
}

}