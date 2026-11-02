#pragma once
#include "BL/AbstractGame.h"
#include "BL/PongCore_API.h"

namespace Messerli::PongCore {

extern "C" PONGCORE_API HINSTANCE GetPongLibResourceHandle();

PONGCORE_API auto CreateGameManager() -> std::unique_ptr<PongCore::BL::AbstractGame>;

}