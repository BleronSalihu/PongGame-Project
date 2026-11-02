#include "pch.h"
#include "PongCore/BL/Data/Tool/StartPositionGetter.h"
#include "PongCore/UI/Data/ObjectRatios.h"

namespace Messerli::PongCore::BL::Data::Tool {

auto StartPositionGetter::GetBallStartPos(PongDoc& doc) -> CPoint
{
    let fieldWidth = doc.Width;
    let fieldHeight = doc.Height;
    return CPoint(static_cast<int>(fieldWidth * UI::Data::BALL_X_RATIO), static_cast<int>(fieldHeight * UI::Data::BALL_Y_RATIO));
}

auto StartPositionGetter::GetPlayer1StartPos1(PongDoc& doc) -> CPoint
{
    let fieldWidth = doc.Width;
    let fieldHeight = doc.Height;
    return CPoint(static_cast<int>(fieldWidth * UI::Data::PLAYER1_X_RATIO), static_cast<int>(fieldHeight * UI::Data::PLAYER_Y_RATIO - (fieldHeight * UI::Data::PLAYER_SIZE_RATIO) / 2));
}

auto StartPositionGetter::GetPlayer1StartPos2(PongDoc& doc) -> CPoint
{
    let fieldWidth = doc.Width;
    let fieldHeight = doc.Height;
    let playerWidth = static_cast<int>(fieldWidth * 0.02);
    return CPoint(static_cast<int>(fieldWidth * UI::Data::PLAYER1_X_RATIO + playerWidth), static_cast<int>(fieldHeight * UI::Data::PLAYER_Y_RATIO + (fieldHeight * UI::Data::PLAYER_SIZE_RATIO) / 2));
}

auto StartPositionGetter::GetPlayer2StartPos1(PongDoc& doc) -> CPoint
{
    let fieldWidth = doc.Width;
    let fieldHeight = doc.Height;
    let playerWidth = static_cast<int>(fieldWidth * 0.02);
    return CPoint(static_cast<int>(fieldWidth * UI::Data::PLAYER2_X_RATIO - playerWidth), static_cast<int>(fieldHeight * UI::Data::PLAYER_Y_RATIO - (fieldHeight * UI::Data::PLAYER_SIZE_RATIO) / 2));
}

auto StartPositionGetter::GetPlayer2StartPos2(PongDoc& doc) -> CPoint
{
    let fieldWidth = doc.Width;
    let fieldHeight = doc.Height;
    return CPoint(static_cast<int>(fieldWidth * UI::Data::PLAYER2_X_RATIO), static_cast<int>(fieldHeight * UI::Data::PLAYER_Y_RATIO + (fieldHeight * UI::Data::PLAYER_SIZE_RATIO) / 2));
}


}