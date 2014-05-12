#include "statesmanager.h"

StatesManager::StatesManager()
{
}

void StatesManager::addState(std::unique_ptr<State> state, StateID identifier)
{
    mStates.insert(std::make_pair(identifier, std::move(state)));
}

State* StatesManager::getState(StateID identifier)
{
    return mStates.at(identifier).get();
}

void StatesManager::removeState(StateID identifier)
{
    mStates.erase(identifier);
}

void StatesManager::removeAllStatesExcept(StateID identifier)
{
    for(std::map<StateID, std::unique_ptr<State>>::iterator itr = mStates.begin(); itr != mStates.end(); )
    {
        if( itr->first != identifier )
            itr = mStates.erase(itr);
        else ++itr;
    }
}

void StatesManager::removeAllStates()
{
    mStates.clear();
}

void StatesManager::updateStates()
{
    for(auto& state : mStates)
        std::get<1>(state).get()->update();
}

void StatesManager::renderStates()
{
    for(auto& state : mStates)
        std::get<1>(state).get()->render();
}
