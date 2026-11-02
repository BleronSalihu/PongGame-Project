#include "pch.h"
#include "PongCore/BL/Position/ObstaclePosition.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"

namespace Messerli::PongCore::BL::Position {

auto ObstaclePosition::CalculatePosition(const Data::Position::AbstractMoveData& obj) -> std::unique_ptr<Data::Position::AbstractMoveData> 
{
    let& obstacle = dynamic_cast<const Data::Position::ObstacleMoveData&>(obj);
    auto newObstacle = std::make_unique<Data::Position::ObstacleMoveData>(obstacle.Center, obstacle.Size);
    return newObstacle;
}

}