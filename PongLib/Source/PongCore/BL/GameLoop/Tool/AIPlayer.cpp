#include "pch.h"
#include "PongCore/BL/GameLoop/Tool/AIPlayer.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"

namespace Messerli::PongCore::BL::GameLoop::Tool {

namespace {

auto GetBall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::BallMoveData&
{
    return dynamic_cast<const Data::Position::BallMoveData&>(ball);
}

auto GetPaddle(const Data::Position::AbstractMoveData& ball) -> const Data::Position::PlayerMoveData&
{
    return dynamic_cast<const Data::Position::PlayerMoveData&>(ball);
}

static auto PredictBallY(double ballX, double ballY, double vx, double vy, double paddleX, double fieldHeight) -> double 
{
    if (vx == 0.0) {
        return std::clamp(ballY, 0.0, fieldHeight);
    }
    double time = (paddleX - ballX) / vx;
    if (time < 0.0) {
        time = 0.0;
    }

    let y = ballY + vy * time;
    let period = 2.0 * fieldHeight;
    double m = std::fmod(y, period);
    if (m < 0.0) {
        m += period;
    }
    if (m > fieldHeight) {
        m = period - m;
    }
    return std::clamp(m, 0.0, fieldHeight);
}

auto GetVisabilty(const Data::PongDoc& doc) -> double {
    auto visibility = 0.0;
    switch (std::get<1>(doc.GameStartUp)) {
    case UI::Data::GameDifficulty::Easy:    visibility = doc.Height / 3.0; break;
    case UI::Data::GameDifficulty::Medium:  visibility = 2.0 * doc.Height / 3.0; break;
    case UI::Data::GameDifficulty::Hard:
    case UI::Data::GameDifficulty::Extreme: visibility = doc.Height; break;
    default: visibility = 0.0; break;
    }
    return visibility;
}

}

void AIPlayer::Move(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel,
    Data::PongDoc& doc) {
    let it = std::find_if(moveModel.begin(), moveModel.end(), [](auto const& obj) {
        return obj->GetElement() == Data::GameElement::Ball;
        });
    if (it == moveModel.end()) {
        return;
    }
    let& ballData = dynamic_cast<const Data::Position::BallMoveData&>(**it);

    auto* paddleMove = dynamic_cast<Data::Position::PlayerMoveData*>(moveModel[1].get());
    if (!paddleMove) {
        return;
    }

    let ballX = static_cast<double>(ballData.Center.x);
    let ballY = static_cast<double>(ballData.Center.y);
    let rad = ballData.Direction.GetAngle() * 3.14159265359 / 180.0;
    let vx = std::cos(rad) * ballData.Speed;
    let vy = std::sin(rad) * ballData.Speed;
    
    let paddleX = static_cast<double>(paddleMove->Pos1.x);
    let fieldH = static_cast<double>(doc.Height);
    let centerY = (static_cast<double>(paddleMove->Pos1.y) + paddleMove->Pos2.y) * 0.5;
    let maxSpeed = doc.DefaultValues->Player1Speed;
    let visibility = GetVisabilty(doc);

    let distX = std::abs(ballX - paddleX);
    if (distX > visibility) {
        double target = fieldH * 0.5;
        double delta = target - centerY;
        if (std::abs(delta) < 1e-3) {
            paddleMove->Speed = 0;
        }
        else {
            paddleMove->Direction = Position::Type::Direction(delta > 0 ? 90.0 : 270.0);
            paddleMove->Speed = maxSpeed;
        }
        return;
    }

    let movingTowards = (vx < 0 && paddleX < ballX) || (vx > 0 && paddleX > ballX);
    if (!movingTowards) {
        paddleMove->Speed = 0;
        return;
    }

    let predictedY = PredictBallY(ballX, ballY, vx, vy, paddleX, fieldH);
    let diffY = predictedY - centerY;
    if (std::abs(diffY) < 1.0) {
        paddleMove->Speed = 0;
    }
    else {
        paddleMove->Direction = Position::Type::Direction(diffY > 0 ? 90.0 : 270.0);
        paddleMove->Speed = maxSpeed;
    }
}

}