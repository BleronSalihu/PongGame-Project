#include "pch.h"
#include "PongCore/UI/Tool/ResultHandler.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"

namespace Messerli::PongCore::UI::Tool {

auto ResultHandler::HandleResult(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void
{
    let& ball = *std::find_if(moveModel.begin(), moveModel.end(), [](const auto& obj) {
        return obj->GetElement() == BL::Data::GameElement::Ball;
        });
    let ballPos = dynamic_cast<const BL::Data::Position::BallMoveData&>(*ball).Center;
    let fieldWidth = doc.Width;

    if (ballPos.x < 0) {
        doc.Player2.PlayerScore += 1;
        ResetBall(moveModel, doc);
    } else if (ballPos.x > fieldWidth) {
        doc.Player1.PlayerScore += 1;
        ResetBall(moveModel, doc);
    }
}

auto ResultHandler::ResetBall(std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& moveModel, BL::Data::PongDoc& doc) -> void
{
    let& ball = *std::find_if(moveModel.begin(), moveModel.end(), [](const auto& obj) {
        return obj->GetElement() == BL::Data::GameElement::Ball;
        });
    auto& ballMove = dynamic_cast<BL::Data::Position::BallMoveData&>(*ball);
    ballMove.Center = {doc.Width / 2, doc.Height / 2};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> validAngles;

    for (int angle = 0; angle < 360; ++angle) {
        if (!((angle >= 70 && angle <= 110) || (angle >= 250 && angle <= 290))) {
            validAngles.push_back(angle);
        }
    }

    std::uniform_int_distribution<size_t> indexDist(0, validAngles.size() - 1);
    let angle = validAngles[indexDist(gen)];
    ballMove.Direction = BL::Position::Type::Direction(angle);
    ballMove.Speed = doc.DefaultValues->BallSpeed;
}

}