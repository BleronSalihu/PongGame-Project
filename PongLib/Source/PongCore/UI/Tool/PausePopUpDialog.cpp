#include "pch.h"
#include "PongCore/UI/Tool/PausePopUpDialog.h"
#include "Resource.h"

namespace Messerli::PongCore::UI::Tool {

IMPLEMENT_DYNAMIC(PausePopUpDialog, CDialogEx)

BEGIN_MESSAGE_MAP(PausePopUpDialog, CDialogEx)
    ON_BN_CLICKED(ID_GAME_RESUME, &PausePopUpDialog::OnClickedResume)
    ON_BN_CLICKED(ID_GAME_STOP, &PausePopUpDialog::OnClickedStop)
END_MESSAGE_MAP()

PausePopUpDialog::PausePopUpDialog(CWnd* wnd)
    : CDialogEx(IDD_PAUSE_POPUP, wnd)
{
}

PausePopUpDialog::~PausePopUpDialog()
{
}

BOOL PausePopUpDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    SetWindowPos(nullptr, 0, 0, 300, 160, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    CenterWindow();
    ModifyStyle(WS_THICKFRAME, 0);
    return TRUE;
}

void PausePopUpDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

auto PausePopUpDialog::OnClickedResume() -> void
{
    EndDialog(IDOK);
}

auto PausePopUpDialog::OnClickedStop() -> void
{
    EndDialog(IDCANCEL);
}

}