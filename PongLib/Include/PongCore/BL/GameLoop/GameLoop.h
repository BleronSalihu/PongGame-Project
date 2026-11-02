#pragma once
#include "PongCore/BL/Data/Paint/AbstractViewData.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Data/Collision/AbstractCollisionData.h"
#include "PongCore/BL/Data/PongDoc.h"
#include "PongCore/BL/Collision/CollisionModule.h"
#include "PongCore/BL/Position/PositionModule.h"
#include "PongCore/UI/Paint/PaintModule.h"
#include "PongCore/BL/GameLoop/Tool/ModelUpdater.h"
#include "PongCore/BL/GameLoop/Tool/AIPlayer.h"
#include "PongCore/UI/Tool/ResultHandler.h"
#include "PongCore/UI/Paint/ResultPainter.h"
#include "PongCore/BL/GameLoop/Tool/MoveModelConverter.h"
#include "PongCore/BL/GameLoop/Tool/ViewModelConverter.h"
#include "PongCore/BL/GameLoop/GameElement/ObstacleManager.h"

namespace Messerli::PongCore::BL::GameLoop {

class GameLoop {
public:
    GameLoop(Data::PongDoc& doc, Collision::Tool::AbstractCollisionCollector& collisionCollector,
        Collision::Calculation::AbstractCalculationModule& calculationModule,
        Collision::Detection::AbstractDetectionModule& detectionModule,
        Tool::AbstractModelUpdater& modelUpdater,
        UI::Tool::AbstractResultHandler& resultHandler,
        UI::Paint::AbstractResultPainter& resultPainter,
        Tool::AbstractAIPlayer& AIPlayer,
        Tool::AbstractMoveModelConverter& moveModelConverter,
        Tool::AbstractViewModelConverter& viewModelConverter,
        GameElement::AbstractObstacleManager& obstacleManager);
    auto operator() () -> void;
    auto SetFlag(bool flag) -> void;
    auto SetPause(bool flag) -> void;
private:
    Data::PongDoc& m_doc;
    std::atomic<bool> m_isRunning;
    std::atomic<bool> m_paused;

    std::unique_ptr<Position::PositionModule> m_positionModule;
    std::unique_ptr<Collision::CollisionModule> m_collisionModule;
    std::unique_ptr<UI::Paint::PaintModule> m_paintModule;
    Tool::AbstractModelUpdater& m_modelUpdater;
    UI::Tool::AbstractResultHandler& m_resultHandler;
    UI::Paint::AbstractResultPainter& m_resultPainter;
    Tool::AbstractAIPlayer& m_AIPlayer;
    Tool::AbstractMoveModelConverter& m_moveModelConverter;
    Tool::AbstractViewModelConverter& m_viewModelConverter;
    GameElement::AbstractObstacleManager& m_obstacleManager;

    auto RunLoop() -> void;
};

}