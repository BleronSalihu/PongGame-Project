#pragma once
#include "PongCore_API.h"

namespace Messerli::PongCore::BL {

class PONGCORE_API AbstractPongApp {
public:
    virtual auto GetMainWindow() -> CWnd* abstract;
    virtual auto SetMainWindow(CWnd*) -> void abstract;
    virtual auto GetInitialShowProperty() const -> int abstract;
};

}