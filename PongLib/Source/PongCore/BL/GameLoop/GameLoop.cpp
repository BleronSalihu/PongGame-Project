#include "pch.h"
#include "PongCore/BL/GameLoop/GameLoop.h"
#include "PongCore/BL/Data/Paint/BallViewData.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Paint/PlayerViewData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/GameLoop/Tool/LoopTimer.h"
#include "PongCore/BL/Data/Collision/BallCollisionData.h"
#include "PongCore/BL/Data/Collision/PlayerCollisionData.h"


namespace Messerli::PongCore::BL::GameLoop {

GameLoop::GameLoop(Data::PongDoc& doc, Collision::Tool::AbstractCollisionCollector& collisionCollector,
    Collision::Calculation::AbstractCalculationModule& calculationModule,
    Collision::Detection::AbstractDetectionModule& detectionModule,
    Tool::AbstractModelUpdater& modelUpdater,
    UI::Tool::AbstractResultHandler& resultHandler,
    UI::Paint::AbstractResultPainter& resultPainter,
    Tool::AbstractAIPlayer& AIPlayer,
    Tool::AbstractMoveModelConverter& moveModelConverter,
    Tool::AbstractViewModelConverter& viewModelConverter,
    GameElement::AbstractObstacleManager& obstacleManager)
    : m_doc(doc),
    m_isRunning(false),
    m_modelUpdater(modelUpdater),
    m_resultHandler(resultHandler),
    m_resultPainter(resultPainter),
    m_AIPlayer(AIPlayer),
    m_moveModelConverter(moveModelConverter),
    m_viewModelConverter(viewModelConverter),
    m_obstacleManager(obstacleManager)
{
    m_collisionModule = std::make_unique<Collision::CollisionModule>(collisionCollector, calculationModule, detectionModule);
    m_positionModule = std::make_unique<Position::PositionModule>();
    m_paintModule = std::make_unique<UI::Paint::PaintModule>(m_doc.GetWnd());
    m_obstacleManager.Initialize(m_moveModelConverter.ConvertMove(m_doc));
}

auto GameLoop::RunLoop() -> void
{
    std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> moveModel {};
    std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> moveResultModel {};
    moveModel = m_moveModelConverter.ConvertMove(m_doc);
    std::vector<std::unique_ptr<Data::Paint::AbstractViewData>> viewModel {};
    std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>> collisionModel {};
    std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>> collisionResultModel {};

    while (m_isRunning) {
        if (m_paused) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        Tool::LoopTimer timer;
        timer.Start();

        m_obstacleManager.Update(moveModel, m_doc);
        m_modelUpdater.UpdateMoveModel(moveModel, m_doc);
        if (std::get<0>(m_doc.GameStartUp) == UI::Data::GameMode::Singleplayer) {
            m_AIPlayer.Move(moveModel, m_doc);
        }
        moveResultModel = std::move(m_positionModule->CalculatePosition(moveModel));
        collisionResultModel = std::move(m_collisionModule->Calculate(moveModel, moveResultModel, std::get<2>(m_doc.GameStartUp)));
        moveResultModel = m_modelUpdater.UpdateMoveResultModel(collisionResultModel, moveResultModel, m_doc);
        m_resultHandler.HandleResult(moveResultModel, m_doc);
        viewModel = m_viewModelConverter.ConvertView(moveResultModel, m_doc);
        m_paintModule->Paint(viewModel);
        m_resultPainter.Paint(*m_doc.GetWnd(), m_doc);
        m_modelUpdater.UpdateMoveModel(moveModel, moveResultModel);

        timer.End();
        timer.Sleep();
    }
}

auto GameLoop::operator() () -> void
{
    m_isRunning = true;
    RunLoop();
}

auto GameLoop::SetFlag(bool flag) -> void
{
    m_isRunning = flag;
}

auto GameLoop::SetPause(bool flag) -> void
{
    m_paused = flag;
}

}