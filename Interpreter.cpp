#include <sstream>
#include <vector>
#include <iostream>
#include "Interpreter.h"


/**
 * the function gets line input and separate to substrings
 * and push to vector.
 * @param line
 * @param vec
 * @param delim - char to separate by.
 */
void splitLine(const string &line, strvec &vec, char delim) {
    stringstream stream(line);
    string split;
    while (getline(stream, split, delim)) {
        vec.push_back(split);
    }
}

/**
 * the function gets vector<string> and return the
 * last element and pop it
 * @param input strvec - the input
 * @return string point
 */
string getLast(strvec &input) {
    string last = input.at(input.size() - 1);
    input.pop_back();
    return last;
}

/**
 * the function gets vector to split
 * and vector to insert the result to
 * and split
 * @param rowVec
 * @param colVec
 */
void splitMat(strvec &rowVec, strvec &colVec) {
    strvec::iterator it;
    for (it = rowVec.begin(); it < rowVec.end(); ++it) {
        splitLine(*it, colVec, ',');
    }
}

/**
 * the function gets input, number of row and column
 * and create int** from the input
 * @param input
 * @param row
 * @param col
 * @return array of int**
 */
int** createMatrix(strvec rowVec, int row, int &col) {
    strvec colVec;
    splitMat(rowVec, colVec);
    col = ((int) colVec.size()) / row;
    //create array matrix
    int **mat = new int *[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new int[col];
    }
    //fill the matrix.
    int t = 0;
    for (int j = 0; j < row; j++) {
        for (int k = 0; k < col; k++) {
            mat[j][k] = stoi(colVec.at(t));
            t++;
        }
    }
    return mat;
}

/**
 * the function gets string of point and
 * convert it to Node.
 * @param point
 * @return Node
 */
Node fromPointToNode(string point) {
    strvec pointVec;
    splitLine(point, pointVec, ',');
    int beg = stoi(pointVec.at(0));
    int end = stoi(pointVec.at(pointVec.size() - 1));
    return Node(beg, end);
}

/**
 * main parser function gets matrix and 2 points
 * as strings and create new Matrix.
 * @param string input
 * @param init
 * @param goal
 * @return Matrix
 */
Matrix Interpreter::parser(strvec rowVec, string init, string goal) {
    int col = 0;
    int row = rowVec.size();
    int **mat;
    mat = createMatrix(rowVec, row, col);
    return Matrix(row, col, mat,
                  fromPointToNode(init), fromPointToNode(goal));
}

/**
 * the function gets the whole input
 * and split it to its elements
 * @param input - string
 * @return vector<string> - the elements
 */
Matrix Interpreter::stringToMatrix(string input) {
    strvec element;
    splitLine(input, element, '\n');
    //pop end of input
    string end = getLast(element);
    string begin = getLast(element);
    return parser(element, begin, end);
}
