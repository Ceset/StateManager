#ifndef STATESMANAGER_H
#define STATESMANAGER_H

#include <map>
#include <memory>
#include <algorithm>
#include "state.h"

// This class is a manager to contain and manage
// all state classes. If you ever desires to add,
// remove or anything that is wanted this class
// just use functions that are provided by the
// manager class.
//
// In most cases the last added states will be 
// rendered to the top. So it will just update, 
// render according to adding order.
//
// If you need furture features you should make 
// changes at the class.

class StatesManager
{
public:
    StatesManager();

    // A function to add a new state. It will require a unique
    // state identifier.
    void addState(std::unique_ptr<State> state, StateID identifier);
    // Get the state as a pointer. If needs be.
    State* getState(StateID identifier);

    // Just remove one specific state.
    void removeState(StateID identifier);
    // Remove all added state except one specific state.
    void removeAllStatesExcept(StateID identifier);
    // Remove all added states.
    void removeAllStates();

    // Updates all added states.
    void updateStates();
    // Renders all added states.
    void renderStates();

private:
    // The container of our states.
    std::map<StateID, std::unique_ptr<State>> mStates;
};

#endif // STATESMANAGER_H
