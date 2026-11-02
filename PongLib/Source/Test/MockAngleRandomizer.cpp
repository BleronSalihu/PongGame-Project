#include "pch.h"
#include "Test/MockAngleRandomizer.h"

namespace Messerli::PongCore::Test {

MockAngleRandomizer::MockAngleRandomizer(double angle)
    : m_angle(angle)
{
}

auto MockAngleRandomizer::GetRandomAngle() -> double
{
    return m_angle;
}

}