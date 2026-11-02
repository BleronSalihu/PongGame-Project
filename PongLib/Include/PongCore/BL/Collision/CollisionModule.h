#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/Collision/AbstractCollisionData.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Collision/Tool/CollisionCollector.h"
#include "PongCore/BL/Collision/Calculation/CalculationModule.h"
#include "PongCore/BL/Collision/Detection/DetectionModule.h"

namespace Messerli::PongCore::BL::Collision {

class PONGCORE_API CollisionModule {
public:
    CollisionModule(Tool::AbstractCollisionCollector& collisionCollector, Calculation::AbstractCalculationModule& calculationModule,
        Detection::AbstractDetectionModule& detectionModule);
    auto Calculate(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelFirstPosition,
        const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelEndPosition, 
        UI::Data::GameReflectation reflectation) -> std::vector<std::unique_ptr<Data::Collision::AbstractCollisionData>>;
private:
    Tool::AbstractCollisionCollector& m_collisionCollector;
    Calculation::AbstractCalculationModule& m_calculationModule;
    Detection::AbstractDetectionModule& m_detectionModule;

};

}