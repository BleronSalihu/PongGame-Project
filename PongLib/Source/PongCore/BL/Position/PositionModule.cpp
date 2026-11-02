#include "pch.h"
#include "PongCore/BL/Position/PositionModule.h"
#include "PongCore/BL/Position/PositionFactory.h"

namespace Messerli::PongCore::BL::Position {

auto PositionModule::CalculatePosition(std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModell) -> std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>
{
    std::vector<std::unique_ptr<Data::Position::AbstractMoveData>> tempMoveModel;
    for (auto& obj : moveModell) {
        let calculater = PositionFactory::Create(obj->GetElement());
        if (calculater) {
            auto newObj = calculater->CalculatePosition(*obj);
            tempMoveModel.push_back(std::move(newObj));
        }
    }
    return tempMoveModel;
}

}