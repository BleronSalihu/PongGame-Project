#include "pch.h"
#include "PongCore/BL/Data/DefaultValues.h"

namespace Messerli::PongCore::BL::Data {

DefaultValues::DefaultValues(int ballSpeed, int player1Speed, int player2Speed)
    : BallSpeed(ballSpeed), Player1Speed(player1Speed), Player2Speed(player2Speed)
{
}

}