#ifndef SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H
#define SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H

#include "PriorityQueue.h"
#include "Searcher.h"
#include "Searchable.h"
#include <string>
#include "Node.h"

/**
 * a Wrapper class for the searcher algorithms.
 * @tparam Solution
 * @tparam T
 */
template<class Solution, class T>
class SearcherWrapper : public Searcher<Solution, T> {
protected:
    PriorityQueue<State<T>*> *openList;

    int evaluatedNodes;
    /**
    * CTOR
    * @param pq
   */
    SearcherWrapper(PriorityQueue<State<T>*> *pq) : openList(pq), evaluatedNodes(0) {}

    /**
     * pop an element from the list and add 1 to the evaluated nodes.
     * @return the popped element.
     */
    State<T>* popOpenList() {
        if (!this->openList->isEmpty()) {
            this->evaluatedNodes++;
            return this->openList->pop();
        }
        return new CoreState<Node>(Node(-1, -1), -1, nullptr);
    }

    /**
     * track back the solution route for later evaluation.
     * @param tail
     * @param initState
     * @return (Solution) vector<State<T>*> route.
     */
    virtual Solution trackBack(State<T> *tail, State<T> *initState) {
        std::vector<State<T> *> route;
        while (!(*tail == *initState)) {
            route.push_back(new CoreState<T>(tail));
            tail = tail->getFather();
        }
        route.push_back(new CoreState<T>(tail));
        return (Solution) route;
    }

    /**
     * frees all of the allocated states.
     * @param allocTracker
     */
    void freeAllocTracker(std::vector<State<T> *> &allocTracker) {
        for (State<T> *vertex : allocTracker) {
            delete (vertex);
        }
    }

    typedef typename std::vector<State<T> *>::iterator InputIterator;

    /**
     * finds a value in a vector of pointers,
     * implemented the same as std::find but compares the values of the pointers.
     * @param first begin iterator.
     * @param last end iterator
     * @param val State<T>* value.
     * @return InputIterator.
     */
    InputIterator findByVal(InputIterator first, InputIterator last, State<T>* val) {
        while (first != last) {
            if (**first == *val) return first;
            ++first;
        }
        return last;
    }

public:

    /**
     * number of nodes evaluated getter.
     * @return
     */
    int getNumberOfNodesEvaluated() { return this->evaluatedNodes; }

    virtual ~SearcherWrapper() {delete(this->openList);}

};


#endif //SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H