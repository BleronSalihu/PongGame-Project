#pragma once
#include "PongCore/BL/Data/Collision/AbstractCollisionData.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Data/PongDoc.h"
#include <vector>
#include <memory>

namespace Messerli::PongCore::BL::GameLoop::Tool {

class AbstractModelUpdater {
public:
    virtual auto UpdateMoveResultModel(std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>>& collisionResultModel,
        const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveResultModel, Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> abstract;
    virtual auto UpdateMoveModel(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel,
        Data::PongDoc& doc) -> void abstract;
    virtual auto UpdateMoveModel(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel,
        std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveResultModel) -> void abstract;
};

}