#include "pch.h"
#include "CppUnitTest.h"
#include "PongCore/BL/Collision/Calculation/BallObstacleCollisionCalculator.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/ObstacleMoveData.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Messerli::PongTest {

    namespace {
        PongCore::BL::Data::Position::BallMoveData Ball(int x, int y, int speed, double angle, int radius)
        {
            return PongCore::BL::Data::Position::BallMoveData(
                CPoint{ x, y },
                speed,
                PongCore::BL::Position::Type::Direction(angle),
                radius
            );
        }

        PongCore::BL::Data::Position::ObstacleMoveData Obstacle(int x1, int y1)
        {
            return PongCore::BL::Data::Position::ObstacleMoveData(
                CPoint{ x1, y1 },
                10
            );
        }

        PongCore::BL::Collision::Type::CollisionPair CollisionPair(
            const PongCore::BL::Data::Position::BallMoveData& ball,
            const PongCore::BL::Data::Position::ObstacleMoveData& obstacle)
        {
            return {
                ball,
                ball,
                PongCore::BL::Collision::Type::CollisionType::Reflection,
                obstacle,
                obstacle,
                PongCore::BL::Collision::Type::CollisionType::Standstill
            };
        }
    }

    TEST_CLASS(BallObstacleCollisionCalculatorTest)
    {
    public:
        TEST_METHOD(HorizontalCollisionReflectsX)
        {
            auto ball = Ball(120, 100, 10, 180.0, 5);
            auto obs = Obstacle(100, 100);
            auto pair = CollisionPair(ball, obs);

            PongCore::BL::Collision::Calculation::BallObstacleCollisionCalculator calc;
            auto result = calc.CalculateCollision(pair);
            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result.get());

            Assert::IsNotNull(result.get());
            double newAngle = ballResult->Direction.GetAngle();
            Assert::IsTrue(fabs(newAngle - 0.0) < 0.001 || fabs(newAngle - 360.0) < 0.001);
        }

        TEST_METHOD(HorizontalCollision_PassesThrough_StillReflects)
        {
            auto ball = Ball(130, 100, 50, 180.0, 5);
            auto obs = Obstacle(100, 100);
            auto pair = CollisionPair(ball, obs);

            PongCore::BL::Collision::Calculation::BallObstacleCollisionCalculator calc;
            auto result = calc.CalculateCollision(pair);
            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result.get());

            Assert::IsNotNull(ballResult);
            double newAngle = ballResult->Direction.GetAngle();
            Assert::IsTrue(fabs(newAngle - 0.0) < 0.001 || fabs(newAngle - 360.0) < 0.001);
        }

        TEST_METHOD(HorizontalCollision_EdgeCase_Reflects)
        {
            auto ball = Ball(110, 100, 10, 180.0, 5);
            auto obs = Obstacle(100, 100);
            auto pair = CollisionPair(ball, obs);

            PongCore::BL::Collision::Calculation::BallObstacleCollisionCalculator calc;
            auto result = calc.CalculateCollision(pair);
            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result.get());

            Assert::IsNotNull(ballResult);
            double newAngle = ballResult->Direction.GetAngle();
            Assert::IsTrue(fabs(newAngle - 0.0) < 0.001 || fabs(newAngle - 360.0) < 0.001);
        }

        TEST_METHOD(HorizontalCollision_MinimalSpeed_Reflects)
        {
            auto ball = Ball(106, 100, 5, 180.0, 0.1);  // bewegt sich extrem langsam von rechts
            auto obs = Obstacle(100, 100);             // Obstacle-Rand ist bei X = 105
            auto pair = CollisionPair(ball, obs);

            PongCore::BL::Collision::Calculation::BallObstacleCollisionCalculator calc;
            auto result = calc.CalculateCollision(pair);
            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result.get());

            Assert::IsNotNull(ballResult);
            double newAngle = ballResult->Direction.GetAngle();
            Assert::IsTrue(fabs(newAngle - 0.0) < 0.001 || fabs(newAngle - 360.0) < 0.001);
        }

        TEST_METHOD(HorizontalCollision_HighSpeed_PassesThrough_StillReflects)
        {
            auto ball = Ball(150, 100, 10, 180.0, 100);  // sehr schnell, durchquert das Obstacle
            auto obs = Obstacle(100, 100);
            auto pair = CollisionPair(ball, obs);

            PongCore::BL::Collision::Calculation::BallObstacleCollisionCalculator calc;
            auto result = calc.CalculateCollision(pair);
            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result.get());

            Assert::IsNotNull(ballResult);
            double newAngle = ballResult->Direction.GetAngle();
            Assert::IsTrue(fabs(newAngle - 0.0) < 0.001 || fabs(newAngle - 360.0) < 0.001);
        }

        TEST_METHOD(HorizontalCollision_TouchesCorner_Reflects)
        {
            auto ball = Ball(110, 104, 10, 180.0, 5);  // Y = 104 → oberer Rand fast auf gleicher Y-Höhe
            auto obs = Obstacle(100, 100);            // Obstacle reicht von Y = 95–105
            auto pair = CollisionPair(ball, obs);

            PongCore::BL::Collision::Calculation::BallObstacleCollisionCalculator calc;
            auto result = calc.CalculateCollision(pair);
            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result.get());

            Assert::IsNotNull(ballResult);
            double newAngle = ballResult->Direction.GetAngle();
            Assert::IsTrue(fabs(newAngle - 0.0) < 0.001 || fabs(newAngle - 360.0) < 0.001);
        }


        TEST_METHOD(VerticalCollisionReflectsY)
        {
            auto ball = Ball(100, 140, 5, 90.0, 5);
            auto obs = Obstacle(100, 100);
            auto pair = CollisionPair(ball, obs);

            PongCore::BL::Collision::Calculation::BallObstacleCollisionCalculator calc;
            auto result = calc.CalculateCollision(pair);
            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result.get());

            Assert::IsNotNull(ballResult);
            double newAngle = ballResult->Direction.GetAngle();
            Assert::IsTrue(fabs(newAngle - 270.0) < 0.001);
        }

        // Für Y-Reflektionen gelten grundsätzlich die gleichen Randfälle wie bei X-Reflektionen
    };
}
