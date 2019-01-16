
#include "Matrix.h"

/**
 * CTOR
 * @param rows
 * @param cols
 * @param maze
 * @param beg
 * @param end
 */
Matrix::Matrix(int rows, int cols, int **maze, Node beg, Node end) {
    this->n = rows;
    this->m = cols, this->matrix = maze;
    this->initialState = beg;
    this->goalState = end;
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->m; j++) {
            Node node(i,j);
            State<Node>* st = new CoreState<Node>(node, 0, nullptr);
            this->states[st] = false;
        }
    }
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
State<Node> *Matrix::getInitialState() {
    return new CoreState<Node>(this->initialState, (*this)[this->initialState], nullptr);
}

/**
 * goal state getter, in this case - the [n-1][m-1] node.
 * @return goal state.
 */
State<Node> *Matrix::getGoalState() {
    return new CoreState<Node>(this->goalState, (*this)[this->goalState], nullptr);
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
std::vector<State<Node> *> Matrix::getAllPossibleStates(State<Node> *state) {
    std::vector<State<Node> *> result;
    Node curr = state->getState();
    std::vector<Node> steps = {curr.goDown(), curr.goLeft(), curr.goRight(), curr.goUp()};
    for (Node step : steps) {
        if (validStep(step)) {
            result.push_back(new CoreState<Node>(step, (*this)[step] + state->getCost(), state));
        }
    }
    return result;
}

/**
 * function gets node and convert it to string
 * @param node
 * @return string representation of the node
 */
std::string pointToString(Node n){
    return (std::to_string(n.getRow()) + ','
     + std::to_string(n.getCol()) + '\n');
}

/**
 * convert a matrix to string, for mapping usage.
 * @return string result.
 */
std::string Matrix::to_string() {
    std::string result;
    for (int row = 0; row < this->n; row++) {
        for (int col = 0; col < this->m; col++) {
            result.append(std::to_string(this->matrix[row][col])+',');
        }
        result.pop_back();
        result.push_back('\n');
    }
    result.append(pointToString(this->initialState));
    result.append(pointToString(this->goalState));
    return result;
}

/**
 * the function sum the weights of every node and return
 * the average.
 * @return average weight
 */
int Matrix::getAverageWeight() {
    int weight = 0;
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->m; j++) {
            weight += this->matrix[i][j];
        }
    }
    return weight/(this->n*this->m);
}

bool Matrix::wasVisited(State<Node> *node) {
    return this->states[node];
}

void Matrix::visit(State<Node> *node) {

    this->states[node] = true;
}


Matrix:: ~Matrix(){
    std::map<State<Node>*, bool, functor> :: iterator it;
    for (it = this->states.begin(); it != this->states.end() ; ++it){
        delete(it->first);
    }
    for( int i = 0 ; i < n ; i++ ) {
        delete[] matrix[i];
    }
    delete[] matrix;
}