
#ifndef SERVER_CLIENT_PROJECT_CORESTATE_H
#define SERVER_CLIENT_PROJECT_CORESTATE_H

#include "State.h"

/**
 * coreState implements state as part of the decorator design pattern, used as a "core" of a state.
 * @tparam T
 */
template<class T>
class CoreState : public State<T> {
    T state;
    int cost;
    State<T> *cameFrom;
public:
    /**
     * CTOR
     * @param state
     * @param cost
     * @param father
     */
    CoreState(T state, int cost, State<T> *father) {
        this->state = state;
        this->cost = cost;
        this->cameFrom = father;
    }

    /**
     * CCTOR.
     * @param other
     */
    CoreState(CoreState &other) {
        this->state = other.getState();
        this->cost = other.getCost();
        this->cameFrom = other.cameFrom;
    }

    /**
     * CTOR.
     * @param other
     */
    CoreState(State<T> *other) {
        this->state = other->getState();
        this->cost = other->getCost();
        this->cameFrom = other->getFather();
    }

    bool operator==(State<T> &other) {
        return this->state == other.getState();
    }

    int getCost() const { return this->cost; }

    State<T> *getFather() { return this->cameFrom; }

    T getState() const { return state; }

    bool operator<(State<T> &other) {
        return this->state < other.getState();
    }

    bool operator>(State<T> &other) {
        return ((this->cost) > other.getCost());
    }

    bool operator<=(State<T> &other) {
        return ((this->cost) <= other.getCost());
    }

    bool operator>=(State<T> &other) {
        return ((this->cost) >= other.getCost());
    }

    virtual ~CoreState() {}
};


#endif //SERVER_CLIENT_PROJECT_CORESTATE_H
