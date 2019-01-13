#include "FirstSearchVisit.h"

/**
 * constructor
 * @param row - row num
 * @param col - column number
 */
FirstSearchVisit::FirstSearchVisit(int row, int col) {
    this->row = row;
    this->col = col;
    initMatrix();
}

/**
 * initialize the matrix state of each index to hold white
 */
void FirstSearchVisit::initMatrix() {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            matrix[i][j] = WHITE;
        }
    }
}

/**
 * return the state in the index
 * @param i
 * @param j
 * @return visit state
 */
Visit FirstSearchVisit::getVisitState(int i, int j) {
    return this->matrix[i][j];
}

/**
 * change the state in this index
 * @param i
 * @param j
 */
void FirstSearchVisit::setVisitState(int i, int j) {
    if (matrix[i][j] == WHITE) { matrix[i][j] = GRAY; }
    if (matrix[i][j] == GRAY) { matrix[i][j] = BLACK; }
}