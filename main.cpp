#include <iostream>
#include "Matrix.h"
#include "Interpreter.h"
#include "BestFS_Astar.h"
#include "AstarApproxHeuristic.h"
#include "MinHeap.h"
#include "Queue.h"
#include "BFS_DFS.h"

using namespace std;


int main() {


    string input = "1,2,3 \n"
                   "4,6,7 \n"
                   "8,9,10 \n"
                   "0,0 \n"
                   "1,2 \n";
    /*

    string input = "1,80,3,-1,4 \n"
                   "4,2,-1,1,1 \n"
                   "10,8,9,2,1 \n"
                   "2,-1,1,6,7 \n"
                   "80,1,3,1,10\n"
                   "0,0 \n"
                   "4,4 \n";
                   */
    Interpreter i;
    Matrix m = i.stringToMatrix(input);

    BFS_DFS<vector<State<Node>*>,Node> b (new Queue<State<Node>*>);
    vector<State<Node>*> vec = b.search(&m);
    for (auto v : vec){
        cout << "row" << v->getState().getRow() << "col" << v->getState().getCol()<< endl;
    }

    /*
    BestFS_Astar<vector<State<Node>*>, Node,AstarApproxHeuristic>
            astar(new MinHeap<State<Node>*>, AstarApproxHeuristic());
    BestFS_Astar<vector<State<Node>*>, Node,BestFsHeuristic> bfs(new MinHeap<State<Node>*>, BestFsHeuristic());

    int avg = m.getAverageWeight();
    BestFS_Astar<vector<State<Node>*>, Node,ManhattenAverageWeight>
            astar(new MinHeap<State<Node>*>, new ManhattenAverageWeight(m.getAverageWeight()));
    BestFS_Astar<vector<State<Node>*>, Node,BestFsHeuristic> bfs(new MinHeap<State<Node>*>, new BestFsHeuristic());

    vector<State<Node>*> astarRes = astar.search(&m);
    vector<State<Node>*> bfsRes = bfs.search(&m);
    cout <<"this is astar results:"<<endl;
    for (State<Node>* state: astarRes) {
        cout <<"cost: "<<state->getCost()<<endl;
        cout<< "index: ("<<state->getState().getRow() << ", " << state->getState().getCol()<<")"<<endl;
        delete(state);
    }
    cout << "evaluated Nodes: "<<astar.getNumberOfNodesEvaluated()<<endl;
    cout <<"**********************"<<endl;
    cout <<"this is bfs results:"<<endl;
    for (State<Node>* state: bfsRes) {
        cout <<"cost: "<<state->getCost()<<endl;
        cout<< "index: ("<<state->getState().getRow() << ", " << state->getState().getCol()<<")"<<endl;
        delete(state);
    }
    cout << "evaluated Nodes: "<<bfs.getNumberOfNodesEvaluated()<<endl;
*/
}