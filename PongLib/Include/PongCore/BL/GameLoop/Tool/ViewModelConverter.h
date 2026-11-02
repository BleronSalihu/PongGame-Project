#pragma once
#include "AbstractViewModelConverter.h"

namespace Messerli::PongCore::BL::GameLoop::Tool {

class ViewModelConverter : public AbstractViewModelConverter {
public:
    auto ConvertView(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& positions, Data::PongDoc& doc) -> std::vector<std::unique_ptr<Data::Paint::AbstractViewData>> override;
};

}