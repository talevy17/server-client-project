#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "Matrix.h"
#include "Node.h"

int main() {

    int n = 2;
    int m = 5;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            arr[i][j] = k;
            k++;
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            cout << arr[i][j] << endl;
        }
    }*/
    Matrix mat(n, m, arr);
    State<Node> init = mat.getInitialState();
    vector<State<Node>> states = mat.getAllPossibleStates(&init);
    for (State<Node> state : states) {
        cout << state.getCost() << endl;
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            cout << mat[Node(i,j)] << endl;
        }
    }*/
}