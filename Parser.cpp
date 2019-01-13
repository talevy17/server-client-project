#include <sstream>
#include <vector>
#include "Parser.h"

/**
 * the function gets line input and separate to substrings
 * and push to vector.
 * @param line
 * @param vec
 * @param delim
 * @param numOfDel
 */
void splitLine(const string &line, vector<string> &vec, char delim, int &numOfDel) {
    stringstream stream(line);
    string split;
    while (getline(stream, split, delim)) {
        vec.push_back(split);
        numOfDel++;
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
int** createMatrix (string input, int &row, int &col){
    vector<string> rowVec, colVec;
    splitLine(input, rowVec, '\n', row);
    vector<string>::iterator it;
    for (it = rowVec.begin(); it < rowVec.end(); ++it) {
        splitLine(*it, colVec, ',', col);
    }
    col = col / row;
    //create array matrix
    int **mat = new int *[col];
    for (int i = 0; i < col; i++) {
        mat[i] = new int[row];
    }
    //fill the matrix.
    int t = 0;
    for (int j = 0; j < row; j++) {
        for (int k = 0; k < col; k++) {
            mat[j][k] = stoi(colVec.at(t));
            t++;
        }
    }
}

/**
 * the function gets string of point and
 * convert it to Node.
 * @param point
 * @return Node
 */
Node fromPointToNode(string point){
    ssize_t delim = point.find(',');
    int beg = stoi(point.substr(0,delim));
    int end = stoi(point.substr(delim,point.size()));
    return Node(beg,end);
}

/**
 * main parser function gets matrix and 2 points
 * as strings and create new Matrix.
 * @param string input
 * @param init
 * @param goal
 * @return Matrix
 */
Matrix Parser::stringToMatrix(string matrix, string init, string goal) {
    int row=0,col=0;
    int** mat = createMatrix(matrix, row, col);
    return Matrix(row, col, mat,
            fromPointToNode(init), fromPointToNode(goal));
}