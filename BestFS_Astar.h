

#ifndef SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Searchable.h"
#include "CoreState.h"
#include "Node.h"
#include "SearcherWrapper.h"
#include "HeuristicState.h"
#include <string>
#include <bits/stdc++.h>

/**
 * implements the BestFirstSearch algorithm's family (including A*) computation based on the heuristic function.
 * @tparam Solution
 * @tparam T
 * @tparam Heuristic Functor
 */
template<class Solution, class T, class Heuristic>
class BestFS_Astar : public SearcherWrapper<Solution, T> {
    //heuristic function sent to the CTOR, used to compute the Astar heuristics (returns 0 in case of BestFirstSearch.
    Heuristic* h;

public:
    /**
     * CTOR, initializes super class.
     * @param pq
     * @param heu heuristics Functor.
     */
    BestFS_Astar(PriorityQueue<State<T> *> *pq, Heuristic* heu) : SearcherWrapper<Solution, T>(pq) { this->h = heu; }

    /**
     * searches the cheapest path in the given graph.
     * @param searchable Searchable<T>*
     * @return Solution
     */
    virtual Solution search(Searchable<T> *searchable) {
        //push the initial state to the queue.
        State<T> *init = new HeuristicState<T>(searchable->getInitialState());
        this->openList->push(init);
        std::vector<State<T> *> closed;
        //goal state for comparing purposes.
        State<T> *goal = new HeuristicState<T>(searchable->getGoalState());
        while (!this->openList->isEmpty()) {
            //pop the minimum state.
            HeuristicState<T> *n = (HeuristicState<T> *) this->popOpenList();
            closed.push_back(n);
            //if the algorithm reached the goal, track back the route.
            if (*n == *goal) {
                Solution sol = this->trackBack(n->getCoreState(), init);
                closed.push_back(goal);
                this->freeAllocTracker(closed);
                return sol;
            }
            //create a vector of neighbors.
            std::vector<State<T> *> adj = searchable->getAllPossibleStates(n->getCoreState());
            //loop through all of the neighbors.
            for (State<T> *coreState : adj) {
                HeuristicState<T> *state = new HeuristicState<T>(coreState);
                int nodeIndex = this->openList->find(state);
                typedef typename std::vector<State<T> *>::iterator InputIterator;
                InputIterator closedIter = this->findByVal(closed.begin(), closed.end(), state);
                T curr = state->getState();
                T goalState = goal->getState();
                state->setCost((*(this->h))(curr, goalState));
                //if the node was never visited at all.
                if (closedIter == closed.end() && nodeIndex == -1) {
                    this->openList->push(new HeuristicState<T>(state->getHeurCost(),
                            new CoreState<T>(state->getCoreState())));
                    //the node was visited/
                } else {
                    //if it's not in openList
                    if (nodeIndex == -1) {
                        //if the cost is better than the one in the closed list.
                        if (*state < **closedIter) {
                            this->openList->push(new HeuristicState<T>(state->getHeurCost(),
                                    new CoreState<T>(state->getCoreState())));
                        }
                        //it's in openList
                    } else {
                        //if the cost is better than the one in the openList, replace it.
                        State<T> *temp = this->openList->getElement(nodeIndex);
                        if (*state < *(temp)) {
                            this->openList->replace((new HeuristicState<T>(state->getHeurCost(),
                                    new CoreState<T>(state->getCoreState()))), nodeIndex);
                            delete (temp);
                        }
                    }
                }
                delete (state);
            }
        } // end of while
        //if the algorithm reached this point, there is no path from the initial state to the goal state.
        closed.push_back(goal);
        this->freeAllocTracker(closed);
        std::vector<State<T> *> vec;
        return (Solution) vec;
    }

    virtual ~BestFS_Astar() {
        delete (this->h);
    }
};


#endif //SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H
