

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
    PriorityQueue<State<T>> *openList;

    int evaluatedNodes;
    /**
    * CTOR
    * @param pq
   */
    SearcherWrapper(PriorityQueue<State<Node>> *pq) : openList(pq), evaluatedNodes(0) {}

    /**
     * pop an element from the list and add 1 to the evaluated nodes.
     * @return the popped element.
     */
    State<Node> popOpenList() {
        if (!this->openList->isEmpty()) {
            this->evaluatedNodes++;
            return this->openList->pop();
        }
        return State<Node>(Node(-1, -1), -1, nullptr);
    }

    /**
     * track back the solution route for later evaluation.
     * @param tail
     * @param initState
     * @return (Solution) vector<State<T>*> route.
     */
    Solution trackBack(State<T> *tail, State<T> *initState) {
        std::vector<State<T> *> route;
        while (!(*tail == *initState)) {
            route.push_back(tail);
            tail = tail->getFather();
        }
        return (Solution) route;
    }

public:

    /**
     * number of nodes evaluated getter.
     * @return
     */
    int getNumberOfNodesEvaluated() { return this->evaluatedNodes; }

};


#endif //SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H
