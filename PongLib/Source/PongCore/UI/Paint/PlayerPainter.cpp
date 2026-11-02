#include "pch.h"
#include "PongCore/UI/Paint/PlayerPainter.h"
#include "PongCore/BL/Data/Paint/PlayerViewData.h"

namespace Messerli::PongCore::UI::Paint {

namespace {

auto GetPos1(const BL::Data::Paint::AbstractViewData& obj) -> CPoint
{
    return dynamic_cast<const BL::Data::Paint::PlayerViewData*>(&obj)->Pos1;
}

auto GetPos2(const BL::Data::Paint::AbstractViewData& obj) -> CPoint
{
    return dynamic_cast<const BL::Data::Paint::PlayerViewData*>(&obj)->Pos2;
}

}

auto PlayerPainter::Paint(CDC* dc, const BL::Data::Paint::AbstractViewData& obj) -> void
{
    CBrush brush(obj.Color);
    CBrush* oldBrush = dc->SelectObject(&brush);
    dc->Rectangle(GetPos1(obj).x, GetPos1(obj).y - obj.Size, GetPos2(obj).x, GetPos2(obj).y + obj.Size);
    dc->SelectObject(oldBrush);
}

}