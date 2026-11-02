#include "pch.h"
#include "PongCore/BL/Collision/Calculation/BallObstacleCollisionCalculator.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"

namespace Messerli::PongCore::BL::Collision::Calculation {

namespace {

auto GetBall(const Data::Position::AbstractMoveData& ball) -> const Data::Position::BallMoveData&
{
    return dynamic_cast<const Data::Position::BallMoveData&>(ball);
}

auto GetObstacle(const Data::Position::AbstractMoveData& obstacle) -> const Data::Position::ObstacleMoveData&
{
    return dynamic_cast<const Data::Position::ObstacleMoveData&>(obstacle);
}

}

auto BallObstacleCollisionCalculator::CalculateCollision(const Type::CollisionPair& pair) -> std::unique_ptr<Data::Collision::AbstractCollisionData>
{
    let& ballData = GetBall(pair.AEndPosition);
    let& obsData = GetObstacle(pair.PEndPosition);

    let ballX = static_cast<double>(ballData.Center.x);
    let ballY = static_cast<double>(ballData.Center.y);
    let ballRadius = static_cast<double>(ballData.Size);
    let speed = static_cast<double>(ballData.Speed);
    let angleDeg = ballData.Direction.GetAngle();
    let angleRad = angleDeg * 3.14159265359 / 180.0;
    let vx = std::cos(angleRad) * speed;
    let vy = std::sin(angleRad) * speed;
    
    let obsCX = static_cast<double>(obsData.Center.x);
    let obsCY = static_cast<double>(obsData.Center.y);
    let obsHalf = static_cast<double>(obsData.Size) / 2.0;
    
    let dx = ballX - obsCX;
    let dy = ballY - obsCY;
    let absDX = std::abs(dx);
    let absDY = std::abs(dy);

    double newVX = vx;
    double newVY = vy;
    if (absDX > absDY) {
        newVX = -vx;
        newVY = vy;
    }
    else {
        newVX = vx;
        newVY = -vy;
    }

    double newX = ballX;
    double newY = ballY;
    if (absDX > absDY) {
        double signX = (dx > 0.0) ? 1.0 : -1.0;
        newX = obsCX + signX * (obsHalf + ballRadius);
        newY = ballY;
    }
    else {
        let signY = (dy > 0.0) ? 1.0 : -1.0;
        newY = obsCY + signY * (obsHalf + ballRadius);
        newX = ballX;
    }

    let newAngleRad = std::atan2(newVY, newVX);
    double newAngleDeg = newAngleRad * 180.0 / 3.14159265359;
    if (newAngleDeg < 0.0) {
        newAngleDeg += 360.0;
    }
    Position::Type::Direction newDir(newAngleDeg);
    return std::make_unique<Data::Collision::BallCollisionData>(CPoint(static_cast<LONG>(std::round(newX)), static_cast<LONG>(std::round(newY))), newDir);
}

}