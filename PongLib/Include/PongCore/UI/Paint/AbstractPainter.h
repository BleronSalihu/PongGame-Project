#pragma once
#include "PongCore/BL/Data/Paint/AbstractViewData.h"

namespace Messerli::PongCore::UI::Paint {

class AbstractPainter abstract {
public:
    virtual auto Paint(CDC* dc, const BL::Data::Paint::AbstractViewData& obj) -> void abstract;
};

}