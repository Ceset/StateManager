#ifndef STATE_H
#define STATE_H

// This class is only a abstract class for State classes.
//
// Its main purpose is to be inherited by all State
// classes. So that StateManager class can control
// all state classes easily.
//
// WARNING // WARNING // WARNING // WARNING
// Forward declared enum class
//
// You have to define it before you can use it.
enum class StateID;

class State
{
public:
    State();
    virtual ~State();

    // Update function that must be defined by derived classes
    virtual void update() = 0;

    // Function to question States activeness
    bool isActive()
    {
        return m_isActive;
    }

    // Function to set States activeness
    void setActive(bool isTrue)
    {
        m_isActive = isTrue;
    }

private:
    // A bool variable to learn if the class is active
    // or not
    //
    // Does not do anything particular
    // Check it and decide what you want to do
    bool m_isActive{true};
};

#endif // STATE_H
