
#include "Matrix.h"

Matrix::Matrix(int rows, int cols, int **maze) {
    this->n = rows;
    this->m = cols, this->matrix = maze;
}

int Matrix::operator[](Node node) {
    if (node.getRow() >= this->n || node.getRow() < 0 || node.getCol() >= this->m || node.getCol() < 0) {
        throw "Invalid index";
    }
    return this->matrix[node.getRow()][node.getCol()];
}

State<Node> Matrix::getInitialState() {
    Node node(0, 0);
    return State<Node>(node, (*this)[node], nullptr);
}

State<Node> Matrix::getGoalState() {
    Node node(this->n - 1, this->m - 1);
    return State<Node>(node, (*this)[node], nullptr);
}

bool Matrix::validStep(Node node) {
    if ((node.getRow() >= this->n) || (node.getRow() < 0) || (node.getCol() >= this->m) || (node.getCol() < 0)) {
        return false;
    }
    return ((*this)[node] != -1);
}

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