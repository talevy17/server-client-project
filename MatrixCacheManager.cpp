#include <fstream>
#include "MatrixCacheManager.h"
#define FILE_NAME "MatrixCacheManager"

MatrixCacheManager:: MatrixCacheManager(){
    loadFromFile();
}
/**
 * the function open the CacheManager file and load it to map
 * of problem and solution.
 */
void MatrixCacheManager:: loadFromFile() {
    //open the file
    fstream matTrackMap;
    matTrackMap.open(FILE_NAME, ios::in | ios::app);
    if (!matTrackMap.is_open()) { throw "file not found"; }
    //load to map
    string line;
    while (getline(matTrackMap,line)) {

        //this->matrixTrackSolution.insert(pair<string, string>(key, value));
    }
}

/**
 * the function gets problem and solution and add it to the map
 * @param problem
 * @param solution
 */
void MatrixCacheManager::save(string problem, string solution) {
    this->matrixTrackSolution[problem] = solution;
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
    for (pair<string, string> ps : this->matrixTrackSolution) {
        cacheManage << ps.first  << "end" << ps.second << endl;
    }
}

/**
 * the function gets problem and return it's solution
 * @param problem
 * @return solution
 */
string MatrixCacheManager::getSolution(string problem) {
    return this->matrixTrackSolution[problem];
}

/**
 * the function gets problem, and check if there is an solution.
 * @param problem
 * @return true- if there is solution , false - else
 */
bool MatrixCacheManager::isThereASolution(string problem) {
    return this->matrixTrackSolution.find(problem) != this->matrixTrackSolution.end();
}