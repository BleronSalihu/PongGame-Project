#pragma once
#include "PongCore/BL/Data/PongDoc.h"

namespace Messerli::PongCore::UI {

class PongView : public CView {
    DECLARE_MESSAGE_MAP();
public:
    explicit PongView(BL::Data::PongDoc& doc);
    virtual void OnDraw(CDC* pDC);
private:
    BL::Data::PongDoc& m_doc;
    afx_msg auto OnKeyDown(UINT Char, UINT repCnt, UINT flags) -> void;
    afx_msg auto OnKeyUp(UINT Char, UINT repCnt, UINT flags) -> void;
    afx_msg auto OnEraseBkgnd(CDC* pDC) -> BOOL;
};

}