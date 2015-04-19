#include <iostream>
#include "StateManager/statesmanager.h"

// WARNING: Dont forget you have to define StateID where
// you are using. It is declared inside 'state.h'
enum class StateID{
    foo,
    bar,
    dummy
};

// Example state class
class FooState : public State {
public:
    FooState()
    {
    }

    void update() override
    {
        std::cout << "Update : foo" << std::endl;
    }
};

// Example state class
class BarState : public State {
public:
    BarState()
    {
    }

    void update() override
    {
        std::cout << "Update : bar" << std::endl;
    }
};

// Example state class
class DummyState : public State {
public:
    DummyState()
    {
    }

    void update() override
    {
        std::cout << "Update : dummy" << std::endl;
    }
};

int main()
{
    // Create StateManager class
    StatesManager statesMan;

    // Add foo state to state stack
    statesMan.addState(StateID::foo, std::unique_ptr<FooState>(new FooState()));

    // Get foo state specificly and update it
    // Outputs : Update : foo
    statesMan.getState(StateID::foo)->update();

    // Update all states in stack
    // Outputs : Update : foo
    statesMan.updateStates();

    // Remove specificly foo state
    statesMan.removeState(StateID::foo);

    // Add bar state to stack
    statesMan.addState(StateID::bar, std::unique_ptr<BarState>(new BarState()));

    // Outputs : Update : bar
    statesMan.updateStates();

    // Add dummy state to stack
    statesMan.addState(StateID::dummy, std::unique_ptr<DummyState>(new DummyState()));

    // Outputs : Update : bar
    // Outputs : Update : dummy
    statesMan.updateStates();

    // Just everything except dummy state
    statesMan.removeAllStatesExcept(StateID::dummy);

    // Outputs : Update : dummy
    statesMan.updateStates();

    // Remove all states in the stack
    statesMan.removeAllStates();

    statesMan.updateStates();

    return 0;
}
