#pragma once
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Data/PongDoc.h"
#include <vector>
#include <random>
#include <chrono>

namespace Messerli::PongCore::BL::GameLoop::GameElement {

class AbstractObstacleManager {
public:
    AbstractObstacleManager() = default;
    virtual auto Initialize(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& initialModel) -> void abstract;
    virtual auto Update(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel, const Data::PongDoc& doc) -> void abstract;
};

}