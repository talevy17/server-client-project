#include <iostream>
#include "Interpreter.h"
#include "Queue.h"
#include "Stack.h"
#include "BFS_DFS.h"

using namespace std;


int main() {
    string input = "1,2,3 \n"
                   "4,5,6 \n"
                   "7,8,9 \n"
                   "0,0 \n"
                   "1,2 \n";
    Interpreter i;
    Matrix m = i.stringToMatrix(input);
    Stack<State<Node>*> pq;
    BFS_DFS<vector<State<Node>*>, Node> bfs(&pq);
    vector<State<Node>*> sol = bfs.search(&m);
    cout << "done" << endl;

}