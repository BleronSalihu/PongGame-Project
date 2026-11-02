#include "pch.h"
#include "PongCore/BL/Collision/Tool/CollisionCollector.h"
#define NOMINMAX

namespace Messerli::PongCore::BL::Collision::Tool {

namespace {

const std::map<Data::GameElement, Type::CollisionType> Active {
    {Data::GameElement::Ball, Type::CollisionType::Reflection},
    {Data::GameElement::Player, Type::CollisionType::Standstill},
    {Data::GameElement::Wall, Type::CollisionType::None},
    {Data::GameElement::Obstacle, Type::CollisionType::None}
};

const std::map<Data::GameElement, Type::CollisionType> Passive {
    {Data::GameElement::Ball, Type::CollisionType::Reflection},
    {Data::GameElement::Player, Type::CollisionType::None},
    {Data::GameElement::Wall, Type::CollisionType::None},
    {Data::GameElement::Obstacle, Type::CollisionType::None}
};

}

auto CollisionCollector::ConvertCollision(const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelfirstPosition,
    const std::vector<std::unique_ptr<Data::Position::AbstractMoveData>>& moveModelEndPosition) -> std::vector<Type::CollisionPair>&
{
    static std::vector<Type::CollisionPair> collisionPair;
    collisionPair.clear();

    let firstCount = moveModelfirstPosition.size();
    let endCount = moveModelEndPosition.size();
    let n = (firstCount > endCount) ? firstCount : endCount;

    for (size_t i = 0; i < n; ++i) {
        let iFirst = (i < firstCount ? i : firstCount - 1);
        let iEnd = (i < endCount ? i : endCount - 1);
        let& aFirst = *moveModelfirstPosition[iFirst];
        let& aEnd = *moveModelEndPosition[iEnd];
        let  aActive = Active.at(aEnd.GetElement());

        for (size_t j = 0; j < n; ++j) {
            let jFirst = (j < firstCount ? j : firstCount - 1);
            let jEnd = (j < endCount ? j : endCount - 1);
            let& pFirst = *moveModelfirstPosition[jFirst];
            let& pEnd = *moveModelEndPosition[jEnd];
            let  pPassive = Passive.at(pEnd.GetElement());

            collisionPair.push_back(Type::CollisionPair(aFirst, aEnd, aActive, pFirst, pEnd, pPassive));
        }
    }
    return collisionPair;
}

}