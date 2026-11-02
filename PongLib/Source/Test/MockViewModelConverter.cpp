#include "pch.h"
#include "Test/MockViewModelConverter.h"
#include "PongCore/BL/Data/Paint/BallViewData.h"
#include "PongCore/BL/Data/Paint/PlayerViewData.h"

namespace Messerli::PongCore::Test {

MockViewModelConverter::MockViewModelConverter()
{

}

auto MockViewModelConverter::ConvertView(const std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>& positions, BL::Data::PongDoc& doc)->std::vector<std::unique_ptr<BL::Data::Paint::AbstractViewData>>
{
    std::vector<std::unique_ptr<BL::Data::Paint::AbstractViewData>> tempViewModel;


    tempViewModel.push_back(std::make_unique<BL::Data::Paint::BallViewData>(
        doc.Ball.BallColor,
        CPoint(100, 100),
        doc.Ball.BallSize
    ));

    tempViewModel.push_back(std::make_unique<BL::Data::Paint::PlayerViewData>(
        doc.Player1.PlayerColor,
        CPoint(10, 100),
        CPoint(10, 200),
        doc.Player1.PlayerSize
    ));

    tempViewModel.push_back(std::make_unique<BL::Data::Paint::PlayerViewData>(
        doc.Player2.PlayerColor,
        CPoint(300, 100),
        CPoint(300, 200),
        doc.Player2.PlayerSize
    ));

    return tempViewModel;
}

}