

#ifndef SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"
#include "Node.h"
#include "SearcherWrapper.h"
#include <string>

template<class Solution, class T>
class BestFirstSearch : public SearcherWrapper<Solution, T> {
public:
    BestFirstSearch(PriorityQueue<State<T>> *pq) : SearcherWrapper<Solution, T>(pq) {}

    virtual Solution search(Searchable<T> searchable) {}
};


#endif //SERVER_CLIENT_PROJECT_BESTFIRSTSEARCH_H
