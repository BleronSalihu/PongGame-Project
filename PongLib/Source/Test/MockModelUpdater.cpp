#include "pch.h"
#include "Test/MockModelUpdater.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::Test {

MockModelUpdater::MockModelUpdater()
{

}

auto MockModelUpdater::UpdateMoveResultModel(std::vector<std::unique_ptr<BL::Data::Collision::AbstractCollisionData>>& collisionResultModel,
    const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveResultModel, BL::Data::PongDoc& doc)->std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>
{
    std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>> updatedModel;

    if (moveResultModel.size() < 4) {
        return updatedModel;
    }

    auto ballCopy = std::make_unique<BL::Data::Position::BallMoveData>(
        dynamic_cast<const BL::Data::Position::BallMoveData&>(*moveResultModel[0])
    );
    if (!collisionResultModel.empty()) {
        ballCopy->Center = {100, 100};
        ballCopy->Direction = BL::Position::Type::Direction(45);
    }
    updatedModel.push_back(std::move(ballCopy));

    auto player1Copy = std::make_unique<BL::Data::Position::PlayerMoveData>(
        dynamic_cast<const BL::Data::Position::PlayerMoveData&>(*moveResultModel[1])
    );
    player1Copy->Pos1 = {50, 50};
    player1Copy->Pos2 = {50, 150};
    updatedModel.push_back(std::move(player1Copy));

    auto player2Copy = std::make_unique<BL::Data::Position::PlayerMoveData>(
        dynamic_cast<const BL::Data::Position::PlayerMoveData&>(*moveResultModel[2])
    );
    player2Copy->Pos1 = {300, 50};
    player2Copy->Pos2 = {300, 150};
    updatedModel.push_back(std::move(player2Copy));

    auto wallCopy = std::make_unique<BL::Data::Position::WallMoveData>(
        dynamic_cast<const BL::Data::Position::WallMoveData&>(*moveResultModel[3])
    );
    updatedModel.push_back(std::move(wallCopy));

    return updatedModel;
}
auto MockModelUpdater::UpdateMoveModel(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel,
    BL::Data::PongDoc& doc) -> void
{
    for (size_t i = 0; i < moveModel.size(); ++i) {
        if (auto* playerMove = dynamic_cast<BL::Data::Position::PlayerMoveData*>(moveModel[i].get())) {
            if (i == 1) {
                playerMove->Speed = doc.Player1.PlayerSpeed;
                playerMove->Direction = doc.Player1.PlayerDirection;
            } else if (i == 2) {
                playerMove->Speed = doc.Player2.PlayerSpeed;
                playerMove->Direction = doc.Player2.PlayerDirection;
            }
        }
    }
}
auto MockModelUpdater::UpdateMoveModel(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel,
    std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveResultModel) -> void
{
    moveModel = std::move(moveResultModel);
}

}