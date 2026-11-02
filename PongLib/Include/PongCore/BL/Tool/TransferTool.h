#pragma once
#include "PongCore/BL/Data/PongDoc.h"
#include "PongCore/UI/Tool/SettingsDialog.h"

namespace Messerli::PongCore::UI::Tool {

class TransferTool {
public:
    static auto TransferColor(COLORREF& member, const COLORREF& dialogColor) -> void;
    static auto TransferDigit(int& member, int dialogDigit) -> void;
};

}