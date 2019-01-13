#ifndef SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H

#include <string>
#include "SearcherWrapper.h"

using namespace std;
template <class Solution , class T>
class BFS_DFS : public SearcherWrapper<Solution,T> {
    vector<T> visit;
public:

    typedef vector<State<T>> stateVec;
    typedef typename stateVec :: iterator statesIter;
    typedef typename vector<T> :: iterator vecIter;

    BFS_DFS(PriorityQueue<State<Node>*> *pq) : SearcherWrapper<Solution,T>(pq){}

    virtual Solution search(Searchable<T> searchable){
        State<T> curr = searchable.getInitialState();
        this->openList->push(curr);
        while (!this->openList->isEmpty()){
            if (curr == searchable.getGoalState()){
                return trackBack(curr, searchable.getInitialState());
            }
            stateVec adj = searchable.getAllPossibleStates(curr);

        }
    }

    void bfsDfs(Searchable<T> searchable, State<T> curr){
        stateVec adj = searchable.getAllPossibleStates(curr);
        statesIter adjIter;
        vecIter notFound = this->visit.end();
        for (adjIter = adj.begin(); adjIter < adj.end() ; ++adjIter){
            //if not visited - visit.
            if (this->visit.find(curr) != notFound) {
                this->visit.push_back(*adjIter);
                this->openList->push(*adjIter);
                bfsDfs(searchable.getAllPossibleStates(*adjIter));
            }
        }
    }
};

/**
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited
}
 */


#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
