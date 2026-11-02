#include "pch.h"
#include "PongCore/UI/Paint/PaintModule.h"
#include "PongCore/UI/Paint/PaintFactory.h"

namespace Messerli::PongCore::UI::Paint {

PaintModule::PaintModule(CWnd* gameView)
    : m_gameView(gameView)
{
}

auto PaintModule::Paint(const std::vector<std::unique_ptr<BL::Data::Paint::AbstractViewData>>& viewModell) -> void
{
    CClientDC localDC(m_gameView);
    CRect rect;
    m_gameView->GetClientRect(&rect);
    let width = rect.Width();
    let height = rect.Height();
    CDC memDC;
    memDC.CreateCompatibleDC(&localDC);
    CBitmap memBitmap;
    memBitmap.CreateCompatibleBitmap(&localDC, width, height);
    CBitmap* pOldBitmap = memDC.SelectObject(&memBitmap);
    memDC.PatBlt(0, 0, width, height, WHITENESS);
    for (auto& obj : viewModell) {
        let painter = PaintFactory::Create(obj->GetElement());
        painter->Paint(&memDC, *obj);
    }
    localDC.BitBlt(0, 0, width, height, &memDC, 0, 0, SRCCOPY);
    memDC.SelectObject(pOldBitmap);
}

}