
#ifndef SERVER_CLIENT_PROJECT_STATE_H
#define SERVER_CLIENT_PROJECT_STATE_H

/**
 * the State interface, designed for the searchers as a decorator class.
 * @tparam T
 */
template<class T>
class State {
public:
    /**
     * state getter.
     * @return T state.
     */
    virtual T getState() const = 0;

    /**
     * cost getter
     * @return int cost
     */
    virtual int getCost() const = 0;

    /**
     * father getter, returns the previous state.
     * @return State<T>* father.
     */
    virtual State<T> *getFather() = 0;

    /**
     * overload the == operator
     * @return bool res
     */
    virtual bool operator==(State<T> &) = 0;

    /**
     * overload the <= operator
     * @return bool res
     */
    virtual bool operator<=(State<T> &) = 0;

    /**
     * overload the >= operator
     * @return bool res
     */
    virtual bool operator>=(State<T> &) = 0;

    /**
     * overload the < operator
     * @return bool res
     */
    virtual bool operator<(State<T> &) = 0;

    /**
     * overload the > operator
     * @return bool res
     */
    virtual bool operator>(State<T> &) = 0;

    /**
     * virtual DTOR.
     */
    virtual ~State() {}

};

#endif //SERVER_CLIENT_PROJECT_STATE_H
