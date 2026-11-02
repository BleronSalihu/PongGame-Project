#pragma once
#include "PongCore/UI/Data/GameDifficulty.h"
#include "PongCore/UI/Data/GameMode.h"
#include "PongCore/UI/Data/GameReflectation.h"


namespace Messerli::PongCore::UI::Tool {

class StartUpDialog : public CDialog {
    DECLARE_DYNAMIC(StartUpDialog)
    DECLARE_MESSAGE_MAP()
public:
    StartUpDialog(CWnd* pParent = nullptr);
    virtual ~StartUpDialog();
    virtual BOOL OnInitDialog() override;
    auto GetGameMode() -> Data::GameMode;
    auto GetDifficulty() -> Data::GameDifficulty;
    auto GetReflectation() -> Data::GameReflectation;
private:
    virtual void DoDataExchange(CDataExchange* pDX);
    afx_msg auto OnSinglePlayerClicked() -> void;
    afx_msg auto OnMultiPlayerClicked() -> void;
    afx_msg auto OnDifficultyClicked() -> void;
    afx_msg auto OnReflectationClicked() -> void;
    afx_msg auto OnClose() -> void;
    Data::GameDifficulty m_difficulty = Data::GameDifficulty::Easy;
    Data::GameMode m_mode = Data::GameMode::Invalid;
    Data::GameReflectation m_reflectation = Data::GameReflectation::Invalid;
};

}