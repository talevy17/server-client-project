#ifndef SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H

#include <string>
#include "SearcherWrapper.h"
#include <map>

using namespace std;
template<class Solution, class T>
class BFS_DFS : public SearcherWrapper<Solution, T> {
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
                Solution sol = this->trackBack(curr, searchable->getInitialState());
                while (!this->openList->isEmpty()) {
                    delete(this->openList->pop());
                }
                return sol;
            }
            //if its the first time visiting - mark as visited.
            if (!searchable->wasVisited(curr)) {
                searchable->visit(curr);
                //get neighbors and push it to the list.
                stateVec adjs = searchable->getAllPossibleStates(curr);
                for (auto adj : adjs) {
                    if (!searchable->wasVisited(adj)) {
                        this->openList->push(new CoreState<T>(adj));
                    }
                    delete adj;
                }
            }
        }
    }
};

#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
