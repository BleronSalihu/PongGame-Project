#include "pch.h"
#include "Test/MockMoveModelConverter.h"
#include "PongCore/BL/Data/Position/BallMoveData.h"
#include "PongCore/BL/Data/Position/PlayerMoveData.h"
#include "PongCore/BL/Data/Position/WallMoveData.h"

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes

namespace Messerli::PongCore::Test {

MockMoveModelConverter::MockMoveModelConverter()
{

}

auto MockMoveModelConverter::ConvertMove(BL::Data::PongDoc& doc)->std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>>
{
    std::vector<std::unique_ptr<BL::Data::Position::AbstractMoveData>> tempMoveModel;

    tempMoveModel.push_back(std::make_unique<BL::Data::Position::BallMoveData>(
        CPoint {50, 50},
        10,
        BL::Position::Type::Direction(45),
        10
    ));

    tempMoveModel.push_back(std::make_unique<BL::Data::Position::PlayerMoveData>(
        CPoint {10, 100},
        CPoint {10, 200},
        0,
        BL::Position::Type::Direction(0),
        10
    ));

    tempMoveModel.push_back(std::make_unique<BL::Data::Position::PlayerMoveData>(
        CPoint {300, 100},
        CPoint {300, 200},
        0,
        BL::Position::Type::Direction(0),
        10
    ));

    tempMoveModel.push_back(std::make_unique<BL::Data::Position::WallMoveData>(doc.Width, doc.Height));

    return tempMoveModel;
}

}