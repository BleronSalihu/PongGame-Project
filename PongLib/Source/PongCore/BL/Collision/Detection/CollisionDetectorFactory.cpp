#include "pch.h"
#include "PongCore/BL/Collision/Detection/CollisionDetectorFactory.h"
#include "PongCore/BL/Collision/Detection/BallPaddleCollisionDetector.h"
#include "PongCore/BL/Collision/Detection/BallWallCollisionDetector.h"
#include "PongCore/BL/Collision/Detection/PlayerWallCollisionDetector.h"
#include "PongCore/BL/Collision/Detection/BallObstacleCollisionDetector.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Collision/Type/CollisionPair.h"

namespace Messerli::PongCore::BL::Collision::Detection {

auto CollisionDetectorFactory::Create(Type::CollisionPair pair) -> std::unique_ptr<AbstractCollisionDetector>
{
    switch (pair.AEndPosition.GetElement())
    {
    case Data::GameElement::Ball:
        switch (pair.PEndPosition.GetElement())
        {
            case Data::GameElement::Wall:
                return std::make_unique<BallWallCollisionDetector>();
            case Data::GameElement::Player:
                return std::make_unique<BallPaddleCollisionDetector>();
            case Data::GameElement::Obstacle:
                return std::make_unique<BallObstacleCollisionDetector>();
        default: break;
        }
        break;

    case Data::GameElement::Player:
        switch (pair.PEndPosition.GetElement())
        {
            case Data::GameElement::Wall:
                return std::make_unique<PlayerWallCollisionDetector>();
        default: break;
        }
    }
    return {};
}

}