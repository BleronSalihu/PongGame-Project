#pragma once
#include "AbstractViewData.h"
#include "PongCore/BL/Data/AbstractType.h"

namespace Messerli::PongCore::BL::Data::Paint {

struct ObstacleViewData : public AbstractViewData, public AbstractType {
public:
    ObstacleViewData(CRect rect);
    auto GetElement() -> GameElement override;
    CRect Rect {};
};

}