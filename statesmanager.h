#ifndef STATESMANAGER_H
#define STATESMANAGER_H

#include <map>
#include <memory>
#include <algorithm>
#include "state.h"

class StatesManager
{
public:
    StatesManager();

    void addState(std::unique_ptr<State> state, StateID identifier);
    State* getState(StateID identifier);

    void removeState(StateID identifier);
    void removeAllStatesExcept(StateID identifier);
    void removeAllStates();

    void checkStates();
    void updateStates();
    void renderStates();

private:
    std::map<StateID, std::unique_ptr<State>> mStates;
};

#endif // STATESMANAGER_H
