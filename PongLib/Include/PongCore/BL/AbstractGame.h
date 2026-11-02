#pragma once
#include "PongCore_API.h"
#include "AbstractPongApp.h"

namespace Messerli::PongCore::BL {

class PONGCORE_API AbstractGame {
public:
    virtual ~AbstractGame() = default;
    virtual auto Init() -> void abstract;
    virtual auto Show(AbstractPongApp& theApp) -> void abstract;
};

}