

#ifndef SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H
#define SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H

#include "PriorityQueue.h"
#include "Searcher.h"
#include "Searchable.h"
#include <string>
#include "Node.h"

template <class Solution, class T>
class SearcherWrapper : public Searcher<Solution, T> {
protected:
    PriorityQueue<State<T>> *openList;
    int evaluatedNodes;

    State<Node> popOpenList(){
        if (!this->openList->isEmpty()) {
            this->evaluatedNodes++;
            return this->openList->pop();
        }
        return State<Node>(Node(-1, -1), -1, nullptr);
    }

    Solution trackBack(State<T> head) {
        
    }
public:
    SearcherWrapper(PriorityQueue<State<Node>> *pq) {
        this->openList = pq;
        this->evaluatedNodes = 0;
    }

    int getNumberOfNodesEvaluated(){return this->evaluatedNodes;}

};


#endif //SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H
