#include "pch.h"
#include "PongCore/UI/Paint/BallPainter.h"
#include "PongCore/BL/Data/Paint/BallViewData.h"

namespace Messerli::PongCore::UI::Paint {

namespace {

auto GetCenter(const BL::Data::Paint::AbstractViewData& obj) -> CPoint
{
    return dynamic_cast<const BL::Data::Paint::BallViewData*>(&obj)->Center;
}

}

auto BallPainter::Paint(CDC* dc, const BL::Data::Paint::AbstractViewData& obj) -> void
{
    CBrush brush(obj.Color);
    CBrush* oldBrush = dc->SelectObject(&brush);
    dc->Ellipse(GetCenter(obj).x - obj.Size, GetCenter(obj).y - obj.Size, GetCenter(obj).x + obj.Size, GetCenter(obj).y + obj.Size);
    dc->SelectObject(oldBrush);
}

}