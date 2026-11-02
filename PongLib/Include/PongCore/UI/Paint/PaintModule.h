#pragma once
#include "PongCore/BL/Data/Paint/AbstractViewData.h"

namespace Messerli::PongCore::UI::Paint {

class PaintModule {
public:
    explicit PaintModule(CWnd* gameView);
    auto Paint(const std::vector<std::unique_ptr<BL::Data::Paint::AbstractViewData>>& viewModell) -> void;
private:
    CWnd* m_gameView;
};

}