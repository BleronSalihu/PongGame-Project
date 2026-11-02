#include "pch.h"
#include "PongCore/BL/GameManager.h"
#include "PongCore/UI/MainFrm.h"
#include "PongCore/UI/Tool/StartUpDialog.h"

namespace Messerli::PongCore::BL {

GameManager::~GameManager()
{
    m_mainFrame.release();
}

auto GameManager::Init() -> void
{
    let startUp = [this]() { return SetUp(); };
    m_doc = std::make_unique<Data::PongDoc>(startUp(), *m_angleRandomizer);

    let gameStart = [this]() { Start(); };
    let endGame = [this]() { End(); };
    let pauseGame = [this]() { Pause(); };
    let resumeGame = [this]() { Resume(); };

    auto* view = new UI::PongView(*m_doc);
    m_mainFrame = std::make_unique<Messerli::PongCore::UI::MainFrame>(Messerli::PongCore::UI::MainFrame::ClassParams {view, 
        *m_doc, 
        gameStart, 
        pauseGame, 
        resumeGame, 
        endGame}
    );

    m_doc->SetView(view);

    m_obstacleManager = std::make_unique<GameLoop::GameElement::ObstacleManager>(*m_doc);
    m_gameLoop = std::make_unique<BL::GameLoop::GameLoop>(
        *m_doc, 
        *m_collisionCollector, 
        *m_calculationModule, 
        *m_detectionModule,
        *m_modelUpdater, 
        *m_resultHandler, 
        *m_resultPainter, 
        *m_AIPlayer, 
        *m_moveModelConverter, 
        *m_viewModelConverter, 
        *m_obstacleManager
    );
}

auto GameManager::SetUp() -> std::tuple<UI::Data::GameMode, UI::Data::GameDifficulty, UI::Data::GameReflectation>
{
    PongCore::UI::Tool::StartUpDialog dialog;
    if (dialog.DoModal() == IDOK) {
        return { dialog.GetGameMode(), dialog.GetDifficulty(), dialog.GetReflectation() };
    }
    return { UI::Data::GameMode::Invalid, UI::Data::GameDifficulty::Invalid, UI::Data::GameReflectation::Invalid };
}

auto GameManager::Start() -> void
{
    m_gameLoop->SetFlag(true);
    m_gameLoop->SetPause(false);
    m_doc->UpdateRect();

    if (m_loopThread.joinable()) {
        m_loopThread.join();
    }

    m_loopThread = std::thread(std::ref(*m_gameLoop));
}

auto GameManager::End() -> void
{
    m_gameLoop->SetFlag(false);
    if (m_loopThread.joinable()) {
        m_loopThread.join();
    }
}

auto GameManager::Pause() -> void
{
    m_gameLoop->SetPause(true);
}

auto GameManager::Resume() -> void
{
    m_gameLoop->SetPause(false);
}

auto GameManager::Show(AbstractPongApp& theApp) -> void
{
    theApp.SetMainWindow(&*m_mainFrame);
    theApp.GetMainWindow()->ShowWindow(theApp.GetInitialShowProperty());
    theApp.GetMainWindow()->UpdateWindow();
}

}