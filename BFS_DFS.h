#ifndef SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H

#include <string>
#include "SearcherWrapper.h"

using namespace std;

template<class Solution, class T>
class BFS_DFS : public SearcherWrapper<Solution, T> {
    vector<State<T> *> visit;
public:
    typedef vector<State<T> *> stateVec;

    /**
     * constructor
     * @param priority queue
     */
    BFS_DFS(PriorityQueue<State<T> *> *pq) : SearcherWrapper<Solution, T>(pq) {}

    /**
     * the function does BFS or DFS (same algorithem different priority queue)
     * and return the track
     * @param searchable
     * @return solution
     */
    virtual Solution search(Searchable<T> *searchable) {
        State<T> *curr = searchable->getInitialState();
        this->openList->push(curr);
        // dfs/bfs
        while (!this->openList->isEmpty()) {
            curr = this->popOpenList();
            //if we got to the goal state - stop and return trackBack
            if (*curr == *searchable->getGoalState()) {
                return this->trackBack(curr, searchable->getInitialState());
            }
            //if its the first time visiting - mark as visited.
            if (!visited(curr)) {
                visit.push_back(curr);
            }
            //get neighbors and push it to the list.
            stateVec adjs = searchable->getAllPossibleStates(curr);
            for (auto adj : adjs) {
                if (!visited(adj)) {
                    this->openList->push(adj);
                }
            }
        }
    }

    /**
     * iterator on the visit vector in order to find
     * if the state in this vector
     * @param state
     * @return true if found, false - else
     */
    bool visited(State<T> *state) {
        typename stateVec::iterator it;
        for (it = visit.begin(); it < visit.end(); ++it) {
            if (**it == *state) {
                return true;
            }
        }
        return false;
    }
};

#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
