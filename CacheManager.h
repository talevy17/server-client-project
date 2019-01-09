#ifndef SERVER_CLIENT_PROJECT_CACHEMANAGER_H
#define SERVER_CLIENT_PROJECT_CACHEMANAGER_H

using namespace std;

template<class Problem, class Solution>
class CacheManager {
public:
    virtual void save(Problem problem, Solution solution) = 0;

    virtual Solution getSolution(Problem problem) = 0;

    virtual bool isThereASolution(Problem problem) = 0;

};


#endif //SERVER_CLIENT_PROJECT_CACHEMANAGER_H