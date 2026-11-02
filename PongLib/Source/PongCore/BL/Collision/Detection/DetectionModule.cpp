#include "pch.h"
#include "PongCore/BL/Collision/Detection/DetectionModule.h"
#include "PongCore/BL/Collision/Detection/CollisionDetectorFactory.h"


namespace Messerli::PongCore::BL::Collision::Detection {

auto DetectionModule::IsCollision(const std::vector<Type::CollisionPair>& collisionModel)->std::vector<Type::CollisionPair>
{
    std::vector<Type::CollisionPair> tempCollisionPairs;
    for (let& obj : collisionModel) {
        let detector = Detection::CollisionDetectorFactory::Create(obj);
        if (detector) {
            if (detector->IsCollision(obj)) {
                tempCollisionPairs.push_back(Type::CollisionPair(obj));
            }
        }
    }
    return tempCollisionPairs;
}

}