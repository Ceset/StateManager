#ifndef STATESMANAGER_H
#define STATESMANAGER_H

#include <map>
#include <memory>
#include "state.h"

// This class is a manager to contain and manage
// all state classes.
//
// It will use adding order to update

class StatesManager
{
public:
    StatesManager();

    // A function to add a new state
    void addState(StateID identifier, std::unique_ptr<State> state);

    // Get the state as a pointer
    State *getState(StateID identifier);

    // Just remove one specific state
    void removeState(StateID identifier);

    // Remove all added state except one state
    void removeAllStatesExcept(StateID identifier);

    // Remove all added states
    void removeAllStates();

    // Updates all added states
    void updateStates();

private:
    // The container of our states.
    std::map<StateID, std::unique_ptr<State>> mStates;
};

#endif // STATESMANAGER_H
