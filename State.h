
#ifndef SERVER_CLIENT_PROJECT_STATE_H
#define SERVER_CLIENT_PROJECT_STATE_H

template<class T>
class State {
    T state;
    int cost;
    State<T> *cameFrom;
public:
    State(T state, int cost, State<T> *father) {
        this->state = state;
        this->cost = cost;
        this->cameFrom = father;
    }

    State(const State &other) {
        this->state = other.getState();
        this->cost = other.getCost();
        this->cameFrom = other.cameFrom;
    }

    State &operator=(const State &other) {
        this->state = other.getState();
        this->cost = other.getCost();
        this->cameFrom = other.cameFrom;
    }

    bool operator==(const State<T>& s) {
        return s.getState() == (this->state);
    }

    double getCost() const { return this->cost; }

    State<T> *getFather() { return this->cameFrom; }

    T getState() const { return state; }

    bool operator<(const State<T>& other) {
        return ((this->cost) < other.getCost());
    }

    bool operator>(const State<T>& other) {
        return ((this->cost) > other.getCost());
    }

    bool operator<=(const State<T>& other) {
        return ((this->cost) <= other.getCost());
    }

    bool operator>=(const State<T>& other) {
        return ((this->cost) >= other.getCost());
    }

    void addCost(int toBeAdded) {
        this->cost += toBeAdded;
    }
};


#endif //SERVER_CLIENT_PROJECT_STATE_H
