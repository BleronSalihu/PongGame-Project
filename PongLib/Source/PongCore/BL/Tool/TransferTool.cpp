#include "pch.h"
#include "PongCore/BL/Tool/TransferTool.h"

namespace Messerli::PongCore::UI::Tool {

auto TransferTool::TransferColor(COLORREF& member, const COLORREF& dialogColor) -> void
{
    member = dialogColor;
}

auto TransferTool::TransferDigit(int& member, int dialogDigit) -> void
{
    member = dialogDigit;
}

}