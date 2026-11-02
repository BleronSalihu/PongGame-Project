#pragma once
#include "AbstractPainter.h"

namespace Messerli::PongCore::UI::Paint {

class BallPainter : public AbstractPainter {
public:
    auto Paint(CDC* dc, const BL::Data::Paint::AbstractViewData& obj) -> void override;
};

}