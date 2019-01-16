#ifndef SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H
#define SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H

#include <map>
#include <fstream>
#include <mutex>
#include "CacheManager.h"

class FileCacheManager : public CacheManager<string, string> {
    map<string, string> problemSolutionMap;
    mutex mut;
public:
    FileCacheManager();

    void loadFromFile();

    void save(string problem, string solution);

    void saveToFile();

    string getSolution(string problem);

    bool isThereASolution(string problem);
};


#endif //SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H
