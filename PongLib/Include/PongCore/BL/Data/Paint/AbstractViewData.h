#pragma once
#include "PongCore/BL/Data/GameElements.h"

namespace Messerli::PongCore::BL::Data::Paint {

struct AbstractViewData {
    COLORREF Color {};
    int Size = 0;
    virtual ~AbstractViewData() = default;
    virtual auto GetElement() -> GameElement abstract;
};

}