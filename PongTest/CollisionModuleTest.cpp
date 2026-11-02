#include "pch.h"
#include "CppUnitTest.h"
#include "PongCore/BL/Collision/CollisionModule.h"
#include "Test/MockCollisionCollector.h"
#include "Test/MockCollisionCalculator.h"
#include "Test/MockCollisionDetector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Messerli::PongTest {

namespace {
    std::unique_ptr<PongCore::BL::Data::Position::BallMoveData> Ball(int x, int y, int radius, double angle, int speed) {
        return std::make_unique<PongCore::BL::Data::Position::BallMoveData>(
            CPoint{ x, y },
            speed,
            PongCore::BL::Position::Type::Direction(angle),
            radius
        );
    }

    std::unique_ptr<PongCore::BL::Data::Position::PlayerMoveData> Player(int x1, int y1, int x2, int y2, int speed, int size) {
        return std::make_unique<PongCore::BL::Data::Position::PlayerMoveData>(
            CPoint{ x1, y1 },
            CPoint{ x2, y2 },
            speed,
            PongCore::BL::Position::Type::Direction(0.0),
            size
        );
    }


}

    TEST_CLASS(CollisionModuleTest) {
    public:
        TEST_METHOD(CalculateTest) 
        {
            auto ball = Ball(100, 100, 10, 0.0, 5);
            auto paddle = Player(90, 90, 110, 110, 0, 20);

            std::vector<std::unique_ptr<PongCore::BL::Data::Position::AbstractMoveData>> firstPos;
            std::vector<std::unique_ptr<PongCore::BL::Data::Position::AbstractMoveData>> endPos;

            firstPos.push_back(std::make_unique<PongCore::BL::Data::Position::BallMoveData>(*ball));
            firstPos.push_back(std::make_unique<PongCore::BL::Data::Position::PlayerMoveData>(*paddle));
            endPos.push_back(std::make_unique<PongCore::BL::Data::Position::BallMoveData>(*ball));
            endPos.push_back(std::make_unique<PongCore::BL::Data::Position::PlayerMoveData>(*paddle));

            PongCore::Test::MockCollisionCollector collector(*ball.get(), *paddle.get());
            PongCore::Test::MockCollisionCalculator calculation;
            PongCore::Test::MockCollisionDetector detection;


            PongCore::BL::Collision::CollisionModule module(collector, calculation, detection);

            auto result = module.Calculate(firstPos, endPos, PongCore::UI::Data::GameReflectation::MirrorReflectation);

            Assert::AreEqual(size_t(1), result.size());

            auto* ballResult = dynamic_cast<PongCore::BL::Data::Collision::BallCollisionData*>(result[0].get());
            Assert::IsNotNull(ballResult);
            Assert::AreEqual(50, static_cast<int>(ballResult->Center.x));
            Assert::AreEqual(50, static_cast<int>(ballResult->Center.y));
            Assert::IsTrue(fabs(ballResult->Direction.GetAngle() - 90.0) < 0.001);
        }
        //TODO: Mocks zu Testhelpern und Methodenaufrufe prüfen
        //TODO: Testclass initialize (firstPos und endPos initialisieren)
    };
}