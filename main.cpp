#include <iostream>
#include "Interpreter.h"

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

}