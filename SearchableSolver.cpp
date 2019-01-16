#include <iostream>
#include "SearchableSolver.h"
#include "Interpreter.h"
#include "BestFS_Astar.h"
#include "AstarApproxHeuristic.h"
#include "MinHeap.h"

typedef typename stateVec::iterator stateIter;

enum POS {
    UP, DOWN, LEFT, RIGHT
};

/**
 * get position and return direction
 * @param position
 * @return string direction
 */
string positionToString(POS position) {
    switch (position) {
        case 0: return "up ";
        case 1: return "down ";
        case 2: return "left ";
        case 3: return "right ";
    }
}

/**
 *
 * @param solution
 * @return string - track
 */
string SearchableSolver::fromStatesVectorToString(vector<State<Node> *> solution) {
    string result;
    if (solution.empty()){ return "-1";}
    ssize_t size = solution.size()-1;
    State<Node> *curr = solution.at(size);
    stateIter it;
    for (it = prev(prev(solution.end())); it >= solution.begin(); --it) {
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
    Interpreter i;
    Matrix matrix = i.stringToMatrix(problem);
    BestFS_Astar<vector<State<Node>*>, Node, AstarApproxHeuristic>
            astar(new MinHeap<State<Node>*>,new AstarApproxHeuristic);
    vector<State<Node>*> track = astar.search(&matrix);
    string solution = fromStatesVectorToString(track);
    for (auto a : track){
        delete(a);
    }
    return solution;
}