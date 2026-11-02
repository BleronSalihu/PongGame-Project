#include "pch.h"
#include "CppUnitTest.h"
#include "PongCore/UI/Paint/PaintFactory.h"
#include "PongCore/BL/Data/GameElements.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Messerli::PongTest {
    TEST_CLASS(PaintFactoryTest)
    {
    public:
        TEST_METHOD(CreateBallReturnsBallPainter)
        {
            auto painter = PongCore::UI::Paint::PaintFactory::Create(PongCore::BL::Data::GameElement::Ball);
            Assert::IsNotNull(painter.get());
            Assert::IsTrue(dynamic_cast<PongCore::UI::Paint::BallPainter*>(painter.get()) != nullptr);
        }

        TEST_METHOD(CreatePlayerReturnsPlayerPainter)
        {
            auto painter = PongCore::UI::Paint::PaintFactory::Create(PongCore::BL::Data::GameElement::Player);
            Assert::IsNotNull(painter.get());
            Assert::IsTrue(dynamic_cast<PongCore::UI::Paint::PlayerPainter*>(painter.get()) != nullptr);
        }

        TEST_METHOD(CreateObstacleReturnsObstaclePainter)
        {
            auto painter = PongCore::UI::Paint::PaintFactory::Create(PongCore::BL::Data::GameElement::Obstacle);
            Assert::IsNotNull(painter.get());
            Assert::IsTrue(dynamic_cast<PongCore::UI::Paint::ObstaclePainter*>(painter.get()) != nullptr);
        }

        TEST_METHOD(CreateWallReturnsNullptr)
        {
            auto painter = PongCore::UI::Paint::PaintFactory::Create(PongCore::BL::Data::GameElement::Wall);
            Assert::IsNull(painter.get());
        }
        TEST_METHOD(CreateInvalidReturnsNullptr)
        {
            auto painter = PongCore::UI::Paint::PaintFactory::Create(PongCore::BL::Data::GameElement::Invalid);
            Assert::IsNull(painter.get());
        }
    };
}