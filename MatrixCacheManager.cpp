#include <fstream>
#include <iostream>
#include "MatrixCacheManager.h"

#define FILE_NAME "MatrixCacheManager.txt"
#define SOLUTION 'r'

MatrixCacheManager::MatrixCacheManager() {
    loadFromFile();
}

/**
 * the function open the CacheManager file and load it to map
 * of problem and solution.
 */
void MatrixCacheManager::loadFromFile() {
    //open the file
    fstream matTrackMap;
    matTrackMap.open(FILE_NAME, ios::in | ios::app);
    if (!matTrackMap.is_open()) { throw "file not found"; }
    //load to map
    string line;
    while (getline(matTrackMap, line)) {
        string mat, track;
        while (line.compare("end")) {
            if (line == "") {
                getline(matTrackMap, line);
                continue;
            } else if (line.at(0) == SOLUTION) {
                track.append(line.substr(1, line.size() - 1));
            } else {
                mat.append(line + '\n');
            }
            getline(matTrackMap , line);
        }
        this->matrixTrackSolution.insert(pair<string, string>(mat.substr(0,mat.size()-1), track));
    }
}

/**
 * the function gets problem and solution and add it to the map
 * @param problem
 * @param solution
 */
void MatrixCacheManager::save(string problem, string solution) {
    unique_lock<mutex> ul(this->mut);
    this->matrixTrackSolution[problem] = solution;
    ul.unlock();
}

/**
 * when the program ends - save the map to the file
 * split problem and solution by end of line
 */
void MatrixCacheManager::saveToFile() {
    //open the file
    fstream matTrackMap;
    ofstream cacheManage(FILE_NAME, ios::trunc);
    if (!cacheManage.is_open()) { throw "file not found"; }
    //save to file
    for (pair<string, string> inMap : this->matrixTrackSolution) {
        cacheManage << inMap.first << endl << SOLUTION << inMap.second << endl << "end" << endl;
    }
}

/**
 * the function gets problem and return it's solution
 * @param problem
 * @return solution
 */
string MatrixCacheManager::getSolution(string problem) {
    unique_lock<mutex> ul(this->mut);
    string solution = this->matrixTrackSolution[problem];
    ul.unlock();
    return solution;
}

/**
 * the function gets problem, and check if there is an solution.
 * @param problem
 * @return true- if there is solution , false - else
 */
bool MatrixCacheManager::isThereASolution(string problem) {
    unique_lock<mutex> ul(this->mut);
    bool f = this->matrixTrackSolution.find(problem) != this->matrixTrackSolution.end();
    ul.unlock();
    return f;
}