#pragma once
#include "PongCore/BL/PongCore_API.h"
#include "BallPainter.h"
#include "PlayerPainter.h"
#include "ObstaclePainter.h"
#include "PongCore/BL/Data/GameElements.h"

namespace Messerli::PongCore::UI::Paint {

class PONGCORE_API PaintFactory {
public:
    static auto Create(BL::Data::GameElement element) -> std::unique_ptr<AbstractPainter>;
};

}