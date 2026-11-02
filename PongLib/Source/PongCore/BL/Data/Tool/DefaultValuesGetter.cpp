#include "pch.h"
#include "PongCore/BL/Data/Tool/DefaultValuesGetter.h"

namespace Messerli::PongCore::BL::Data::Tool {

namespace {

constexpr int SMALL = -10;
constexpr int MEDIUM = 15;
constexpr int LARGE = 25;
constexpr int NOOBLARGE = 50;

constexpr int SLOW = 4;
constexpr int NORMAL = 7;
constexpr int FAST = 10;
constexpr int FLASH = 13;

const std::vector<int> EasyDefaultValues {
    NOOBLARGE,
    NORMAL,
    LARGE,
    FAST
};

const std::vector<int> MediumDefaultValues {
    MEDIUM,
    FAST,
    SMALL,
    NORMAL
};

const std::vector<int> HardDefaultValues {
    MEDIUM,
    FLASH,
    MEDIUM,
    NORMAL
};

const std::vector<int> ExtremeDefaultValues {
    MEDIUM,
    FLASH,
    SMALL,
    SLOW
};

}

auto DefaultValuesGetter::GetDefaultValues(UI::Data::GameDifficulty difficulty) -> std::vector<int>
{
    switch (difficulty) {
        case UI::Data::GameDifficulty::Easy:
            return EasyDefaultValues;
        case UI::Data::GameDifficulty::Medium:
            return MediumDefaultValues;
        case UI::Data::GameDifficulty::Hard:
            return HardDefaultValues;
        case UI::Data::GameDifficulty::Extreme:
            return ExtremeDefaultValues;
        case UI::Data::GameDifficulty::Invalid:
            return {};
        default:
            return {};
    }
}

}