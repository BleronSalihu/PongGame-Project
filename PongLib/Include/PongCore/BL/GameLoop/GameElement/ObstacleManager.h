#pragma once
#include "PongCore/BL/GameLoop/GameElement/AbstractObstacleManager.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"

namespace Messerli::PongCore::BL::GameLoop::GameElement {

class ObstacleManager : public AbstractObstacleManager {
public:
    ObstacleManager(const Data::PongDoc& doc);
    auto Initialize(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& initialModel) -> void override;
    auto Update(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel, const Data::PongDoc& doc) -> void override;
private:
    std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> activeObstacles;
    std::mt19937                                    gen;
    std::uniform_int_distribution<int>              distX;
    std::uniform_int_distribution<int>              distY;
    std::chrono::steady_clock::time_point           lastSpawn;
    std::chrono::seconds                            spawnInterval;

    CPoint ballStartCenter = { 0, 0 };
    int    ballStartRadius = 0;
    int    obstacleSize = 20;

    auto IsInvalidPos(int x, int y, const Data::PongDoc& doc, const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel) const -> bool;
};

}