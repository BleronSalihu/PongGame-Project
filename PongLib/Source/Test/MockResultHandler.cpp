#include "pch.h"
#include "Test/MockResultHandler.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"

namespace Messerli::PongCore::Test {

MockResultHandler::MockResultHandler()
{

}

auto MockResultHandler::HandleResult(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void
{
    auto ballIt = std::find_if(moveModel.begin(), moveModel.end(), [](const auto& obj) {
        return obj->GetElement() == BL::Data::GameElement::Ball;
        });
    if (ballIt == moveModel.end()) {
        return;
    }

    auto& ballMove = dynamic_cast<BL::Data::Position::BallMoveData&>(**ballIt);
    const int fieldWidth = doc.Width;

    if (ballMove.Center.x < 0) {
        doc.Player2.PlayerScore += 1;
        ResetBall(moveModel, doc);
    } else if (ballMove.Center.x > fieldWidth) {
        doc.Player1.PlayerScore += 1;
        ResetBall(moveModel, doc);
    }
}

auto MockResultHandler::ResetBall(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void
{
    auto ballIt = std::find_if(moveModel.begin(), moveModel.end(), [](const auto& obj) {
        return obj->GetElement() == BL::Data::GameElement::Ball;
        });
    if (ballIt == moveModel.end()) {
        return;
    }

    auto& ballMove = dynamic_cast<BL::Data::Position::BallMoveData&>(**ballIt);
    ballMove.Center = CPoint(doc.Width / 2, doc.Height / 2);
    ballMove.Direction = BL::Position::Type::Direction(90);
    ballMove.Speed = doc.DefaultValues->BallSpeed;
}

}