//
// Created by tal on 1/10/19.
//

#ifndef SERVER_CLIENT_PROJECT_STATE_H
#define SERVER_CLIENT_PROJECT_STATE_H

template<class T>
class State {
    T state;
    double cost;
    State<T> *cameFrom;
public:
    State(T state, double cost, State<T> *father) {
        this->state = state;
        this->cost = cost;
        this->cameFrom = father;
    }

    bool equals(State<T> s) {
        return s.getState().equals(this->state);
    }

    double getCost() const { return this->cost; }

    State<T> *getFather() { return this->cameFrom; }

    T getState() const { return state; }

    bool operator<(State<T> other) {
        return ((this->cost) < other.getCost());
    }

    bool operator>(State<T> other) {
        return ((this->cost) > other.getCost());
    }

    bool operator<=(State<T> other) {
        return ((this->cost) <= other.getCost());
    }

    bool operator>=(State<T> other) {
        return ((this->cost) >= other.getCost());
    }
};


#endif //SERVER_CLIENT_PROJECT_STATE_H
