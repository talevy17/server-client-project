
#include <iostream>
#include "Matrix.h"
#include "MinHeap.h"

#include <map>
#define TO_CHAR 48

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

    /*
>>>>>>> 8f39472fb299d56b954a71ac13a44af6d847c3d1
    Matrix mat(n, m, arr);
    State<Node> init = mat.getInitialState();
    State<Node> init2 = mat.getInitialState();
    State<Node> goal = mat.getGoalState();
    vector<State<Node>> states = mat.getAllPossibleStates(&init);


    MinHeap<State<Node>> heap;
    for (State<Node> state : states) {
        heap.push(state);
    }
<<<<<<< HEAD
    State<Node> state(Node(1,0), 4, nullptr);
    int index = heap.find(state);
    if (index == -1) {
        cout<< "error"<<endl;
    }
    cout<<heap.getElement(index).getCost()<<endl;
    heap.replace(state, index);
    cout<<heap.getElement(index).getCost()<<endl;
=======
     */

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            cout << mat[Node(i,j)] << endl;
        }
    }*/

    string result;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            result.push_back(arr[row][col] + TO_CHAR);
        }
        result.push_back(';');
    }
}

