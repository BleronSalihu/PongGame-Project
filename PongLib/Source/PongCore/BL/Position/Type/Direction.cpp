#include "pch.h"
#include "PongCore/BL/Position/Type/Direction.h"

namespace Messerli::PongCore::BL::Position::Type {

Direction::Direction(double angle)
    : m_angle(angle)
{
}

auto Direction::GetAngle() const -> double
{
    return m_angle;
}

auto Direction::SetAngle(double newAngle) -> void
{
    m_angle = newAngle;
}

auto Direction::ToRadian() -> double
{
    let PI = 3.14159;
    return m_angle * PI / 180.0;
}

}