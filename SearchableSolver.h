#ifndef SERVER_CLIENT_PROJECT_SEARCHABLESOLVER_H
#define SERVER_CLIENT_PROJECT_SEARCHABLESOLVER_H


#include "Solver.h"
#include "Matrix.h"
#include <string>

using namespace std;
typedef vector<State<Node>*> stateVec;

class SearchableSolver : public Solver<string, string> {
public:
    virtual string solve(string problem);
    string fromStatesVectorToString(vector<State<Node>*> solution);
};


#endif //SERVER_CLIENT_PROJECT_SEARCHABLESOLVER_H
