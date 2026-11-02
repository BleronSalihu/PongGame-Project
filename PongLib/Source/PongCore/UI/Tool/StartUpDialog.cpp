#include "pch.h"
#include "PongCore/UI/Tool/StartUpDialog.h"
#include "Resource.h"

namespace Messerli::PongCore::UI::Tool {

IMPLEMENT_DYNAMIC(StartUpDialog, CDialogEx)

BEGIN_MESSAGE_MAP(StartUpDialog, CDialog)
    ON_BN_CLICKED(IDC_SINGLEPLAYER, &StartUpDialog::OnSinglePlayerClicked)
    ON_BN_CLICKED(IDC_MULTIPLAYER, &StartUpDialog::OnMultiPlayerClicked)
    ON_BN_CLICKED(IDC_EASY, &StartUpDialog::OnDifficultyClicked)
    ON_BN_CLICKED(IDC_MEDIUM, &StartUpDialog::OnDifficultyClicked)
    ON_BN_CLICKED(IDC_HARD, &StartUpDialog::OnDifficultyClicked)
    ON_BN_CLICKED(IDC_EXTREME, &StartUpDialog::OnDifficultyClicked)
    ON_BN_CLICKED(IDC_REFLECTATION, &StartUpDialog::OnReflectationClicked)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

StartUpDialog::StartUpDialog(CWnd* pParent)
    : CDialog(IDD_DEFAULT, pParent)
{
}

StartUpDialog::~StartUpDialog()
{
}

BOOL StartUpDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    SetWindowPos(nullptr, 0, 0, 660, 520, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    ModifyStyle(WS_THICKFRAME, 0);
    CenterWindow();
    CheckRadioButton(IDC_EASY, IDC_EXTREME, IDC_EASY);
    CheckRadioButton(IDC_RANDOM, IDC_MIRRORREFLECTION, IDC_RANDOM);
    return true;
}

auto StartUpDialog::GetGameMode() -> Data::GameMode
{
    return m_mode;
}

auto StartUpDialog::GetDifficulty() -> Data::GameDifficulty
{
    return m_difficulty;
}

auto StartUpDialog::GetReflectation() -> Data::GameReflectation
{
    return m_reflectation;
}

void StartUpDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
}

auto StartUpDialog::OnSinglePlayerClicked() -> void
{
    m_mode = Data::GameMode::Singleplayer;
    GetDlgItem(ID_DIFFICULTY)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_EASY)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_MEDIUM)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_HARD)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_EXTREME)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_REFLECTATION)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_RANDOM)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_MIRRORREFLECTION)->ShowWindow(SW_SHOW); 
}

auto StartUpDialog::OnMultiPlayerClicked() -> void
{
    m_mode = Data::GameMode::Multiplayer;
    GetDlgItem(ID_DIFFICULTY)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_EASY)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_MEDIUM)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_HARD)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_EXTREME)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_REFLECTATION)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_RANDOM)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_MIRRORREFLECTION)->ShowWindow(SW_SHOW);
}

auto StartUpDialog::OnDifficultyClicked() -> void
{
    let selectionID = GetCheckedRadioButton(IDC_EASY, IDC_EXTREME);

    switch (selectionID) {
        case IDC_EASY:
            m_difficulty = Data::GameDifficulty::Easy;
            break;
        case IDC_MEDIUM:
            m_difficulty = Data::GameDifficulty::Medium;
            break;
        case IDC_HARD:
            m_difficulty = Data::GameDifficulty::Hard;
            break;
        case IDC_EXTREME:
            m_difficulty = Data::GameDifficulty::Extreme;
            break;
        default:
            m_difficulty = Data::GameDifficulty::Invalid;
            break;
    }
}

auto StartUpDialog::OnReflectationClicked() -> void
{
    let selectionID = GetCheckedRadioButton(IDC_RANDOM, IDC_MIRRORREFLECTION);

    switch (selectionID) {
        case IDC_RANDOM:
            m_reflectation = Data::GameReflectation::Random;
            break;
        case IDC_MIRRORREFLECTION:
            m_reflectation = Data::GameReflectation::MirrorReflectation;
            break;
        default:
            m_reflectation = Data::GameReflectation::Invalid;
            break;
    }
}

auto StartUpDialog::OnClose() -> void
{
    PostQuitMessage(0);
    CDialog::OnClose();
}

}