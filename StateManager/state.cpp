#include "state.h"

State::State()
{
}

State::~State()
{
}

bool State::isActive()
{
    return m_isActive;
}

void State::setActive(bool isTrue)
{
    m_isActive = isTrue;
}
