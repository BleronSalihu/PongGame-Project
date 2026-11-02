#include "pch.h"
#include "PongCore/BL/GameLoop/Tool/ViewModelConverter.h"
#include "PongCore/BL/Data/Paint/BallViewData.h"
#include "PongCore/BL/Data/Paint/PlayerViewData.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"
#include "PongCore/BL/Data/Paint/ObstacleViewData.h"

namespace Messerli::PongCore::BL::GameLoop::Tool {

namespace {

auto GetPlayerCast(const Data::Position::AbstractMoveData& obj) -> Data::Position::PlayerMoveData
{
    return *dynamic_cast<const Data::Position::PlayerMoveData*>(&obj);
}

auto GetBallCast(const Data::Position::AbstractMoveData& obj) -> Data::Position::BallMoveData
{
    return *dynamic_cast<const Data::Position::BallMoveData*>(&obj);
}

}

auto ViewModelConverter::ConvertView(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& positions, Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Paint::AbstractViewData>>
{
    std::vector<std::unique_ptr<Data::Paint::AbstractViewData>> viewModel;
    viewModel.reserve(positions.size());

    for (auto& pos : positions) {
        switch (pos->GetElement()) {
        case Data::GameElement::Ball: {
            auto& b = dynamic_cast<const Data::Position::BallMoveData&>(*pos);
            viewModel.push_back(std::make_unique<Data::Paint::BallViewData>(doc.Ball.BallColor, b.Center, doc.Ball.BallSize));
            break;
        }
        case Data::GameElement::Player: {
            auto& p = dynamic_cast<const Data::Position::PlayerMoveData&>(*pos);
            const auto& info = (p.Pos1.x < doc.Width / 2) ? doc.Player1 : doc.Player2;
            viewModel.push_back(std::make_unique<Data::Paint::PlayerViewData>(info.PlayerColor, p.Pos1, p.Pos2, info.PlayerSize));
            break;
        }
        case Data::GameElement::Obstacle: {
            auto& o = dynamic_cast<const Data::Position::ObstacleMoveData&>(*pos);
            CRect rect(o.Center.x - o.Size / 2, o.Center.y - o.Size / 2, o.Center.x + o.Size / 2, o.Center.y + o.Size / 2);
            viewModel.push_back(std::make_unique<Data::Paint::ObstacleViewData>(rect));
            break;
        }
        default:
            break;
        }
    }

    return viewModel;
}

}