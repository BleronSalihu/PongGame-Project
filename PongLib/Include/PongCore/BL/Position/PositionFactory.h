#pragma once
#include "BallPosition.h"
#include "PlayerPosition.h"
#include "ObstaclePosition.h"
#include "WallPosition.h"
#include "PongCore/BL/Data/GameElements.h"

namespace Messerli::PongCore::BL::Position {

class PositionFactory {
public:
    static auto Create(Data::GameElement element) -> std::unique_ptr<AbstractPosition>;
};

}