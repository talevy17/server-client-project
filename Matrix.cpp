
#include "Matrix.h"
#define TO_CHAR 48

/**
* CTOR
* @param rows
* @param cols
* @param maze
*/
Matrix::Matrix(int rows, int cols, int **maze) {
    this->n = rows;
    this->m = cols, this->matrix = maze;
}

/**
 * overloaded [] operator, get the [][] node.
 * @param node Node
 * @return int matrix[i][j]
 */
int Matrix::operator[](Node node) {
    if (node.getRow() >= this->n || node.getRow() < 0 || node.getCol() >= this->m || node.getCol() < 0) {
        throw "Invalid index";
    }
    return this->matrix[node.getRow()][node.getCol()];
}

/**
* returns the initial state, in this case, the [0][0] node.
* @return initial state.
*/
State<Node> Matrix::getInitialState() {
    Node node(0, 0);
    return State<Node>(node, (*this)[node], nullptr);
}

/**
 * goal state getter, in this case - the [n-1][m-1] node.
 * @return goal state.
 */
State<Node> Matrix::getGoalState() {
    Node node(this->n - 1, this->m - 1);
    return State<Node>(node, (*this)[node], nullptr);
}

/**
* check if the node is within the bounds and the value isn't a wall.
* @param node Node
* @return bool validStep.
*/
bool Matrix::validStep(Node node) {
    if ((node.getRow() >= this->n) || (node.getRow() < 0) || (node.getCol() >= this->m) || (node.getCol() < 0)) {
        return false;
    }
    return ((*this)[node] != -1);
}

/**
 * creates a vector of all the possible states from the current state.
 * @param state State<Node>
 * @return vector<State<Node>> result.
 */
std::vector<State<Node>> Matrix::getAllPossibleStates(State<Node> *state) {
    std::vector<State<Node>> result;
    Node curr = state->getState();
    std::vector<Node> steps = {curr.goDown(), curr.goLeft(), curr.goRight(), curr.goUp()};
    for (Node step : steps) {
        if (validStep(step)) {
            result.push_back(State<Node>(step, (*this)[step], state));
        }
    }
    return result;
}

/**
 * convert a matrix to string, for mapping usage.
 * @return string result.
 */
std::string Matrix::to_string() {
    std::string result;
    for (int row = 0; row < this->n; row++) {
        for (int col = 0; col < this->m; col++) {
            result.push_back(this->matrix[row][col] + TO_CHAR);
        }
        result.push_back(';');
    }
    return result;
}
