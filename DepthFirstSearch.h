#ifndef SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H

#include <string>
#include "Searcher.h"
#include "Matrix.h"
#include "FirstSearchVisit.h"

using namespace std;
template <class T>
class DepthFirstSearch : public Searcher<string, T> {
    vector<T> visit;
public:
    virtual string search(Searchable<T> searchable){
       
    }
    virtual int getNumberOfNodesEvaluated(){

    }
};


#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
