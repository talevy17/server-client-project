//
// Created by tal on 1/10/19.
//

#ifndef SERVER_CLIENT_PROJECT_SEARCHER_H
#define SERVER_CLIENT_PROJECT_SEARCHER_H

#include "Searchable.h"

template <class Solution, class T>
class Searcher {
public:
    virtual Solution search(Searchable<T> searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //SERVER_CLIENT_PROJECT_SEARCHER_H
