#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "PongCore/BL/Data/Position/AbstractMoveData.h"
#include "PongCore/BL/Data/AbstractType.h"

namespace Messerli::PongCore::BL::Data::Position {

struct PONGCORE_API ObstacleMoveData : public AbstractMoveData, public AbstractType {
public:
    ObstacleMoveData(CPoint center, int size);
    auto GetElement() const->GameElement override;
    int Size;
    CPoint Center;
};

}