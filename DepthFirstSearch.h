#ifndef SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H

#include <string>
#include "Searcher.h"
#include "Matrix.h"
#include "FirstSearchVisit.h"

using namespace std;

class DepthFirstSearch : public Searcher<string,Matrix> {
    int evaluatedNodes;
    FirstSearchVisit visitMatrix;
public:
    DepthFirstSearch(int i, int j);
    virtual string search(Matrix matrix);
    virtual int getNumberOfNodesEvaluated();
};


#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
