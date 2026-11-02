#include "pch.h"
#include "PongCore/UI/Paint/ObstaclePainter.h"
#include "PongCore/BL/Data/Paint/ObstacleViewData.h"

namespace Messerli::PongCore::UI::Paint {

namespace {

auto GetRect(const BL::Data::Paint::AbstractViewData& obj) -> CRect
{
    return dynamic_cast<const BL::Data::Paint::ObstacleViewData*>(&obj)->Rect;
}

}

auto ObstaclePainter::Paint(CDC* dc, const BL::Data::Paint::AbstractViewData& obj) -> void
{
    CBrush brush(obj.Color);
    CBrush* oldBrush = dc->SelectObject(&brush);
    CRect rect = GetRect(obj);
    dc->Rectangle(rect);
    dc->SelectObject(oldBrush);
}

}