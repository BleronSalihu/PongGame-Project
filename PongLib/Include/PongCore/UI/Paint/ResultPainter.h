#pragma once
#include "AbstractResultPainter.h"

namespace Messerli::PongCore::UI::Paint {

class ResultPainter : public AbstractResultPainter {
public:
    auto Paint(CWnd& gameView, BL::Data::PongDoc& doc) -> void override;
};

}