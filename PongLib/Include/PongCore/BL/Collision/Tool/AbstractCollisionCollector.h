#pragma once
#include "PongCore/BL/Collision/Type/CollisionPair.h"
#include "PongCore/BL/Data/PongDoc.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"

namespace Messerli::PongCore::BL::Collision::Tool {

class AbstractCollisionCollector {
public:
    virtual auto ConvertCollision(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelfirstPosition, const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelEndPosition) -> std::vector<Type::CollisionPair>& abstract;
};

}