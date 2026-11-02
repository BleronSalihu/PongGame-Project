#pragma once

namespace Messerli::PongCore::UI::Tool {

class PausePopUpDialog : public CDialogEx {
    DECLARE_DYNAMIC(PausePopUpDialog)
    DECLARE_MESSAGE_MAP()
public:
    PausePopUpDialog(CWnd* wnd = nullptr);
    virtual ~PausePopUpDialog();
    virtual BOOL OnInitDialog() override;
private:
    virtual void DoDataExchange(CDataExchange* pDX);
    afx_msg auto OnClickedResume() -> void;
    afx_msg auto OnClickedStop() -> void;
};

}