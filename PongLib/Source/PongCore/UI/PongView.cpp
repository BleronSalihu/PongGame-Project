#include "pch.h"
#include "PongCore/UI/PongView.h"

namespace Messerli::PongCore::UI {

BEGIN_MESSAGE_MAP(PongView, CView)
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


PongView::PongView(BL::Data::PongDoc& doc)
    : m_doc(doc)
{
}

void PongView::OnDraw(CDC* pDC)
{
}

auto PongView::OnKeyDown(UINT Char, UINT repCnt, UINT flags) -> void
{
    switch (Char) {
        case VK_UP:
            m_doc.Player2.PlayerDirection.SetAngle(270.0);
            m_doc.Player2.PlayerSpeed = m_doc.DefaultValues->Player2Speed;
            break;
        case VK_DOWN:
            m_doc.Player2.PlayerDirection.SetAngle(90.0);
            m_doc.Player2.PlayerSpeed = m_doc.DefaultValues->Player2Speed;
            break;
        case 'W':
        case 'w':
            if (std::get<0>(m_doc.GameStartUp) != Data::GameMode::Singleplayer) {
                m_doc.Player1.PlayerDirection.SetAngle(270.0);
                m_doc.Player1.PlayerSpeed = m_doc.DefaultValues->Player1Speed;
            }
            break;
        case 'S':
        case 's':
            if (std::get<0>(m_doc.GameStartUp) != Data::GameMode::Singleplayer) {
                m_doc.Player1.PlayerDirection.SetAngle(90.0);
                m_doc.Player1.PlayerSpeed = m_doc.DefaultValues->Player1Speed;
            }
            break;
        default:
            CView::OnKeyDown(Char, repCnt, flags);
    }
}

auto PongView::OnKeyUp(UINT Char, UINT repCnt, UINT flags) -> void
{
    switch (Char) {
        case VK_UP:
            m_doc.Player2.PlayerSpeed = 0;
            break;
        case VK_DOWN:
            m_doc.Player2.PlayerSpeed = 0;
            break;
        case 'W':
        case 'w':
            m_doc.Player1.PlayerSpeed = 0;
            break;
        case 'S':
        case 's':
            m_doc.Player1.PlayerSpeed = 0;
            break;
        default:
            CView::OnKeyUp(Char, repCnt, flags);
    }
}

auto PongView::OnEraseBkgnd(CDC* pDC) -> BOOL
{
    return TRUE;
}

}