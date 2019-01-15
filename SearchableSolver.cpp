#include <iostream>
#include "SearchableSolver.h"
#include "Interpreter.h"

enum POS {
    UP, DOWN, LEFT, RIGHT
};

string positionToString(POS position) {
    switch (position) {
        case 0: return "up ";
        case 1: return "down ";
        case 2: return "left ";
        case 3: return "right ";
    }
}

string SearchableSolver::fromStatesVectorToString(vector<State<Node> *> solution) {
    string result;
    State<Node> *curr = solution.at(solution.size() - 1);
    typename stateVec::iterator it;
    for (it = --solution.end(); it >= solution.begin(); --it) {
        string direction;
        if (curr->getState() <= (*it)->getState()) { direction = positionToString(DOWN); }
        else if (curr->getState() >= (*it)->getState()) { direction = positionToString(UP); }
        else if (curr->getState() > (*it)->getState()) { direction = positionToString(LEFT); }
        else { direction = positionToString(RIGHT); }
        result.append(direction);
        curr = *it;
    }
    return result;
}

string SearchableSolver::solve(string problem) {


}
