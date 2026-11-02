#pragma once
#include "PongCore/BL/GameLoop/Tool/AbstractModelUpdater.h"

namespace Messerli::PongCore::Test {

class MockModelUpdater : public BL::GameLoop::Tool::AbstractModelUpdater {
public:
    MockModelUpdater();
    auto UpdateMoveResultModel(std::vector<std::unique_ptr<BL::Data::Collision::AbstractCollisionData>>& collisionResultModel,
        const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveResultModel, BL::Data::PongDoc& doc) -> std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>> override;
    auto UpdateMoveModel(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel,
        BL::Data::PongDoc& doc) -> void override;
    auto UpdateMoveModel(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel,
        std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveResultModel) -> void override;
private:

};

}