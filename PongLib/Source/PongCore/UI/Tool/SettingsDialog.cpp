#include "pch.h"
#include "PongCore/UI/Tool/SettingsDialog.h"
#include "Resource.h"

namespace Messerli::PongCore::UI::Tool {

namespace {

const std::map<CString, int> ObjectSizes {
    {_T("Small"), -10},
    {_T("Medium"), 15},
    {_T("Large"), 25},
    {_T("Noob - Large"), 50}
};

const std::map<CString, int> ObjectSpeeds {
    {_T("Slow"), 4},
    {_T("Medium"), 7},
    {_T("Fast"), 10},
    {_T("Flash"), 13}
};

}

IMPLEMENT_DYNAMIC(SettingsDialog, CDialogEx)

BEGIN_MESSAGE_MAP(SettingsDialog, CDialogEx)
    ON_BN_CLICKED(IDC_BACKGROUNDCOLOR, &SettingsDialog::OnSelchangeBackgroundColor)
    ON_BN_CLICKED(IDC_BALLCOLOR, &SettingsDialog::OnSelchangeBallColor)
    ON_BN_CLICKED(IDC_PLAYERCOLOR, &SettingsDialog::OnSelchangePlayerColor)
    ON_CBN_SELCHANGE(IDC_BALLSIZECOMBO, &SettingsDialog::OnSelchangeBallSize)
    ON_CBN_SELCHANGE(IDC_PLAYERSIZECOMBO, &SettingsDialog::OnSelchangePlayerSize)
    ON_CBN_SELCHANGE(IDC_BALLSPEEDCOMBO, &SettingsDialog::OnSelchangeBallSpeed)
    ON_CBN_SELCHANGE(IDC_PLAYERSPEEDCOMBO, &SettingsDialog::OnSelchangePlayerSpeed)
END_MESSAGE_MAP()

SettingsDialog::SettingsDialog(CWnd* pParent)
    : CDialogEx(IDD_SETTINGS, pParent)
{
}

SettingsDialog::~SettingsDialog()
{
}

BOOL SettingsDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    auto ballSize = static_cast<CComboBox*>(GetDlgItem(IDC_BALLSIZECOMBO));
    auto playerSize = static_cast<CComboBox*>(GetDlgItem(IDC_PLAYERSIZECOMBO));
    auto ballSpeed = static_cast<CComboBox*>(GetDlgItem(IDC_BALLSPEEDCOMBO));
    auto playerSpeed = static_cast<CComboBox*>(GetDlgItem(IDC_PLAYERSPEEDCOMBO));
    for (auto [key, value] : ObjectSizes) {
        ballSize->AddString(key);
        playerSize->AddString(key);
    }
    for (auto [key, value] : ObjectSpeeds) {
        ballSpeed->AddString(key);
        playerSpeed->AddString(key);
    }

    SetWindowPos(NULL, 0, 0, 650, 350, SWP_NOMOVE);
    return true;
}

auto SettingsDialog::GetBackgroundColor() const -> COLORREF
{
    return m_backgroundColor;
}

auto SettingsDialog::GetBallColor() const -> COLORREF
{
    return m_ballColor;
}

auto SettingsDialog::GetPlayerColor() const -> COLORREF
{
    return m_playerColor;
}

auto SettingsDialog::GetBallSize() const -> int
{
    return m_ballSize;
}

auto SettingsDialog::GetPlayerSize() const -> int
{
    return m_playerSize;
}

auto SettingsDialog::GetBallSpeed() const -> int
{
    return m_ballSpeed;
}

auto SettingsDialog::GetPlayerSpeed() const -> int
{
    return m_playerSpeed;
}

void SettingsDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

void SettingsDialog::OnSelchangeBackgroundColor()
{
    let colorPicker = (CMFCColorButton*)GetDlgItem(IDC_BACKGROUNDCOLOR);
    m_backgroundColor = colorPicker->GetColor();
}

void SettingsDialog::OnSelchangeBallColor()
{
    let colorPicker = (CMFCColorButton*)GetDlgItem(IDC_BALLCOLOR);
    m_ballColor = colorPicker->GetColor();
}

void SettingsDialog::OnSelchangePlayerColor()
{
    let colorPicker = (CMFCColorButton*)GetDlgItem(IDC_PLAYERCOLOR);
    m_playerColor = colorPicker->GetColor();
}

void SettingsDialog::OnSelchangeBallSize()
{
    let ballSize = (CComboBox*)GetDlgItem(IDC_BALLSIZECOMBO);
    CString temp(_T(""));
    ballSize->GetWindowText(temp);
    m_ballSize = ObjectSizes.at(temp);
}

void SettingsDialog::OnSelchangePlayerSize()
{
    let playerSize = (CComboBox*)GetDlgItem(IDC_PLAYERSIZECOMBO);
    CString temp(_T(""));
    playerSize->GetWindowText(temp);
    m_playerSize = ObjectSizes.at(temp);
}

void SettingsDialog::OnSelchangeBallSpeed()
{
    let ballSpeed = (CComboBox*)GetDlgItem(IDC_BALLSPEEDCOMBO);
    CString temp(_T(""));
    ballSpeed->GetWindowText(temp);
    m_ballSpeed = ObjectSpeeds.at(temp);
}

void SettingsDialog::OnSelchangePlayerSpeed()
{
    let playerSpeed = (CComboBox*)GetDlgItem(IDC_PLAYERSPEEDCOMBO);
    CString temp(_T(""));
    playerSpeed->GetWindowText(temp);
    m_playerSpeed = ObjectSpeeds.at(temp);
}

}