#ifndef SERVER_CLIENT_PROJECT_CACHEMANAGER_H
#define SERVER_CLIENT_PROJECT_CACHEMANAGER_H

using namespace std;

template<class T>
class CacheManager {
    virtual void save(T solution) = 0;

    virtual T getSolution(T problem) = 0;

    virtual bool isThereASolution(T problem) = 0;

};


#endif //SERVER_CLIENT_PROJECT_CACHEMANAGER_H
