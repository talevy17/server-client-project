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
 * the function gets vector of states and compare each state with his father
 * and write the directions.
 * @param solution
 * @return string - track
 */
string SearchableSolver::fromStatesVectorToString(vector<State<Node> *> solution) {
    string result;
    if (solution.empty()){ return "-1";}
    ssize_t size = solution.size()-1;
    State<Node> *curr = solution.at(size);
    stateIter it;
    //start from the end just like boyer and moore!
    //compare each state with his former
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

/**
 * the function gets the input and interpreter it to matrix
 * and solve it by using astar algorithm.
 * we wrote 4 algorithms : bfs, dfs, bestfs and astar
 * we tested them on matrix (10x10 -> 50x50)
 * and found out that the best algorithm is astar
 * therefor we choose to use it
 * @param problem
 * @return string of directions
 */
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