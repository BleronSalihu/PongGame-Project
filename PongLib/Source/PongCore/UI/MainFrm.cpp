#include "pch.h"
#include "PongCore/UI/MainFrm.h"
#include "PongCore/UI/Tool/SettingsDialog.h"
#include "PongCore/BL/Tool/TransferTool.h"
#include "PongCore/BL/Data/DefaultValues.h"
#include "PongCore/UI/Tool/PausePopUpDialog.h"
#include "Resource.h"


namespace Messerli::PongCore::UI {

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_COMMAND(ID_GAME_SETTINGS, &MainFrame::OnGameSettings)
    ON_COMMAND(ID_GAME_START, &MainFrame::OnGameStart)
    ON_COMMAND(ID_GAME_STOP, &MainFrame::OnGameEnd)
    ON_COMMAND(ID_GAME_PAUSE, &MainFrame::OnGamePause)
    ON_COMMAND(ID_GAME_RESUME, &MainFrame::OnGameResume)
    ON_WM_CLOSE()
    ON_UPDATE_COMMAND_UI(ID_GAME_SETTINGS, &MainFrame::OnUpdateGameSettings)
    ON_UPDATE_COMMAND_UI(ID_GAME_START, &MainFrame::OnUpdateGameStart)
    ON_UPDATE_COMMAND_UI(ID_GAME_PAUSE, &MainFrame::OnUpdateGamePause)
    ON_UPDATE_COMMAND_UI(ID_GAME_STOP, &MainFrame::OnUpdateGameStop)
    ON_UPDATE_COMMAND_UI(ID_GAME_RESUME, &MainFrame::OnUpdateGameResume)
END_MESSAGE_MAP()

MainFrame::MainFrame(ClassParams params)
    : m_classParams {params}
{
    CFrameWnd::Create(nullptr, _T("PONG"), WS_OVERLAPPEDWINDOW, CRect(300, 100, 1500, 800));
    m_classParams.View->Create(nullptr, nullptr, WS_CHILD | WS_VISIBLE, CRect(), this, AFX_IDW_PANE_FIRST);
    m_menu.LoadMenu(IDR_MAINFRAME);
    m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
    SetMenu(&m_menu);
}

BOOL MainFrame::PreTranslateMessage(MSG* pMsg)
{
    if (m_hAccel && ::TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
        return TRUE;
    return CFrameWnd::PreTranslateMessage(pMsg);
}

MainFrame::~MainFrame()
{
}

auto MainFrame::OnGameSettings() -> void
{
    Tool::SettingsDialog dialog;

    if (dialog.DoModal() == IDOK) {
        UI::Tool::TransferTool::TransferColor(m_classParams.Doc.BackgroundColor, dialog.GetBackgroundColor());
        UI::Tool::TransferTool::TransferColor(m_classParams.Doc.Ball.BallColor, dialog.GetBallColor());
        UI::Tool::TransferTool::TransferColor(m_classParams.Doc.Player1.PlayerColor, dialog.GetPlayerColor());
        UI::Tool::TransferTool::TransferColor(m_classParams.Doc.Player2.PlayerColor, dialog.GetPlayerColor());
        UI::Tool::TransferTool::TransferDigit(m_classParams.Doc.Ball.BallSize, dialog.GetBallSize());
        UI::Tool::TransferTool::TransferDigit(m_classParams.Doc.Player1.PlayerSize, dialog.GetPlayerSize());
        UI::Tool::TransferTool::TransferDigit(m_classParams.Doc.Player2.PlayerSize, dialog.GetPlayerSize());
        UI::Tool::TransferTool::TransferDigit(m_classParams.Doc.Ball.BallSpeed, dialog.GetBallSpeed());
    }
    m_classParams.Doc.DefaultValues.emplace(BL::Data::DefaultValues(m_classParams.Doc.Ball.BallSpeed, dialog.GetPlayerSpeed(), dialog.GetPlayerSpeed()));
}

auto MainFrame::OnGameStart() -> void
{
    m_classParams.View->Invalidate();
    m_classParams.View->UpdateData();
    m_classParams.View->SetFocus();
    m_isRunning = true;
    m_classParams.Start();
}

auto MainFrame::OnGameEnd() -> void
{
    m_classParams.EndGame();
    m_isRunning = false;
    m_isPaused = false;
    SendMessage(WM_IDLEUPDATECMDUI, 1, 0);
    DrawMenuBar();

    CWnd* pView = m_classParams.View;
    CClientDC dc(pView);
    CRect rect;
    pView->GetClientRect(&rect);
    dc.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS);
}

auto MainFrame::OnGamePause() -> void
{

    m_classParams.PauseGame();
    m_isPaused = true;

    SendMessage(WM_IDLEUPDATECMDUI, 1, 0);
    DrawMenuBar();

    Tool::PausePopUpDialog dialog;
    let result = static_cast<int>(dialog.DoModal());

    if (result == IDOK) {
        OnGameResume();
    } else if (result == IDCANCEL) {
        OnGameEnd();
    }
}

auto MainFrame::OnGameResume() -> void
{
    m_classParams.ResumeGame();
    m_isPaused = false;
    SendMessage(WM_IDLEUPDATECMDUI, 1, 0);
    DrawMenuBar();
}

auto MainFrame::OnClose() -> void
{
    m_classParams.EndGame();
    CFrameWnd::OnClose();
}

auto MainFrame::OnUpdateGameSettings(CCmdUI* pCmdUI) -> void
{
    pCmdUI->Enable(!m_isRunning);
}

auto MainFrame::OnUpdateGameStart(CCmdUI* pCmdUI) -> void
{
    pCmdUI->Enable(!m_isRunning);
}

auto MainFrame::OnUpdateGamePause(CCmdUI* pCmdUI) -> void
{
    pCmdUI->Enable(m_isRunning && !m_isPaused);
}

auto MainFrame::OnUpdateGameResume(CCmdUI* pCmdUI) -> void
{
    pCmdUI->Enable(m_isPaused);
}

auto MainFrame::OnUpdateGameStop(CCmdUI* pCmdUI) -> void
{
    pCmdUI->Enable(m_isRunning);
}

}