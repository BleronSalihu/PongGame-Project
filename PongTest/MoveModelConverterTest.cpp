#include "pch.h"
#include "CppUnitTest.h"
#include "PongCore/BL/GameLoop/Tool/MoveModelConverter.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"
#include "Test/MockAngleRandomizer.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Messerli::PongTest {

    namespace {
        std::tuple<PongCore::UI::Data::GameMode, PongCore::UI::Data::GameDifficulty, PongCore::UI::Data::GameReflectation> MakeStartUp() {
            return {
                PongCore::UI::Data::GameMode::Singleplayer,
                PongCore::UI::Data::GameDifficulty::Easy,
                PongCore::UI::Data::GameReflectation::MirrorReflectation
            };
        }

        std::vector<std::unique_ptr<PongCore::BL::Data::Position::AbstractMoveData>> CreateMoves()
        {
            PongCore::Test::MockAngleRandomizer angle(40);
            auto startUp = MakeStartUp();
            PongCore::BL::Data::PongDoc doc(startUp, angle);
            doc.Width = 800;
            doc.Height = 600;

            PongCore::BL::GameLoop::Tool::MoveModelConverter converter;
            return converter.ConvertMove(doc);
        }
    }

    TEST_CLASS(MoveModelConverterTest) {
    public:
        TEST_METHOD(ConvertMoveReturns4Elements)
        {
            auto moves = CreateMoves();
            Assert::AreEqual(size_t(4), moves.size());
        }


        TEST_METHOD(ConvertMoveContainsBallMoveData)
        {
            auto moves = CreateMoves();

            auto* ball = dynamic_cast<PongCore::BL::Data::Position::BallMoveData*>(moves[0].get());
            Assert::IsNotNull(ball);

            PongCore::Test::MockAngleRandomizer angle(40);
            auto doc = PongCore::BL::Data::PongDoc(MakeStartUp(), angle);

            Assert::AreEqual(doc.Ball.BallSize, ball->Size);
            Assert::AreEqual(doc.Ball.BallSpeed, ball->Speed);
            Assert::IsTrue(fabs(ball->Direction.GetAngle() - doc.Ball.BallDirection.GetAngle()) < 0.001);
        }

        TEST_METHOD(ConvertMoveContainsPlayer1MoveData)
        {
            auto moves = CreateMoves();

            auto* player1 = dynamic_cast<PongCore::BL::Data::Position::PlayerMoveData*>(moves[1].get());
            Assert::IsNotNull(player1);

            PongCore::Test::MockAngleRandomizer angle(40);
            auto doc = PongCore::BL::Data::PongDoc(MakeStartUp(), angle);

            Assert::AreEqual(doc.Player1.PlayerSize, player1->Size);
            Assert::IsTrue(fabs(player1->Direction.GetAngle() - doc.Player1.PlayerDirection.GetAngle()) < 0.001);
        }

        TEST_METHOD(ConvertMoveContainsPlayer2MoveData)
        {
            auto moves = CreateMoves();

            auto* player2 = dynamic_cast<PongCore::BL::Data::Position::PlayerMoveData*>(moves[2].get());
            Assert::IsNotNull(player2);

            PongCore::Test::MockAngleRandomizer angle(40);
            auto doc = PongCore::BL::Data::PongDoc(MakeStartUp(), angle);

            Assert::AreEqual(doc.Player2.PlayerSize, player2->Size);
            Assert::IsTrue(fabs(player2->Direction.GetAngle() - doc.Player2.PlayerDirection.GetAngle()) < 0.001);
        }

        TEST_METHOD(ConvertMoveContainsWallMoveData)
        {
            auto moves = CreateMoves();

            auto* wall = dynamic_cast<PongCore::BL::Data::Position::WallMoveData*>(moves[3].get());
            Assert::IsNotNull(wall);

            PongCore::Test::MockAngleRandomizer angle(40);
            auto doc = PongCore::BL::Data::PongDoc(MakeStartUp(), angle);
            doc.Width = 800;
            doc.Height = 600;

            Assert::IsTrue(fabs(wall->FieldWidth - doc.Width) < 0.001);
            Assert::IsTrue(fabs(wall->FieldHeight - doc.Height) < 0.001);
        }

        TEST_METHOD(ConvertMoveWithNegativeDimensionsHandlesWallData)
        {
            PongCore::Test::MockAngleRandomizer angle(40);
            auto doc = PongCore::BL::Data::PongDoc(MakeStartUp(), angle);
            doc.Width = -100;
            doc.Height = -50;

            PongCore::BL::GameLoop::Tool::MoveModelConverter converter;
            auto moves = converter.ConvertMove(doc);

            Assert::AreEqual(size_t(4), moves.size());

            auto* wall = dynamic_cast<PongCore::BL::Data::Position::WallMoveData*>(moves[3].get());
            Assert::IsNotNull(wall);

            Assert::AreEqual(-100.0, wall->FieldWidth);
            Assert::AreEqual(-50.0, wall->FieldHeight);
        }
    };
}
