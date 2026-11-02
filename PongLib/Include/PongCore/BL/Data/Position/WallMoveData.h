#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/AbstractType.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"

namespace Messerli::PongCore::BL::Data::Position {

struct PONGCORE_API WallMoveData : public AbstractMoveData, public AbstractType {
    WallMoveData(double fieldWidth, double fieldHeight);
    double FieldWidth = 0.0;
    double FieldHeight = 0.0;
    auto GetElement() const->GameElement override;
};

}