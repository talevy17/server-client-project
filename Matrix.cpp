
#include "Matrix.h"
#define TO_CHAR 48

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
    std::vector<Node> steps = {curr.goDownLeft(), curr.goDown(), curr.goLeft(), curr.goDownRight(), curr.goRight(),
                               curr.goUpLeft(), curr.goUp(), curr.goUpRight()};
    for (Node step : steps) {
        if (validStep(step)) {
            result.push_back(State<Node>(step, (*this)[step], state));
        }
    }
    return result;
}

std::string Matrix::to_string() {
    std::string result;
    for (int row = 0; row < this->n; row++) {
        for (int col = 0; col < this->m; col++) {
            result.push_back(this->matrix[row][col] + TO_CHAR);
            result.push_back(',');
        }
        result.push_back(';');
    }
}
