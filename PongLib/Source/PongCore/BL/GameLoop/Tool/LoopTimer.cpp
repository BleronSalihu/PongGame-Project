#include "pch.h"
#include "PongCore/BL/GameLoop/Tool/LoopTimer.h"


namespace Messerli::PongCore::BL::GameLoop::Tool {

auto LoopTimer::Start() -> void
{
    m_start = std::chrono::steady_clock::now();
}

auto LoopTimer::End() -> void
{
    m_end = std::chrono::steady_clock::now();
}

auto LoopTimer::Sleep() -> void
{
    std::chrono::duration<double, std::milli> elapsedTime = m_end - m_start;
    if (elapsedTime.count() < m_timeDuration) {
        std::this_thread::sleep_for(std::chrono::milliseconds(m_timeDuration) - elapsedTime);
    }
}

}