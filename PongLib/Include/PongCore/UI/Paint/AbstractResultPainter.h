#pragma once
#include "PongCore/BL/Data/PongDoc.h"

namespace Messerli::PongCore::UI::Paint {

class AbstractResultPainter {
public:
    virtual auto Paint(CWnd& gameView, BL::Data::PongDoc& doc) -> void abstract;
};

}