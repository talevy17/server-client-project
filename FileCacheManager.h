#ifndef SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H
#define SERVER_CLIENT_PROJECT_FILECACHEMANAGER_H

#include <map>
#include <fstream>
#include "CacheManager.h"

#define DELIM ','
#define FILE_NAME "problemSolutionMap.txt"

using namespace std;

template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
    map<Problem, Solution> problemSolutionMap;
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
        string line, key, value;
        while (getline(probSolMap, line)) {
            int k = (int) line.find(DELIM);
            key = line.substr(0, k);
            value = line.substr(k + 1, line.size());
//        this->problemSolutionMap.insert(pair <Problem,Solution> (key,value));
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
     */
    void saveToFile() {
        fstream probSolMap;
        //check if open as trunc or add bool to problem and solution
        probSolMap.open(FILE_NAME, ios::in | ios::app);
        if (!probSolMap.is_open()) { throw "file not found"; }
        typename map<Problem, Solution>::iterator it;
        //check if change condition to !=
        for (it = this->problemSolutionMap.begin(); it < this->problemSolutionMap.end(); ++it) {
            //here save to file
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
