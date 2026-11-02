#pragma once
#include "PongCore/UI/PongView.h"
#include "PongCore/BL/Data/PongDoc.h"
#include <functional>
#include <afxwin.h>

namespace Messerli::PongCore::UI {

class MainFrame : public CFrameWnd {
    DECLARE_MESSAGE_MAP();
public:
    struct ClassParams {
        PongView* View {nullptr};
        BL::Data::PongDoc& Doc;
        std::function<void(void)> Start;
        std::function<void(void)> PauseGame;
        std::function<void(void)> ResumeGame;
        std::function<void(void)> EndGame;
    };
    explicit MainFrame(ClassParams params);
    virtual BOOL PreTranslateMessage(MSG* pMsg) override;
    virtual ~MainFrame();
private:
    ClassParams m_classParams;
    CMenu m_menu;
    std::atomic<bool> m_isPaused;
    std::atomic<bool> m_isRunning;
    HACCEL m_hAccel;
    afx_msg auto OnGameSettings() -> void;
    afx_msg auto OnGameStart() -> void;
    afx_msg auto OnGameEnd() -> void;
    afx_msg auto OnGamePause() -> void;
    afx_msg auto OnGameResume() -> void;
    afx_msg auto OnClose() -> void;
    afx_msg auto OnUpdateGameSettings(CCmdUI* pCmdUI) -> void;
    afx_msg auto OnUpdateGameStart(CCmdUI* pCmdUI) -> void;
    afx_msg auto OnUpdateGameStop(CCmdUI* pCmdUI) -> void;
    afx_msg auto OnUpdateGamePause(CCmdUI* pCmdUI) -> void;
    afx_msg auto OnUpdateGameResume(CCmdUI* pCmdUI) -> void;
    auto GetDoc() -> BL::Data::PongDoc*;
};

}