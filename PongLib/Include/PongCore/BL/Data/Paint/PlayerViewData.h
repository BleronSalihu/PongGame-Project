#pragma once
#include "AbstractViewData.h"
#include "PongCore/BL/Data/AbstractType.h"

namespace Messerli::PongCore::BL::Data::Paint {

struct PlayerViewData : public AbstractViewData, public AbstractType {
    PlayerViewData(COLORREF color, CPoint pos1, CPoint pos2, int size);
    CPoint Pos1 {};
    CPoint Pos2 {};
    auto GetElement() -> GameElement override;
};

}