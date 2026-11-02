#pragma once
#include "AbstractCollisionCollector.h"

namespace Messerli::PongCore::BL::Collision::Tool {

class CollisionCollector : public AbstractCollisionCollector {
public:
    auto ConvertCollision(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelfirstPosition, const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelEndPosition) -> std::vector<Type::CollisionPair>&;
};

}