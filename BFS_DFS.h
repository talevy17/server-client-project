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
        vector<State<T>*> allStates;
        State<T> *init = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();
        allStates.push_back(init);
        allStates.push_back(goal);
        this->openList->push(new CoreState<T>(init));
        // dfs/bfs
        while (!this->openList->isEmpty()) {
            State<T>* curr = this->popOpenList();
            allStates.push_back(curr);
            //if we got to the goal state - stop and return trackBack
            if (*curr == *goal) {
                Solution sol = this->trackBack(curr, init);
                for (auto s : allStates){ delete(s); }
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
        std::vector<State<T> *> vec;
        return (Solution) vec;
    }
};

#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H