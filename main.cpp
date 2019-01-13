
#include <iostream>
#include "Matrix.h"
#include "FirstSearchVisit.h"
#include <map>
#define TO_CHAR 48

using namespace std;

int main() {
//
//    int n = 2;
//    int m = 5;
//    int** arr = new int*[n];
//    for (int i = 0; i < n; i++) {
//        arr[i] = new int[m];
//    }
//    int k = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j ++) {
//            arr[i][j] = k;
//            k++;
//        }
//    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            cout << arr[i][j] << endl;
        }
    }*/

    /*
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
     */

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            cout << mat[Node(i,j)] << endl;
        }
    }*/
//
//    string result;
//    for (int row = 0; row < n; row++) {
//        for (int col = 0; col < m; col++) {
//            result.push_back(arr[row][col] + TO_CHAR);
//        }
//        result.push_back(';');
//    }




}

