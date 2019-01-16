#include <iostream>
#include "FileCacheManager.h"

#define FILE_NAME "problemSolutionMap.txt"

/**
 * constructor
 */
FileCacheManager::FileCacheManager() {
    loadFromFile();
}

/**
 * the function open the CacheManager file and load it to map
 * of problem and solution.
 */
void FileCacheManager::loadFromFile() {
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
void FileCacheManager::save(string problem, string solution) {
    cout << problem << endl;

    unique_lock<mutex> ul(this->mut);
    this->problemSolutionMap[problem] = solution;
    ul.unlock();
}

/**
 * when the program ends - save the map to the file
 * split problem and solution by end of line
 */
void FileCacheManager::saveToFile() {
    //open the file
    fstream probSolMap;
    ofstream cacheManage(FILE_NAME, ios::trunc);
    if (!cacheManage.is_open()) { throw "file not found"; }
    //save to file
    for (pair<string, string> ps : this->problemSolutionMap) {
        cacheManage << ps.first << endl << ps.second << endl;
    }
}

/**
 * the function gets problem and return it's solution
 * @param problem
 * @return solution
 */
string FileCacheManager::getSolution(string problem) {
    unique_lock<mutex> ul(this->mut);
    string p =  this->problemSolutionMap[problem];
    ul.unlock();
    return p;
}

/**
 * the function gets problem, and check if there is an solution.
 * @param problem
 * @return true- if there is solution , false - else
 */
bool FileCacheManager::isThereASolution(string problem) {
    unique_lock<mutex> ul(this->mut);
    bool f =  this->problemSolutionMap.find(problem) != this->problemSolutionMap.end();
    ul.unlock();
    return f;
}