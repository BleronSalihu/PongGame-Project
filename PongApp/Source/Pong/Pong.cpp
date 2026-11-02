#include "pch.h"
#include "Pong/Pong.h"
#include "PongCore/BL/GameManager.h"
#include "PongCore/PomgLib.h"

namespace Messerli::Pong {

PongApp::PongApp() noexcept
{
    SetAppID(_T("Pong.AppID.NoVersion"));
}

PongApp theApp;

BOOL PongApp::InitInstance()
{
    AfxSetResourceHandle(PongCore::GetPongLibResourceHandle());

    CWinApp::InitInstance();
    m_management = PongCore::CreateGameManager();
    m_management->Init();
    m_management->Show(theApp);
    return TRUE;
}

auto PongApp::GetMainWindow() -> CWnd*
{
    return m_pMainWnd;
}

auto PongApp::SetMainWindow(CWnd* hwnd) -> void
{
    m_pMainWnd = hwnd;
}

int PongApp::GetInitialShowProperty() const
{
    return m_nCmdShow;
}

}