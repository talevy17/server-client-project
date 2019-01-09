#ifndef SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H
#define SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H

#include <map>
#include <fstream>
#include "CacheManager.h"

#define FILE_NAME "problemSolutionMap.txt"

using namespace std;

class FileCacheManager : public CacheManager<string, string> {
    map<string,string> problemSolutionMap;
public:

    /**
     * constructor
     */
    FileCacheManager() {
        loadFromFile();
    }

    /**
     * the function open the CacheManager file and load it to map
     * of problem and solution.
     */
    void loadFromFile() {
        //open the file
        fstream probSolMap;
        probSolMap.open(FILE_NAME, ios::in | ios::app);
        if (!probSolMap.is_open()) { throw "file not found"; }
        //load to map
        string key;
        string value;
        while (!probSolMap.eof()) {
            probSolMap >> key >> value;
            this->problemSolutionMap.insert(pair<string, string>(key, value));
        }
    }

    /**
     * the function gets problem and solution and add it to the map
     * @param problem
     * @param solution
     */
    void save(string problem, string solution) {
        this->problemSolutionMap[problem] = solution;
    }

    /**
     * when the program ends - save the map to the file
     * split problem and solution by end of line
     */
    void saveToFile() {
        //open the file
        fstream probSolMap;
        ofstream cacheManage(FILE_NAME, ios::trunc);
        if (!cacheManage.is_open()) { throw "file not found"; }
        //save to file
        for (pair<string,string> ps : this->problemSolutionMap) {
            cacheManage << ps.first << endl << ps.second << endl;
        }
    }

    /**
     * the function gets problem and return it's solution
     * @param problem
     * @return solution
     */
    string getSolution(string problem) {
        return this->problemSolutionMap[problem];
    }

    /**
     * the function gets problem, and check if there is an solution.
     * @param problem
     * @return true- if there is solution , false - else
     */
    bool isThereASolution(string problem) {
        return (this->problemSolutionMap.count(problem) != 0);
    }


};


#endif //SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H
