
#include <iostream>
#include "Matrix.h"
#include "MinHeap.h"

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
    Matrix mat(n, m, arr);
    State<Node> init = mat.getInitialState();
    State<Node> init2 = mat.getInitialState();
    State<Node> goal = mat.getGoalState();
    vector<State<Node>> states = mat.getAllPossibleStates(&init);


    MinHeap<State<Node>> heap;
    for (State<Node> state : states) {
        heap.push(state);
    }
    State<Node> state(Node(1,0), 4, nullptr);
    int index = heap.find(state);
    if (index == -1) {
        cout<< "error"<<endl;
    }
    cout<<heap.getElement(index).getCost()<<endl;
    heap.replace(state, index);
    cout<<heap.getElement(index).getCost()<<endl;
}

