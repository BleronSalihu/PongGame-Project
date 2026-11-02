#include "pch.h"
#include "PongCore/BL/Collision/Calculation/CollisionCalculatorFactory.h"
#include "PongCore/BL/Data/GameElements.h"
#include "PongCore/BL/Collision/Calculation/BallPaddleCollisionCalculator.h"
#include "PongCore/BL/Collision/Calculation/BallPaddleCollisionCalculatorMirror.h"
#include "PongCore/BL/Collision/Calculation/BallWallCollisionCalculator.h"
#include "PongCore/BL/Collision/Calculation/PlayerWallCollisionCalculator.h"
#include "PongCore/BL/Collision/Calculation/BallObstacleCollisionCalculator.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

auto CollisionCalculatorFactory::Create(Type::CollisionPair pair, UI::Data::GameReflectation reflectation) -> std::unique_ptr<AbstractCollisionCalculator>
{
    switch (pair.AEndPosition.GetElement())
    {
    case Data::GameElement::Ball:
        switch (pair.PEndPosition.GetElement())
        {
        case Data::GameElement::Wall:
            return std::make_unique<BallWallCollisionCalculator>();
        case Data::GameElement::Player:
            return reflectation == UI::Data::GameReflectation::Random
                ? std::unique_ptr<AbstractCollisionCalculator>(std::make_unique<BallPaddleCollisionCalculator>())
                : std::unique_ptr<AbstractCollisionCalculator>(std::make_unique<BallPaddleCollisionCalculatorMirror>());
        case Data::GameElement::Obstacle:
            return std::make_unique<BallObstacleCollisionCalculator>();
        default: break;
        }
        break;

    case Data::GameElement::Player:
        switch (pair.PEndPosition.GetElement())
        {
        case Data::GameElement::Wall:
            return std::make_unique<PlayerWallCollisionCalculator>();
        default: break;
        }
    }
    return {};
}

}