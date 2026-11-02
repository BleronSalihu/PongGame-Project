#include "pch.h"
#include "PongCore/BL/GameLoop/Tool/MoveModelConverter.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"
#include "PongCore/BL/Data/Tool/StartPositionGetter.h"

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

auto MoveModelConverter::ConvertMove(Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>
{
    std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> tempMoveModel;
    tempMoveModel.push_back(std::make_unique<Data::Position::BallMoveData>(Data::Tool::StartPositionGetter::GetBallStartPos(doc), doc.Ball.BallSpeed, doc.Ball.BallDirection, doc.Ball.BallSize));
    tempMoveModel.push_back(std::make_unique<Data::Position::PlayerMoveData>(Data::Tool::StartPositionGetter::GetPlayer1StartPos1(doc), Data::Tool::StartPositionGetter::GetPlayer1StartPos2(doc), 0, doc.Player1.PlayerDirection, doc.Player1.PlayerSize));
    tempMoveModel.push_back(std::make_unique<Data::Position::PlayerMoveData>(Data::Tool::StartPositionGetter::GetPlayer2StartPos1(doc), Data::Tool::StartPositionGetter::GetPlayer2StartPos2(doc), 0, doc.Player2.PlayerDirection, doc.Player2.PlayerSize));
    tempMoveModel.push_back(std::make_unique<Data::Position::WallMoveData>(doc.Width, doc.Height));
    return tempMoveModel;
}

}