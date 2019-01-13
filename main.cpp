#include <iostream>
#include "Matrix.h"
#include "Interpreter.h"
#include "BestFS_Astar.h"
#include "AstarApproxHeuristic.h"
#include "MinHeap.h"

using namespace std;


int main() {
    string input = "1,2,3 \n"
                   "4,5,6 \n"
                   "7,8,9 \n"
                   "0,0 \n"
                   "2,2 \n";
    Interpreter i;
    Matrix m = i.stringToMatrix(input);
    State<Node>* f = m.getInitialState();
    vector<State<Node>*> vf = m.getAllPossibleStates(f);
    cout << "done" << endl;
    int rows = 5;
    int cols = 5;
    int** arr = new int*[rows];
    for (int in = 0; in < rows; in++) {
        arr[in] = new int[cols];
    }
    int k = 1;
    for (int in = 0; in < rows; in ++) {
        for (int j = 0; j < cols; j ++) {
            arr[in][j] = k++;
        }
    }
    Matrix mat(5,5,arr,Node(0,0),Node(4,4));
    BestFS_Astar<vector<State<Node>*>, Node,AstarApproxHeuristic>
            astar(new MinHeap<State<Node>*>, AstarApproxHeuristic());
    BestFS_Astar<vector<State<Node>*>, Node,BestFsHeuristic> bfs(new MinHeap<State<Node>*>, BestFsHeuristic());
    vector<State<Node>*> astarRes = astar.search(&mat);
    vector<State<Node>*> bfsRes = bfs.search(&mat);
    cout <<"this is astar results:"<<endl;
    for (State<Node>* state: astarRes) {
        cout <<state->getCost()<<endl;
    }
    cout << "evaluated Nodes: "<<astar.getNumberOfNodesEvaluated()<<endl;
    cout <<"**********************"<<endl;
    cout <<"this is bfs results:"<<endl;
    for (State<Node>* state: bfsRes) {
        cout <<state->getCost()<<endl;
    }
    cout << "evaluated Nodes: "<<bfs.getNumberOfNodesEvaluated()<<endl;
}