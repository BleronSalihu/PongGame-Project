#pragma once
#include "AbstractViewData.h"
#include "PongCore/BL/Data/AbstractType.h"

namespace Messerli::PongCore::BL::Data::Paint {

struct BallViewData : public AbstractViewData, public AbstractType {
    BallViewData(COLORREF color, CPoint center, int size);
    CPoint Center {};
    auto GetElement() -> GameElement override;
};

}