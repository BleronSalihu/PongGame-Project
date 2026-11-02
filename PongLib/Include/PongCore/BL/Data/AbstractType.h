#pragma once
#include "PongCore/BL/Data/GameElements.h"

namespace Messerli::PongCore::BL::Data {

struct AbstractType {
public:
    GameElement Element = GameElement::Invalid;
protected:
    explicit AbstractType(GameElement element)
        : Element(element)
    {}
};

}