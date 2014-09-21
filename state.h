#ifndef STATE_H
#define STATE_H

// This class is only a base class for State classes.
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

    // A common update function that has to be defined by
    // all State classes.
    virtual void update() = 0;

    // A common render function.
    virtual void render() = 0;

    // Functions to set and question States activeness.
    bool isActive()
    {
        return mIsActive;
    }
    
    void setActive(bool isTrue)
    {
        mIsActive = isTrue;
    }

private:
    // A bool variable to learn if the class is active
    // or not. So we can do whatever we want if we ever
    // desire to way it works.
    bool mIsActive{true};
};

#endif // STATE_H
