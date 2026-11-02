#include "pch.h"
#include "PongCore/PomgLib.h"
#include "PongCore/BL/GameManager.h"

namespace Messerli::PongCore {

static HINSTANCE g_hInstance = nullptr;

extern "C" PONGCORE_API HINSTANCE GetPongLibResourceHandle()
{
    return g_hInstance;
}

static void* GetThisDllAddress()
{
    return (void*)&GetThisDllAddress;
}

class HInstanceHolder {
public:
    HInstanceHolder()
    {
        MEMORY_BASIC_INFORMATION mbi = {};
        VirtualQuery(GetThisDllAddress(), &mbi, sizeof(mbi));
        g_hInstance = (HINSTANCE)mbi.AllocationBase;
    }
};

static HInstanceHolder g_instanceLoader;

auto CreateGameManager() -> std::unique_ptr<BL::AbstractGame>
{
    return std::make_unique<BL::GameManager>();
}

}