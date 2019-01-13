#ifndef SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H

#include <string>
#include "SearcherWrapper.h"

using namespace std;
template <class T>
class BFS_DFS : public SearcherWrapper<string,T> {
    vector<T> visit;
public:
    typedef vector<State<T>> stateVec;
    BFS_DFS(){

    }
    virtual string search(Searchable<T> searchable){
        State<T> state = searchable.getInitialState();
        stateVec vic = searchable.getAllPossibleStates(state);
        typename vector<State<T>> :: iterator stateVecIter;

        
    }
    virtual int getNumberOfNodesEvaluated(){

    }
};


#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
