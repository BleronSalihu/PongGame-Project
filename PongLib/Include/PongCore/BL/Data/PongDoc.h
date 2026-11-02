#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/DefaultValues.h"
#include "PongCore/UI/Data/GameMode.h"
#include "PongCore/UI/Data/GameDifficulty.h"
#include "PongCore/UI/Data/GameReflectation.h"
#include "PongCore/BL/Data/Tool/PlayerDoc.h"
#include "PongCore/BL/Data/Tool/BallDoc.h"
#include "PongCore/BL/Position/Tool/AbstractAngleRandomizer.h"
#include <optional>

namespace Messerli::PongCore::BL::Data {

class PONGCORE_API PongDoc : public CDocument {
public:
    PongDoc(std::tuple<UI::Data::GameMode, UI::Data::GameDifficulty, UI::Data::GameReflectation> gameStartUp, BL::Position::Tool::AbstractAngleRandomizer& angleRandomizer);
    virtual ~PongDoc();
    Tool::PlayerDoc Player1;
    Tool::PlayerDoc Player2;
    Tool::BallDoc Ball;
    COLORREF BackgroundColor {RGB(100, 100, 100)};
    std::optional<BL::Data::DefaultValues> DefaultValues;
    int Width = 0;
    int Height = 0;
    std::tuple<UI::Data::GameMode, UI::Data::GameDifficulty, UI::Data::GameReflectation> GameStartUp;
    auto UpdateRect() -> void;
    auto SetView(CWnd* view) -> void;
    auto GetWnd() -> CWnd*;
private:
    CWnd* GameView {nullptr};
    BL::Position::Tool::AbstractAngleRandomizer& m_angleRandomizer;
};

}