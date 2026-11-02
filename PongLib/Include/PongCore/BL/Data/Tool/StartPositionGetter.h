#pragma once
#include "PongCore/BL/Data/PongDoc.h"

namespace Messerli::PongCore::BL::Data::Tool {

class StartPositionGetter {
public:
    static auto GetBallStartPos(PongDoc& doc) -> CPoint;
    static auto GetPlayer1StartPos1(PongDoc& doc) -> CPoint;
    static auto GetPlayer1StartPos2(PongDoc& doc) -> CPoint;
    static auto GetPlayer2StartPos1(PongDoc& doc) -> CPoint;
    static auto GetPlayer2StartPos2(PongDoc& doc) -> CPoint;
};

}