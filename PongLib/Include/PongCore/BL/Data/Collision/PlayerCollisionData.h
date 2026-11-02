#pragma once
#include "AbstractCollisionData.h"
#include "PongCore/BL/Data/AbstractType.h"

namespace Messerli::PongCore::BL::Data::Collision {

struct PlayerCollisionData : public AbstractCollisionData, public AbstractType {
    PlayerCollisionData(CPoint pos1, CPoint pos2);
    CPoint Pos1;
    CPoint Pos2;
    auto GetElement() -> GameElement override;
};

}