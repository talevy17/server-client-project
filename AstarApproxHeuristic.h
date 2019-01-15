

#ifndef SERVER_CLIENT_PROJECT_ASTARAPPROXHEURISTIC_H
#define SERVER_CLIENT_PROJECT_ASTARAPPROXHEURISTIC_H

#include <cmath>
#include "Node.h"

struct AstarApproxHeuristic {
    int operator()(Node &current, Node &goalState) {
        return abs(current.getRow() - goalState.getRow()) + abs(current.getCol() - goalState.getCol());
    }
};

struct ManhattenAverageWeight {
    int avgWeight;
public:
    ManhattenAverageWeight(int w) { this->avgWeight = w; }

    int operator()(Node &current, Node &goalState) {
        return abs(current.getRow() - goalState.getRow()) * avgWeight
               + abs(current.getCol() - goalState.getCol()) * avgWeight;
    }
};

struct BestFsHeuristic {
    int operator()(Node &current, Node &goalState) {
        return 0;
    }
};


#endif //SERVER_CLIENT_PROJECT_ASTARAPPROXHEURISTIC_H
