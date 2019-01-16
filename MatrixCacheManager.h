#ifndef SERVER_CLIENT_PROJECT_MATRIXCACHEMANAGER_H
#define SERVER_CLIENT_PROJECT_MATRIXCACHEMANAGER_H

#include <string>
#include "CacheManager.h"
#include <map>
#include <mutex>

using namespace std;
class MatrixCacheManager : public CacheManager<string, string>{
    map<string, string> matrixTrackSolution;
    mutex mut;
public:
    MatrixCacheManager();

    void loadFromFile();

    void save(string problem, string solution);

    void saveToFile();

    string getSolution(string problem);

    bool isThereASolution(string problem);
};


#endif //SERVER_CLIENT_PROJECT_MATRIXCACHEMANAGER_H
