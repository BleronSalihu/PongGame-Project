#pragma once
#include "PongCore/BL/AbstractPongApp.h"

namespace Messerli::PongCore::BL {
class AbstractGame;
}

namespace Messerli::Pong {


class PongApp : public CWinApp, public Messerli::PongCore::BL::AbstractPongApp {
public:
    PongApp() noexcept;
    virtual BOOL InitInstance();
    auto GetMainWindow() -> CWnd* override;
    auto SetMainWindow(CWnd*) -> void override;
    auto GetInitialShowProperty() const -> int override;
private:
    std::unique_ptr<Messerli::PongCore::BL::AbstractGame> m_management{};
};

extern PongApp theApp;

}