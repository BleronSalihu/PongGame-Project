#pragma once
#include "PongCore/UI/Data/GameDifficulty.h"

namespace Messerli::PongCore::BL::Data::Tool {

class DefaultValuesGetter {
public:
    static auto GetDefaultValues(UI::Data::GameDifficulty difficulty) -> std::vector<int>;
};

}