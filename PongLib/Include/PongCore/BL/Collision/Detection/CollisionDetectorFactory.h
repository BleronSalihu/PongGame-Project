#pragma once
#include "PongCore/BL/Collision/Detection/AbstractCollisionDetector.h"
#include "PongCore/BL/Data/GameElements.h"
#include "PongCore/BL/Collision/Type/CollisionPair.h"

namespace Messerli::PongCore::BL::Collision::Detection {

class CollisionDetectorFactory {
public:
    static auto Create(Type::CollisionPair pair) -> std::unique_ptr<AbstractCollisionDetector>;
};

}