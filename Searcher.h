

#ifndef SERVER_CLIENT_PROJECT_SEARCHER_H
#define SERVER_CLIENT_PROJECT_SEARCHER_H

#include "Searchable.h"

/**
 * the Searcher interface.
 * @tparam Solution
 * @tparam T
 */
template<class Solution, class T>
class Searcher {
public:
    /**
     * search a searchable and return the solution.
     * @param searchable
     * @return Solution solution
     */
    virtual Solution search(Searchable<T>* searchable) = 0;

    /**
     * query the amount of nodes developed throughout the search.
     * @return int numberOfNodes.
     */
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //SERVER_CLIENT_PROJECT_SEARCHER_H
