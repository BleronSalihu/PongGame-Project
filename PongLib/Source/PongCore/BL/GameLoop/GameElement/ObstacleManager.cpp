#include "pch.h"
#include "PongCore/BL/GameLoop/GameElement/ObstacleManager.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"

namespace Messerli::PongCore::BL::GameLoop::GameElement {

ObstacleManager::ObstacleManager(const Data::PongDoc& doc)
    : gen{ std::random_device{}() },
    distX{ 15, ((doc.Width - 15) > 15 ? (doc.Width - 15) : 15) },
    distY{ 15, ((doc.Height - 15) > 15 ? (doc.Height - 15) : 15) },
    lastSpawn{ std::chrono::steady_clock::now() - std::chrono::seconds(5) },
    spawnInterval{ 10 }
{}

auto ObstacleManager::Initialize(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& initialModel) -> void 
{
    for (let& obj : initialModel) {
        if (obj->GetElement() == Data::GameElement::Ball) {
            let& b = dynamic_cast<const Data::Position::BallMoveData&>(*obj);
            ballStartCenter = b.Center;
            ballStartRadius = b.Size;
            break;
        }
    }
}

auto ObstacleManager::Update(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel, const Data::PongDoc& doc) -> void
{
    if (std::get<1>(doc.GameStartUp) != UI::Data::GameDifficulty::Extreme) {
        return;
    }

    let now = std::chrono::steady_clock::now();
    if (now - lastSpawn < spawnInterval) {
        return;
    }
    lastSpawn = now;

    let fieldW = doc.Width;
    let fieldH = doc.Height;
    let minX = obstacleSize / 2;
    let maxX = (fieldW - obstacleSize / 2 > minX) ? (fieldW - obstacleSize / 2) : minX;
    let minY = obstacleSize / 2;
    let maxY = (fieldH - obstacleSize / 2 > minY) ? (fieldH - obstacleSize / 2) : minY;
    std::uniform_int_distribution<int> distX(minX, maxX);
    std::uniform_int_distribution<int> distY(minY, maxY);

    let maxAttempts = 50;
    int x = 0;
    int y = 0;
    bool foundValid = false;
    for (int attempt = 0; attempt < maxAttempts; ++attempt) {
        x = distX(gen);
        y = distY(gen);
        if (!IsInvalidPos(x, y, doc, moveModel)) {
            foundValid = true;
            break;
        }
    }
    activeObstacles.push_back(std::make_unique<Data::Position::ObstacleMoveData>(CPoint(x, y), obstacleSize));
    moveModel.push_back(std::make_unique<Data::Position::ObstacleMoveData>(CPoint(x, y), obstacleSize));
}

auto ObstacleManager::IsInvalidPos(int x, int y, const Data::PongDoc& doc, const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModel) const -> bool
{
    let half = obstacleSize / 2;
    let buffer = 10;
    if (std::abs(x - ballStartCenter.x) <= (ballStartRadius + half + buffer) &&
        std::abs(y - ballStartCenter.y) <= (ballStartRadius + half + buffer)) {
        return true;
    }
    for (let& mv : moveModel) {
        if (mv->GetElement() == Data::GameElement::Player) {
            let& p = dynamic_cast<const Data::Position::PlayerMoveData&>(*mv);
            int paddleLeft = 0;
            int paddleRight = 0;
            if (p.Pos1.x < p.Pos2.x) {
                paddleLeft = p.Pos1.x;
                paddleRight = p.Pos2.x;
            }
            else {
                paddleLeft = p.Pos2.x;
                paddleRight = p.Pos1.x;
            }
            let xMin = paddleLeft - (half + buffer);
            let xMax = paddleRight + (half + buffer);
            if (x >= xMin && x <= xMax) {
                return true;
            }
        }
    }
    return false;
}


}