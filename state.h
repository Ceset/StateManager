#ifndef STATE_H
#define STATE_H

// WARNING // WARNING // WARNING // WARNING
// Forward declared enum class
enum class StateID;

class State
{
public:
    State(){}
    virtual ~State(){}

    virtual void check() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif // STATE_H
