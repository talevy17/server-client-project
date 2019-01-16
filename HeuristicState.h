
#ifndef SERVER_CLIENT_PROJECT_HEURISTICSTATE_H
#define SERVER_CLIENT_PROJECT_HEURISTICSTATE_H

#include "State.h"

/**
 * Heuristic State implements the decorator pattern.
 * @tparam T
 */
template<class T>
class HeuristicState : public State<T> {
    //the core state
    State<T> *state;
    //the heuristic cost of the path.
    int cost;
public:
    /**
     * CTOR, accepts a core state.
     * @param st
     */
    HeuristicState(State<T> *st) {
        this->state = st;
        this->cost = 0;
    }

    /**
     * CTOR, accepts a core state and a heuristic path cost.
     * @param st
     * @param heurCost
     */
    HeuristicState(int heurCost, State<T> *st) {
        this->state = st;
        this->cost = heurCost;
    }

    /**
     * return the core's father (for track back usage).
     * @return State<T>* cameFrom
     */
    State<T> *getFather() {
        return this->state->getFather();
    }

    /**
     * returns the state.
     * @return T state.
     */
    T getState() const {
        return this->state->getState();
    }

    /**
     * sets the heuristic cost.
     * @param val
     */
    void setCost(int val) {
        this->cost = val;
    }

    /**
     * computes the current path cost + the estimated path to the goal.
     * @return int cost.
     */
    int getCost() const { return (this->state->getCost() + this->cost); }

    /**
     * overload the == operator.
     * @param other
     * @return bool res
     */
    bool operator==(State<T> &other) {
        return this->state->getState() == other.getState();
    }

    /**
     * overload the < operator.
     * @param other
     * @return bool res
     */
    bool operator<(State<T> &other) {
        return this->getCost() < other.getCost();
    }

    /**
     * overload the > operator.
     * @param other
     * @return bool res
     */
    bool operator>(State<T> &other) {
        return this->getCost() > other.getCost();
    }

    /**
     * overload operator <=
     * @param other
     * @return bool res
     */
    bool operator<=(State<T> &other) {
        return this->getCost() <= other.getCost();
    }

    /**
     * overload >= operator
     * @param other
     * @return bool res
     */
    bool operator>=(State<T> &other) {
        return this->getCost() >= other.getCost();
    }

    /**
     * specific for heuristic state, returns the core state.
     * @return this->state.
     */
    State<T> *getCoreState() {
        return this->state;
    }

    /**
     * specific fir heuristic state, returns the estimated distance from the goal state.
     * @return this->cost.
     */
    int getHeurCost() { return this->cost; }

    /**
     * DTOR
     * frees the core state.
     */
    virtual ~HeuristicState() {
        delete (this->state);
    }

};

#endif //SERVER_CLIENT_PROJECT_HEURISTICSTATE_H
