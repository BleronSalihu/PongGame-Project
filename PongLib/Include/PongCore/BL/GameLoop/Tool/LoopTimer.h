#pragma once
#include <chrono>
#include <thread>

namespace Messerli::PongCore::BL::GameLoop::Tool {

class LoopTimer {
public:
    auto Start() -> void;
    auto End() -> void;
    auto Sleep() -> void;
private:
    int m_timeDuration = 1000 / 60;
    std::chrono::steady_clock::time_point m_start;
    std::chrono::steady_clock::time_point m_end;
};

}