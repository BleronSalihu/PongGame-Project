#pragma once
#include "AbstractModelUpdater.h"

namespace Messerli::PongCore::BL::GameLoop::Tool {

class ModelUpdater : public AbstractModelUpdater {
public:
    auto UpdateMoveResultModel(std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>>& collisionResultModel,
        const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveResultModel,
        Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> override;
    auto UpdateMoveModel(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel,
        Data::PongDoc& doc) -> void override;
    auto UpdateMoveModel(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel,
        std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveResultModel) -> void override;
};

}