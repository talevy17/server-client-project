#ifndef SERVER_CLIENT_PROJECT_SEARCHABLESOLVER_H
#define SERVER_CLIENT_PROJECT_SEARCHABLESOLVER_H


#include "Solver.h"
#include "Matrix.h"
#include <string>

using namespace std;
typedef vector<State<Node>*> stateVec;

class SearchableSolver : public Solver<string, string> {
public:
    /**
     * gets problem as string and solve it.
     * @param problem
     * @return solution
     */
    virtual string solve(string problem);
    /**
     * gets the states vector and convert to direction
     * @param solution
     * @return directions
     */
    string fromStatesVectorToString(vector<State<Node>*> solution);
};


#endif //SERVER_CLIENT_PROJECT_SEARCHABLESOLVER_H
