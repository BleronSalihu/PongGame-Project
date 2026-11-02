#include "pch.h"
#include "PongCore/BL/Position/PositionFactory.h"

namespace Messerli::PongCore::BL::Position {

auto PositionFactory::Create(Data::GameElement element) -> std::unique_ptr<AbstractPosition>
{
    switch (element) {
        case Data::GameElement::Ball:
            return std::make_unique<BallPosition>();
        case Data::GameElement::Player:
            return std::make_unique<PlayerPosition>();
        case Data::GameElement::Wall:
            return std::make_unique<WallPosition>();
        case Data::GameElement::Obstacle:
            return std::make_unique<ObstaclePosition>();
        default:
            return {};
    }
}

}