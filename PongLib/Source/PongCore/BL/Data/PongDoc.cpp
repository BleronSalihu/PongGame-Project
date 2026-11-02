#include "pch.h"
#include "Pongcore/BL/Data/PongDoc.h"
#include "PongCore/BL/Data/Tool/DefaultValuesGetter.h"

namespace Messerli::PongCore::BL::Data {

PongDoc::PongDoc(std::tuple<UI::Data::GameMode, UI::Data::GameDifficulty, UI::Data::GameReflectation> gameStartUps,
    Position::Tool::AbstractAngleRandomizer& angleRandomizer)
    : GameStartUp(gameStartUps), m_angleRandomizer(angleRandomizer)
{
    Ball.BallDirection = m_angleRandomizer.GetRandomAngle();
    Player1.PlayerDirection = Position::Type::Direction(90);
    Player2.PlayerDirection = Position::Type::Direction(270);
    let defaults = Tool::DefaultValuesGetter::GetDefaultValues(std::get<1>(GameStartUp));
    Ball.BallSize = defaults[0];
    Ball.BallSpeed = defaults[1];
    Player1.PlayerSize = defaults[2];
    Player2.PlayerSize = defaults[2];
    Player1.PlayerSpeed = 0;
    Player2.PlayerSpeed = 0;
    DefaultValues.emplace(BL::Data::DefaultValues(Ball.BallSpeed, defaults[3], defaults[3]));
}

PongDoc::~PongDoc()
{
}

auto PongDoc::UpdateRect() -> void
{
    CRect rect;
    let* mainWnd = AfxGetMainWnd();
    if (mainWnd) {
        mainWnd->GetClientRect(&rect);
        Width = rect.Width();
        Height = rect.Height();
    }
}

auto PongDoc::SetView(CWnd* wnd) -> void
{
    GameView = wnd;
}

auto PongDoc::GetWnd() -> CWnd*
{
    return GameView;
}

}