

#ifndef SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"
#include "Node.h"
#include "SearcherWrapper.h"
#include <string>
#include <bits/stdc++.h>

template<class Solution, class T>
class BestFirstSearch : public SearcherWrapper<Solution, T> {
public:
    /**
     * CTOR, initializes super class.
     * @param pq
     */
    BestFirstSearch(PriorityQueue<State<T>*> *pq) : SearcherWrapper<Solution, T>(pq) {}

    /**
     * searches the cheapest path in the given graph.
     * @param searchable Searchable<T>*
     * @return Solution
     */
    virtual Solution search(Searchable<T>* searchable) {
        //push the initial state to the queue.
        this->openList->push(searchable->getInitialState());
        std::unordered_set<State<T>*> closed;
        //goal state for comparing purposes.
        State<T>* goal = searchable->getGoalState();
        while (!this->openList->isEmpty()) {
            //pop the minimum state.
            State<T>* n = this->popOpenList();
            closed.insert(n);
            //if the algorithm reached the goal, track back the route.
            if (*n == *goal) {
                return this->trackBack(n, searchable->getInitialState());
            }
            //create a vector of neighbors.
            std::vector<State<T>*> adj = searchable->getAllPossibleStates(n);
            //loop through all of the neighbors.
            for (State<T>* state : adj) {
                int nodeIndex = this->openList->find(state);
                typename std::unordered_set<State<T>*> ::iterator closedIter = closed.find(state);
                //if the node was never visited at all.
                if (closedIter == closed.end() && nodeIndex == -1) {
                    this->openList->push(state);
                //the node was visited/
                } else {
                    //if it's not in openList
                    if (nodeIndex == -1) {
                        //if the cost is better than the one in the closed list.
                        if (*state < **closedIter) {
                            this->openList->push(state);
                        }
                    //it's in openList
                    } else {
                        //if the cost is better than the one in the openList, replace it.
                        if (*state < *(this->openList->getElement(nodeIndex))) {
                            this->openList->replace(state, nodeIndex);
                        }
                    }
                }
            }
        } // end of while
        //if the algorithm reached this point, there is no path from the initial state to the goal state.
        std::vector<State<T>*> vec;
        return (Solution) vec;
    }
};


#endif //SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H
