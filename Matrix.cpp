//
// Created by tal on 1/12/19.
//

#include "Matrix.h"

Matrix::Matrix(int rows, int cols, int **maze) {this->n = rows; this->m = cols, this->matrix = maze;}

int Matrix::operator[](Node node) {
    if (node.getRow() >= this->n || node.getRow() < 0 || node.getCol() >= this->m || node.getCol() < 0) {
        throw "Invalid index";
    }
    return *(*this->matrix +(node.getRow()*this->m + node.getCol()));
}

State<Node> Matrix::getInitialState() {
    Node node(0,0);
    return State<Node>(node, (*this)[node], nullptr);
}

State<Node> Matrix::getGoalState() {
    Node node(this->n - 1, this->m - 1);
    return State<Node>(node, (*this)[node], nullptr);
}

std::vector<State<Node>> Matrix::getAllPossibleStates() {
    std::vector<State<Node>> result;

}