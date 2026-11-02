#pragma once

namespace Messerli::PongCore::UI::Tool {

class SettingsDialog : public CDialogEx {
    DECLARE_DYNAMIC(SettingsDialog)
    DECLARE_MESSAGE_MAP()
public:
    SettingsDialog(CWnd* pParent = nullptr);
    virtual ~SettingsDialog();
    virtual BOOL OnInitDialog() override;
    auto GetBackgroundColor() const->COLORREF;
    auto GetBallColor() const->COLORREF;
    auto GetPlayerColor() const->COLORREF;
    auto GetBallSize() const -> int;
    auto GetPlayerSize() const -> int;
    auto GetBallSpeed() const -> int;
    auto GetPlayerSpeed() const -> int;
private:
    virtual void DoDataExchange(CDataExchange* pDX);
    afx_msg void OnSelchangeBackgroundColor();
    afx_msg void OnSelchangeBallColor();
    afx_msg void OnSelchangePlayerColor();
    afx_msg void OnSelchangeBallSize();
    afx_msg void OnSelchangePlayerSize();
    afx_msg void OnSelchangeBallSpeed();
    afx_msg void OnSelchangePlayerSpeed();
    COLORREF m_backgroundColor {};
    COLORREF m_ballColor {};
    COLORREF m_playerColor {};
    int m_ballSize = 0;
    int m_playerSize = 0;
    int m_ballSpeed = 0;
    int m_playerSpeed = 0;
};

}