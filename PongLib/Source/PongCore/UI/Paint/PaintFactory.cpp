#include "pch.h"
#include "PongCore/UI/Paint/PaintFactory.h"

namespace Messerli::PongCore::UI::Paint {

auto PaintFactory::Create(BL::Data::GameElement element) -> std::unique_ptr<AbstractPainter>
{
    switch (element) {
        case BL::Data::GameElement::Ball:
            return std::make_unique<BallPainter>();
        case BL::Data::GameElement::Player:
            return std::make_unique<PlayerPainter>();
        case BL::Data::GameElement::Obstacle:
            return std::make_unique<ObstaclePainter>();
        default:
            return {};
    }
}

}