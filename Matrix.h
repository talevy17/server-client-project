//
// Created by tal on 1/12/19.
//

#ifndef SERVER_CLIENT_PROJECT_MATRIX_H
#define SERVER_CLIENT_PROJECT_MATRIX_H

#include "Node.h"
#include "Searchable.h"
#include <vector>

class Matrix : public Searchable<Node> {
    int n;
    int m;
    int **matrix;

    bool validStep(Node node);
public:
    Matrix(int rows, int cols, int **maze);

    int operator[](Node node);

    virtual State<Node> getInitialState();

    virtual State<Node> getGoalState();

    virtual std::vector<State<Node>> getAllPossibleStates(State<Node>* state);

    virtual std::string to_string();
};


#endif //SERVER_CLIENT_PROJECT_MATRIX_H
