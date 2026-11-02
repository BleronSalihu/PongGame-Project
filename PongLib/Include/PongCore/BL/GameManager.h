#pragma once
#include "PongCore/BL/Data/PongDoc.h"
#include "PongCore/UI/PongView.h"
#include "PongCore/UI/MainFrm.h"
#include "PongCore/BL/GameLoop/GameLoop.h"
#include "PongCore/BL/Collision/Tool/CollisionCollector.h"
#include "PongCore/BL/Collision/Calculation/CalculationModule.h"
#include "PongCore/BL/Collision/Detection/DetectionModule.h"
#include "PongCore/BL/GameLoop/Tool/ModelUpdater.h"
#include "PongCore/BL/Position/Tool/AngleRandomizer.h"
#include "PongCore/BL/GameLoop/Tool/AIPlayer.h"
#include "PongCore/UI/Tool/ResultHandler.h"
#include "PongCore/UI/Paint/ResultPainter.h"
#include "PongCore/BL/GameLoop/Tool/MoveModelConverter.h"
#include "PongCore/BL/GameLoop/Tool/ViewModelConverter.h"
#include "PongCore/BL/GameLoop/GameElement/ObstacleManager.h"
#include "AbstractPongApp.h"
#include "AbstractGame.h"
#include <thread>

namespace Messerli::PongCore::BL {

extern "C"
class GameManager : public AbstractGame {
public:
    virtual ~GameManager();
    auto Init() -> void override;
    auto Show(AbstractPongApp& theApp) -> void override;
private:
    auto SetUp() -> std::tuple<UI::Data::GameMode, UI::Data::GameDifficulty, UI::Data::GameReflectation>;
    auto Start() -> void;
    auto Pause() -> void;
    auto Resume() -> void;
    auto End() -> void;
    std::unique_ptr<Data::PongDoc> m_doc;
    std::unique_ptr<UI::MainFrame> m_mainFrame;
    std::unique_ptr<GameLoop::GameLoop> m_gameLoop;
    std::thread m_loopThread;

    std::unique_ptr<Position::Tool::AbstractAngleRandomizer>           m_angleRandomizer = std::make_unique<Position::Tool::AngleRandomizer>();
    std::unique_ptr<Collision::Calculation::AbstractCalculationModule> m_calculationModule = std::make_unique<Collision::Calculation::CalculationModule>();
    std::unique_ptr<Collision::Detection::AbstractDetectionModule>     m_detectionModule = std::make_unique<Collision::Detection::DetectionModule>();
    std::unique_ptr<Collision::Tool::AbstractCollisionCollector>       m_collisionCollector = std::make_unique<Collision::Tool::CollisionCollector>();
    std::unique_ptr<GameLoop::Tool::AbstractModelUpdater>              m_modelUpdater = std::make_unique<GameLoop::Tool::ModelUpdater>();
    std::unique_ptr<UI::Tool::AbstractResultHandler>                   m_resultHandler = std::make_unique<UI::Tool::ResultHandler>();
    std::unique_ptr<UI::Paint::AbstractResultPainter>                  m_resultPainter = std::make_unique<UI::Paint::ResultPainter>();
    std::unique_ptr<GameLoop::Tool::AbstractAIPlayer>                  m_AIPlayer = std::make_unique<GameLoop::Tool::AIPlayer>();
    std::unique_ptr<GameLoop::Tool::AbstractMoveModelConverter>        m_moveModelConverter = std::make_unique<GameLoop::Tool::MoveModelConverter>();
    std::unique_ptr<GameLoop::Tool::AbstractViewModelConverter>        m_viewModelConverter = std::make_unique<GameLoop::Tool::ViewModelConverter>();
    std::unique_ptr<GameLoop::GameElement::AbstractObstacleManager>    m_obstacleManager;
};

}