#include "FileCacheManager.h"
#define DELIM ','
/*
void FileCacheManager :: loadFromFile(){
    fstream probSolMap;
    probSolMap.open("problemSolutionMap.txt",ios::in|ios::app);
    if(!probSolMap.is_open()){throw "file not found";}
    string line, key, value;
    while (getline(probSolMap,line)) {
        int k = (int)line.find(DELIM);
        key = line.substr(0,k);
        value = line.substr(k+1, line.size());
//        this->problemSolutionMap.insert(pair <Problem,Solution> (key,value));
    }
}


FileCacheManager ::FileCacheManager() {
    loadFromFile();
}
 */
