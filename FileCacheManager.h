#ifndef SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H
#define SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H

#include <map>
#include <fstream>
#include "CacheManager.h"

#define FILE_NAME "problemSolutionMap.txt"

using namespace std;

template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
    map<Problem, Solution> problemSolutionMap;
public:
    typedef map<Problem, Solution> psMap;

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
        string key, value;
        int size;
        probSolMap >> size;
        for (int i = 0; i < size; i++) {
            probSolMap >> key >> value;
            this->problemSolutionMap.insert(pair<string, string>(key, value));
        }
    }

    /**
     * the function gets problem and solution and add it to the map
     * @param problem
     * @param solution
     */
    void save(Problem problem, Solution solution) {
        this->problemSolutionMap[problem] = solution;
    }

    /**
     * when the program ends - save the map to the file
     * split problem and solution by end of line
     */
    void saveToFile() {
        fstream probSolMap;
        //check if open as trunc or add bool to problem and solution
        ofstream cacheManage(FILE_NAME, ios::in | ios::app);
        if (!cacheManage.is_open()) { throw "file not found"; }
        //first - insert the size of map
        cacheManage << this->problemSolutionMap.size() << endl;
        for (psMap p : this->problemSolutionMap) {
            cacheManage << p.first << endl << p.second << endl;
        }
    }

    /**
     * the function gets problem and return it's solution
     * @param problem
     * @return solution
     */
    Solution getSolution(Problem problem) {
        return this->problemSolutionMap[problem];
    }

    /**
     * the function gets problem, and check if there is an solution.
     * @param problem
     * @return true- if there is solution , false - else
     */
    bool isThereASolution(Problem problem) {
        return (this->problemSolutionMap.count(problem) != 0);
    }


};


#endif //SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H
