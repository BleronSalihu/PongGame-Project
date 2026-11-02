#include "pch.h"
#include "PongCore/UI/Paint/ResultPainter.h"

namespace Messerli::PongCore::UI::Paint {

auto ResultPainter::Paint(CWnd& gameView, BL::Data::PongDoc& doc) -> void
{
    CClientDC localDC(&gameView);
    localDC.SetTextAlign(TA_CENTER);
    localDC.TextOut(doc.Width / 2, 20, CString(std::to_wstring(doc.Player1.PlayerScore).c_str()));
    localDC.TextOut(doc.Width / 2 + 50, 20, CString(":"));
    localDC.TextOut(doc.Width / 2 + 100, 20, CString(std::to_wstring(doc.Player2.PlayerScore).c_str()));
}

}