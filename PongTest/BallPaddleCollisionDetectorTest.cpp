#include "pch.h"
#include "CppUnitTest.h"
#include "PongCore/BL/Collision/Detection/BallPaddleCollisionDetector.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Collision/Type/CollisionPair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Messerli::PongTest {

    namespace {

        PongCore::BL::Data::Position::BallMoveData Ball(int x, int y, int radius)
        {
            return PongCore::BL::Data::Position::BallMoveData(
                CPoint{ x, x },
                0,
                PongCore::BL::Position::Type::Direction(0.0),
                radius
            );
        }

        PongCore::BL::Data::Position::PlayerMoveData Player(int x1, int y1, int x2, int y2)
        {
            return PongCore::BL::Data::Position::PlayerMoveData(
                CPoint{ x1, y1 },
                CPoint{ x2, y2 },
                0,
                PongCore::BL::Position::Type::Direction(0.0),
                0
            );
        }

        PongCore::BL::Collision::Type::CollisionPair CollisionPair(
            const PongCore::BL::Data::Position::BallMoveData& ball,
            const PongCore::BL::Data::Position::PlayerMoveData& player)
        {
            return {
                ball,
                ball,
                PongCore::BL::Collision::Type::CollisionType::Reflection,
                player,
                player,
                PongCore::BL::Collision::Type::CollisionType::Standstill
            };
        }
    }

    TEST_CLASS(BallPaddleCollisionDetectorTest)
    {       
    public:
        TEST_METHOD(BallHitsPaddle)
        {
            auto ball = Ball(50, 50, 10);
            auto player = Player(45, 45, 55, 55);
            auto pair = CollisionPair(ball, player);
            PongCore::BL::Collision::Detection::BallPaddleCollisionDetector detector;

            Assert::IsTrue(detector.IsCollision(pair));
        }

        TEST_METHOD(BallMissesPaddle)
        {
            auto ball = Ball(100, 100, 10);
            auto player = Player(120, 120, 130, 130);
            auto pair = CollisionPair(ball, player);
            PongCore::BL::Collision::Detection::BallPaddleCollisionDetector detector;

            Assert::IsFalse(detector.IsCollision(pair));
        }

        TEST_METHOD(BallInsidePaddle)
        {
            auto ball = Ball(50, 50, 1);
            auto player = Player(40, 40, 60, 60);
            auto pair = CollisionPair(ball, player);
            PongCore::BL::Collision::Detection::BallPaddleCollisionDetector detector;

            Assert::IsTrue(detector.IsCollision(pair));
        }

        TEST_METHOD(BallTouchesPaddle_Corner)
        {
            auto ball = Ball(60, 60, 5);
            auto player = Player(55, 55, 65, 65);
            auto pair = CollisionPair(ball, player);
            PongCore::BL::Collision::Detection::BallPaddleCollisionDetector detector;

            Assert::IsTrue(detector.IsCollision(pair));
        }
    };

}