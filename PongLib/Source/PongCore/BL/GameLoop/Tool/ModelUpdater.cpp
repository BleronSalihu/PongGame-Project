#include "pch.h"
#include "PongCore/BL/GameLoop/Tool/ModelUpdater.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"
#include "PongCore/BL/Data/Collision/PlayerCollisionData.h"

namespace Messerli::PongCore::BL::GameLoop::Tool {

namespace {

auto GetBall(const Data::Collision::AbstractCollisionData& ball) -> const Data::Collision::BallCollisionData&
{
    return dynamic_cast<const Data::Collision::BallCollisionData&>(ball);
}

auto GetPaddle(const Data::Position::AbstractMoveData& ball) -> const Data::Position::PlayerMoveData&
{
    return dynamic_cast<const Data::Position::PlayerMoveData&>(ball);
}

auto GetWall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::WallMoveData&
{
    return dynamic_cast<const Data::Position::WallMoveData&>(ball);
}

}

auto ModelUpdater::UpdateMoveResultModel(std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>>& collisionResultModel,
    const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveResultModel, Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>
{
    std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> updatedModel;
    updatedModel.reserve(moveResultModel.size());

    for (let& mv : moveResultModel) {
        switch (mv->GetElement()) {
        case Data::GameElement::Ball: {
            let& b = dynamic_cast<const Data::Position::BallMoveData&>(*mv);
            updatedModel.push_back(std::make_unique<Data::Position::BallMoveData>(b));
            break;
        }
        case Data::GameElement::Player: {
            let& p = dynamic_cast<const Data::Position::PlayerMoveData&>(*mv);
            updatedModel.push_back(std::make_unique<Data::Position::PlayerMoveData>(p));
            break;
        }
        case Data::GameElement::Wall: {
            let& w = dynamic_cast<const Data::Position::WallMoveData&>(*mv);
            updatedModel.push_back(std::make_unique<Data::Position::WallMoveData>(w));
            break;
        }
        case Data::GameElement::Obstacle: {
            let& o = dynamic_cast<const Data::Position::ObstacleMoveData&>(*mv);
            updatedModel.push_back(std::make_unique<Data::Position::ObstacleMoveData>(o));
            break;
        }
        }
    }

    for (const auto& collision : collisionResultModel) {
        if (!collision) continue;

        if (let ballCollision = dynamic_cast<const Data::Collision::BallCollisionData*>(collision.get())) {
            auto& ball = dynamic_cast<Data::Position::BallMoveData&>(*updatedModel[0]);
            ball.Center = ballCollision->Center;
            ball.Direction = ballCollision->Direction;
        } else if (let paddleCollision = dynamic_cast<const Data::Collision::PlayerCollisionData*>(collision.get())) {
            if (paddleCollision->Pos1.x == GetPaddle(*moveResultModel[1]).Pos1.x) {
                auto& player1 = dynamic_cast<Data::Position::PlayerMoveData&>(*updatedModel[1]);
                player1.Pos1 = paddleCollision->Pos1;
                player1.Pos2 = paddleCollision->Pos2;
            } else if (paddleCollision->Pos1.x == GetPaddle(*moveResultModel[2]).Pos1.x) {
                auto& player2 = dynamic_cast<Data::Position::PlayerMoveData&>(*updatedModel[2]);
                player2.Pos1 = paddleCollision->Pos1;
                player2.Pos2 = paddleCollision->Pos2;
            }
        }
    }

    return updatedModel;
}

auto ModelUpdater::UpdateMoveModel(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel, Data::PongDoc& doc) -> void
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

auto ModelUpdater::UpdateMoveModel(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel,
    std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveResultModel) -> void
{
    moveModel = std::move(moveResultModel);
}

}