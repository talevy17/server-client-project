

#ifndef SERVER_CLIENT_PROJECT_MATRIX_H
#define SERVER_CLIENT_PROJECT_MATRIX_H

#include "Node.h"
#include "Searchable.h"
#include <vector>

/**
 * a searchable used for finding paths in a maze.
 */
struct functor {
    bool operator()(State<Node>* a, State<Node>* b) {
        return *a < *b;
    }
};

class Matrix : public Searchable<Node> {
    int n;
    int m;
    int **matrix;
    std::map<State<Node>*, bool, functor> states;
    Node initialState;
    Node goalState;

    /**
     * check if the node is within the bounds and the value isn't a wall.
     * @param node Node
     * @return bool validStep.
     */
    bool validStep(Node node);
public:

    /**
     * CTOR
     * @param rows
     * @param cols
     * @param maze
     */
    Matrix(int rows, int cols, int **maze, Node beg, Node end);

    /**
    * overloaded [] operator, get the [][] node.
    * @param node Node
    * @return int matrix[i][j]
    */
    int operator[](Node node);

    /**
     * returns the initial state, in this case, the [0][0] node.
     * @return initial state.
     */
    virtual State<Node>* getInitialState();

    /**
    * goal state getter, in this case - the [n-1][m-1] node.
    * @return goal state.
    */
    virtual State<Node>* getGoalState();

    /**
    * creates a vector of all the possible states from the current state.
    * @param state State<Node>
    * @return vector<State<Node>> result.
    */
    virtual std::vector<State<Node>*> getAllPossibleStates(State<Node>* state);

    /**
    * convert a matrix to string, for mapping usage.
    * @return string result.
    */
    virtual std::string to_string();

    /**
     * @return average weight
     */
    int getAverageWeight();

    virtual bool wasVisited(State<Node>* node);

    virtual void visit(State<Node>* node);

    ~Matrix();
};


#endif //SERVER_CLIENT_PROJECT_MATRIX_H
