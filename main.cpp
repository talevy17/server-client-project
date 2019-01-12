
#include <iostream>
#include "Matrix.h"

using namespace std;

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
    State<Node> init2 = mat.getInitialState();
    State<Node> goal = mat.getGoalState();
    cout << init.equals(init2) << endl;
    cout << init.equals(goal) << endl;
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

