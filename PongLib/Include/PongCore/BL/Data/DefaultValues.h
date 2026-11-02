#pragma once

namespace Messerli::PongCore::BL::Data {

struct DefaultValues {
    DefaultValues(int ballSpeed, int player1Speed, int player2Speed);
    const int BallSpeed = 0;
    const int Player1Speed = 0;
    const int Player2Speed = 0;
};

}