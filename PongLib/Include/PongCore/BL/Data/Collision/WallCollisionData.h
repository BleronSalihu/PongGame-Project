#pragma once
#include "AbstractCollisionData.h"
#include "PongCore/BL/Data/AbstractType.h"

namespace Messerli::PongCore::BL::Data::Collision {

struct WallCollisionData : public AbstractCollisionData, public AbstractType {
    WallCollisionData(int fieldWidth, int fieldHeight, CPoint pos1, CPoint pos2);
    int FieldWidth = 0;
    int FieldHeight = 0;
    CPoint Pos1;
    CPoint Pos2;
    auto GetElement() -> GameElement override;
};

}