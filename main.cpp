
#include <iostream>
#include "Matrix.h"
#include "Interpreter.h"
#include "BestFS_Astar.h"
#include "AstarApproxHeuristic.h"
#include "MinHeap.h"
#include "Queue.h"
#include "BFS_DFS.h"
#include "SearchableSolver.h"
#include "Stack.h"
#include "FileCacheManager.h"

using namespace std;

string randMat (int row, int col){
    string mat;
    for (int i=0 ; i<row ; i++){
        for (int j=0; j<col ; j++){
            int r = rand() % 12;
            if (r % 9 == 0 && (i % 5) == 0) r = -1;
            if (r==0) r=1;
            mat.append(to_string(r) + ",");
        }
        mat.pop_back();
        mat.append("\n");
    }
    mat = mat.substr(1, mat.size()-3);
    string s = "2";
    s.append(mat);
    s.append("5 \n");
    s.append("0,0 \n");
    s.append(to_string(row-1) + "," + to_string(col-1) + "\n");
    return s;
}

int main() {

    //10X10
    string input10 = "2,10,-1,7,5,7,10,-1,-1,1\n"
                     "2,7,2,7,11,10,1,6,4,4\n"
                     "11,8,3,9,2,2,2,7,7,7\n"
                     "5,6,6,6,5,3,1,4,7,10\n"
                     "9,9,9,11,8,1,2,8,11,6\n"
                     "5,10,7,8,8,-1,2,2,4,1\n"
                     "9,9,8,3,8,5,10,9,1,5\n"
                     "1,3,6,9,2,3,2,8,3,2\n"
                     "7,1,1,2,8,1,3,11,2,7\n"
                     "1,1,8,1,7,4,10,6,6,15 \n"
                     "0,0 \n"
                     "9,9 \n";


    //15x15
    string input15 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11\n"
                     "10,1,6,4,4,11,8,3,9,2,2,2,7,7,7\n"
                     "5,6,6,6,5,3,1,4,7,10,9,9,9,11,8\n"
                     "1,2,8,11,6,5,10,7,8,8,9,2,2,4,1\n"
                     "9,9,8,3,8,5,10,9,1,5,1,3,6,9,2\n"
                     "3,2,8,3,2,7,-1,-1,2,8,-1,3,11,2,7\n"
                     "1,1,8,1,7,4,10,6,6,11,3,10,2,10,11\n"
                     "9,5,2,9,1,4,8,1,8,2,1,9,5,4,11\n"
                     "4,9,3,1,9,11,9,11,9,7,3,4,5,9,6\n"
                     "5,10,11,11,8,4,3,8,5,3,11,6,1,4,11\n"
                     "4,-1,-1,11,2,1,2,3,1,11,11,4,8,8,1\n"
                     "2,1,4,2,4,1,10,11,8,3,3,11,1,3,4\n"
                     "4,11,5,4,11,11,6,1,2,7,5,1,3,1,2\n"
                     "8,3,3,1,9,8,4,7,7,5,2,2,4,4,10\n"
                     "1,1,9,9,5,1,8,3,6,11,2,11,4,5,5 \n"
                     "0,0 \n"
                     "14,14 \n";


    //20x20
    string input20 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4\n"
                     "11,8,3,9,2,2,2,7,7,7,5,6,6,6,5,3,1,4,7,10\n"
                     "9,9,9,11,8,1,2,8,11,6,5,10,7,8,8,9,2,2,4,1\n"
                     "9,9,8,3,8,5,10,9,1,5,1,3,6,9,2,3,2,8,3,2\n"
                     "7,1,1,2,8,1,3,11,2,7,1,1,8,1,7,4,10,6,6,11\n"
                     "3,10,2,10,11,-1,5,2,-1,-1,4,8,1,8,2,1,-1,5,4,11\n"
                     "4,9,3,1,9,11,9,11,9,7,3,4,5,9,6,5,10,11,11,8\n"
                     "4,3,8,5,3,11,6,1,4,11,4,9,1,11,2,1,2,3,1,11\n"
                     "11,4,8,8,1,2,1,4,2,4,1,10,11,8,3,3,11,1,3,4\n"
                     "4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,1,9\n"
                     "8,4,7,7,5,2,2,4,4,10,-1,-1,-1,-1,5,-1,8,3,6,11\n"
                     "2,11,4,5,4,6,5,11,2,10,9,2,6,8,1,3,3,4,8,11\n"
                     "2,1,11,3,10,8,4,10,11,10,9,1,1,6,10,5,1,8,4,6\n"
                     "6,5,8,4,6,2,8,9,6,8,1,1,8,11,3,10,8,11,9,11\n"
                     "9,10,1,2,4,3,7,5,11,4,3,9,1,1,2,7,2,2,8,1\n"
                     "10,8,-1,6,-1,7,-1,-1,7,6,11,8,4,4,3,-1,8,2,6,11\n"
                     "6,9,1,1,1,7,11,7,9,8,7,7,8,11,5,1,11,2,1,10\n"
                     "1,4,10,5,8,1,6,8,4,1,8,2,1,9,2,7,4,2,2,5\n"
                     "2,2,1,2,5,9,3,4,1,7,2,4,11,5,9,8,6,7,4,10\n"
                     "11,4,1,1,5,7,8,1,1,2,6,3,4,10,10,2,8,1,6,5 \n"
                     "0,0 \n"
                     "19,19 \n";


    //25x25
    string input25 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4,11,8,3,-1,2\n"
                     "2,2,7,7,7,5,6,6,6,5,3,1,4,7,10,9,9,9,11,8,1,2,8,11,6\n"
                     "5,10,7,8,8,9,2,2,4,1,9,9,8,3,8,5,10,9,1,5,1,3,6,9,2\n"
                     "3,2,8,3,2,7,1,1,2,8,1,3,11,2,7,1,1,8,1,7,4,10,6,6,11\n"
                     "3,10,2,10,11,9,5,2,9,1,4,8,1,8,2,1,9,5,4,11,4,9,3,1,9\n"
                     "11,-1,11,-1,7,3,4,5,-1,6,5,10,11,11,8,4,3,8,5,3,11,6,-1,4,11\n"
                     "4,9,1,11,2,1,2,3,1,11,11,4,8,8,1,2,1,4,2,4,1,10,11,8,3\n"
                     "3,11,1,3,4,4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,1,9\n"
                     "8,4,7,7,5,2,2,4,4,10,1,1,9,9,5,1,8,3,6,11,2,11,4,5,4\n"
                     "6,5,11,2,10,9,2,6,8,1,3,3,4,8,11,2,1,11,3,10,8,4,10,11,10\n"
                     "-1,1,1,6,10,5,-1,8,4,6,6,5,8,4,6,2,8,-1,6,8,-1,-1,8,11,3\n"
                     "10,8,11,9,11,9,10,1,2,4,3,7,5,11,4,3,9,1,1,2,7,2,2,8,1\n"
                     "10,8,1,6,1,7,9,1,7,6,11,8,4,4,3,9,8,2,6,11,6,9,1,1,1\n"
                     "7,11,7,9,8,7,7,8,11,5,1,11,2,1,10,1,4,10,5,8,1,6,8,4,1\n"
                     "8,2,1,9,2,7,4,2,2,5,2,2,1,2,5,9,3,4,1,7,2,4,11,5,9\n"
                     "8,6,7,4,10,11,4,1,1,5,7,8,1,1,2,6,3,4,10,10,2,8,1,6,-1\n"
                     "1,1,4,1,6,6,1,1,1,8,3,1,1,8,6,6,7,6,8,9,8,6,1,5,5\n"
                     "10,7,1,3,5,5,4,6,9,8,4,7,8,9,9,4,1,2,9,1,8,8,7,2,8\n"
                     "4,2,2,9,7,7,11,2,1,3,8,5,11,6,7,11,11,2,7,8,3,3,1,5,1\n"
                     "1,5,1,11,7,9,4,10,11,5,9,11,4,1,11,11,1,9,10,6,8,9,9,2,8\n"
                     "5,6,-1,-1,3,5,-1,-1,6,-1,8,3,5,6,6,10,4,5,2,8,-1,2,8,10,4\n"
                     "6,6,6,4,8,6,1,6,10,11,10,3,1,11,1,1,7,8,10,6,7,8,2,1,3\n"
                     "2,1,9,2,11,5,8,9,3,4,10,10,10,4,8,9,6,4,1,5,9,7,5,6,5\n"
                     "3,1,2,5,5,9,7,7,6,9,10,3,9,1,7,2,10,5,1,6,5,1,1,9,6\n"
                     "10,7,1,7,5,7,10,10,1,7,3,10,6,2,8,7,5,3,5,5,10,11,7,7,5 \n"
                     "0,0 \n"
                     "24,24 \n";


    //30x30
    string input30 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4,11,8,3,-1,2,2,2,7,7,7\n"
                     "5,6,6,6,5,3,1,4,7,10,9,9,9,11,8,1,2,8,11,6,5,10,7,8,8,9,2,2,4,1\n"
                     "9,9,8,3,8,5,10,9,1,5,1,3,6,9,2,3,2,8,3,2,7,1,1,2,8,1,3,11,2,7\n"
                     "1,1,8,1,7,4,10,6,6,11,3,10,2,10,11,9,5,2,9,1,4,8,1,8,2,1,9,5,4,11\n"
                     "4,9,3,1,9,11,9,11,9,7,3,4,5,9,6,5,10,11,11,8,4,3,8,5,3,11,6,1,4,11\n"
                     "4,-1,-1,11,2,1,2,3,1,11,11,4,8,8,1,2,1,4,2,4,-1,10,11,8,3,3,11,1,3,4\n"
                     "4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,1,9,8,4,7,7,5,2,2,4,4,10\n"
                     "1,1,9,9,5,1,8,3,6,11,2,11,4,5,4,6,5,11,2,10,9,2,6,8,1,3,3,4,8,11\n"
                     "2,1,11,3,10,8,4,10,11,10,9,1,1,6,10,5,1,8,4,6,6,5,8,4,6,2,8,9,6,8\n"
                     "1,1,8,11,3,10,8,11,9,11,9,10,1,2,4,3,7,5,11,4,3,9,1,1,2,7,2,2,8,1\n"
                     "10,8,-1,6,-1,7,-1,-1,7,6,11,8,4,4,3,-1,8,2,6,11,6,-1,1,-1,1,7,11,7,-1,8\n"
                     "7,7,8,11,5,1,11,2,1,10,1,4,10,5,8,1,6,8,4,1,8,2,1,9,2,7,4,2,2,5\n"
                     "2,2,1,2,5,9,3,4,1,7,2,4,11,5,9,8,6,7,4,10,11,4,1,1,5,7,8,1,1,2\n"
                     "6,3,4,10,10,2,8,1,6,1,1,1,4,1,6,6,1,1,1,8,3,1,1,8,6,6,7,6,8,9\n"
                     "8,6,1,5,5,10,7,1,3,5,5,4,6,9,8,4,7,8,9,9,4,1,2,9,1,8,8,7,2,8\n"
                     "4,2,2,-1,7,7,11,2,-1,3,8,5,11,6,7,11,11,2,7,8,3,3,-1,5,1,-1,5,1,11,7\n"
                     "9,4,10,11,5,9,11,4,1,11,11,1,9,10,6,8,9,9,2,8,5,6,1,9,3,5,9,9,6,9\n"
                     "8,3,5,6,6,10,4,5,2,8,9,2,8,10,4,6,6,6,4,8,6,1,6,10,11,10,3,1,11,1\n"
                     "1,7,8,10,6,7,8,2,1,3,2,1,9,2,11,5,8,9,3,4,10,10,10,4,8,9,6,4,1,5\n"
                     "9,7,5,6,5,3,1,2,5,5,9,7,7,6,9,10,3,9,1,7,2,10,5,1,6,5,1,1,9,6\n"
                     "10,7,1,7,5,7,10,10,1,7,3,10,6,2,8,7,5,3,5,5,10,11,7,7,3,1,5,8,6,2\n"
                     "2,5,1,4,4,10,3,3,8,4,2,4,6,9,6,6,4,3,9,1,8,1,1,3,11,7,9,4,3,3\n"
                     "11,10,8,4,6,5,3,9,8,3,5,2,7,3,11,6,1,4,9,2,9,10,2,10,5,2,9,2,10,1\n"
                     "6,9,11,6,2,9,11,5,6,11,8,3,2,8,6,5,2,11,1,3,1,11,1,8,9,7,2,6,1,1\n"
                     "11,11,10,2,6,1,11,9,9,9,1,9,1,7,5,10,1,11,9,2,3,11,1,8,7,2,7,9,1,9\n"
                     "1,-1,8,11,6,6,3,6,8,4,7,-1,2,8,4,11,6,4,3,8,10,10,11,11,6,6,1,2,7,6\n"
                     "3,8,6,3,1,4,10,3,2,6,8,10,7,2,6,3,5,4,7,8,4,6,6,3,9,5,9,3,7,8\n"
                     "9,10,5,7,1,5,11,3,1,2,1,1,1,1,6,10,3,1,6,11,1,11,9,11,2,6,4,4,1,3\n"
                     "1,10,5,9,5,10,6,5,6,7,11,7,7,11,8,2,1,3,6,7,2,10,6,3,9,9,2,5,1,3\n"
                     "8,5,2,5,3,11,4,9,4,10,4,3,9,4,6,9,10,7,1,8,3,7,6,1,3,4,10,5,1,5 \n"
                     "0,0 \n"
                     "29,29 \n";


    //35x35
    string input35 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4,11,8,3,-1,2,2,2,7,7,7,5,6,6,6,5\n"
                     "3,1,4,7,10,9,9,9,11,8,1,2,8,11,6,5,10,7,8,8,9,2,2,4,1,9,9,8,3,8,5,10,9,1,5\n"
                     "1,3,6,9,2,3,2,8,3,2,7,1,1,2,8,1,3,11,2,7,1,1,8,1,7,4,10,6,6,11,3,10,2,10,11\n"
                     "9,5,2,9,1,4,8,1,8,2,1,9,5,4,11,4,9,3,1,9,11,9,11,9,7,3,4,5,9,6,5,10,11,11,8\n"
                     "4,3,8,5,3,11,6,1,4,11,4,9,1,11,2,1,2,3,1,11,11,4,8,8,1,2,1,4,2,4,1,10,11,8,3\n"
                     "3,11,1,3,4,4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,-1,-1,8,4,7,7,5,2,2,4,4,10\n"
                     "1,1,9,9,5,1,8,3,6,11,2,11,4,5,4,6,5,11,2,10,9,2,6,8,1,3,3,4,8,11,2,1,11,3,10\n"
                     "8,4,10,11,10,9,1,1,6,10,5,1,8,4,6,6,5,8,4,6,2,8,9,6,8,1,1,8,11,3,10,8,11,9,11\n"
                     "9,10,1,2,4,3,7,5,11,4,3,9,1,1,2,7,2,2,8,1,10,8,1,6,1,7,9,1,7,6,11,8,4,4,3\n"
                     "9,8,2,6,11,6,9,1,1,1,7,11,7,9,8,7,7,8,11,5,1,11,2,1,10,1,4,10,5,8,1,6,8,4,1\n"
                     "8,2,1,-1,2,7,4,2,2,5,2,2,-1,2,5,-1,3,4,-1,7,2,4,11,5,-1,8,6,7,4,10,11,4,1,1,5\n"
                     "7,8,1,1,2,6,3,4,10,10,2,8,1,6,1,1,1,4,1,6,6,1,1,1,8,3,1,1,8,6,6,7,6,8,9\n"
                     "8,6,1,5,5,10,7,1,3,5,5,4,6,9,8,4,7,8,9,9,4,1,2,9,1,8,8,7,2,8,4,2,2,9,7\n"
                     "7,11,2,1,3,8,5,11,6,7,11,11,2,7,8,3,3,1,5,1,1,5,1,11,7,9,4,10,11,5,9,11,4,1,11\n"
                     "11,1,9,10,6,8,9,9,2,8,5,6,1,9,3,5,9,9,6,9,8,3,5,6,6,10,4,5,2,8,9,2,8,10,4\n"
                     "6,6,6,4,8,6,1,6,10,11,10,3,-1,11,1,1,7,8,10,6,7,8,2,-1,3,2,1,-1,2,11,5,8,-1,3,4\n"
                     "10,10,10,4,8,9,6,4,1,5,9,7,5,6,5,3,1,2,5,5,9,7,7,6,9,10,3,9,1,7,2,10,5,1,6\n"
                     "5,1,1,9,6,10,7,1,7,5,7,10,10,1,7,3,10,6,2,8,7,5,3,5,5,10,11,7,7,3,1,5,8,6,2\n"
                     "2,5,1,4,4,10,3,3,8,4,2,4,6,9,6,6,4,3,9,1,8,1,1,3,11,7,9,4,3,3,11,10,8,4,6\n"
                     "5,3,9,8,3,5,2,7,3,11,6,1,4,9,2,9,10,2,10,5,2,9,2,10,1,6,9,11,6,2,9,11,5,6,11\n"
                     "8,3,2,8,6,5,2,11,1,3,1,11,1,8,-1,7,2,6,1,-1,11,11,10,2,6,-1,11,-1,-1,-1,1,-1,-1,7,5\n"
                     "10,1,11,9,2,3,11,1,8,7,2,7,9,1,9,1,1,8,11,6,6,3,6,8,4,7,9,2,8,4,11,6,4,3,8\n"
                     "10,10,11,11,6,6,1,2,7,6,3,8,6,3,1,4,10,3,2,6,8,10,7,2,6,3,5,4,7,8,4,6,6,3,9\n"
                     "5,9,3,7,8,9,10,5,7,1,5,11,3,1,2,1,1,1,1,6,10,3,1,6,11,1,11,9,11,2,6,4,4,1,3\n"
                     "1,10,5,9,5,10,6,5,6,7,11,7,7,11,8,2,1,3,6,7,2,10,6,3,9,9,2,5,1,3,8,5,2,5,3\n"
                     "11,4,-1,4,10,4,3,-1,4,6,-1,10,7,1,8,3,7,6,1,3,4,10,5,1,3,-1,2,-1,6,7,4,6,3,1,10\n"
                     "5,10,6,3,6,4,4,4,1,9,1,7,5,6,8,1,2,11,5,4,6,9,6,7,4,5,11,10,9,5,1,2,3,10,9\n"
                     "9,3,6,5,7,3,9,2,1,3,2,1,10,5,9,6,1,7,4,7,11,9,11,9,10,4,1,5,7,1,2,8,3,1,5\n"
                     "10,4,2,4,8,5,10,9,7,4,6,1,8,5,5,7,4,7,6,5,5,10,7,10,9,11,5,9,2,5,2,4,1,4,1\n"
                     "10,2,2,11,9,6,5,3,6,3,1,2,7,7,8,5,5,11,4,3,8,3,8,10,5,6,1,1,7,5,1,5,11,7,8\n"
                     "8,2,6,3,-1,-1,4,2,8,3,3,1,8,2,5,4,2,8,4,-1,5,10,5,6,6,2,11,3,1,7,-1,1,1,6,5\n"
                     "5,7,1,8,3,4,3,5,5,5,2,9,11,11,1,4,8,4,9,7,10,3,10,5,4,9,9,5,2,7,10,8,2,3,4\n"
                     "10,8,7,3,5,4,9,2,7,1,7,11,9,11,1,4,1,3,6,11,11,4,8,5,6,8,7,2,2,11,10,1,11,5,7\n"
                     "4,1,5,10,9,5,9,1,6,9,5,2,2,1,9,1,1,1,2,9,11,10,4,2,4,7,1,5,6,10,4,2,11,1,4\n"
                     "8,7,2,1,5,3,6,8,5,6,5,7,6,10,9,3,9,11,1,3,3,7,4,1,6,6,5,1,5,10,5,6,5,11,5 \n"
                     "0,0 \n"
                     "34,34 \n";


    //40x40
    string input40 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4,11,8,3,-1,2,2,2,7,7,7,5,6,6,6,5,3,1,4,7,10\n"
                     "9,9,9,11,8,1,2,8,11,6,5,10,7,8,8,9,2,2,4,1,9,9,8,3,8,5,10,9,1,5,1,3,6,9,2,3,2,8,3,2\n"
                     "7,1,1,2,8,1,3,11,2,7,1,1,8,1,7,4,10,6,6,11,3,10,2,10,11,9,5,2,9,1,4,8,1,8,2,1,9,5,4,11\n"
                     "4,9,3,1,9,11,9,11,9,7,3,4,5,9,6,5,10,11,11,8,4,3,8,5,3,11,6,1,4,11,4,9,1,11,2,1,2,3,1,11\n"
                     "11,4,8,8,1,2,1,4,2,4,1,10,11,8,3,3,11,1,3,4,4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,1,9\n"
                     "8,4,7,7,5,2,2,4,4,10,-1,-1,-1,-1,5,-1,8,3,6,11,2,11,4,5,4,6,5,11,2,10,-1,2,6,8,1,3,3,4,8,11\n"
                     "2,1,11,3,10,8,4,10,11,10,9,1,1,6,10,5,1,8,4,6,6,5,8,4,6,2,8,9,6,8,1,1,8,11,3,10,8,11,9,11\n"
                     "9,10,1,2,4,3,7,5,11,4,3,9,1,1,2,7,2,2,8,1,10,8,1,6,1,7,9,1,7,6,11,8,4,4,3,9,8,2,6,11\n"
                     "6,9,1,1,1,7,11,7,9,8,7,7,8,11,5,1,11,2,1,10,1,4,10,5,8,1,6,8,4,1,8,2,1,9,2,7,4,2,2,5\n"
                     "2,2,1,2,5,9,3,4,1,7,2,4,11,5,9,8,6,7,4,10,11,4,1,1,5,7,8,1,1,2,6,3,4,10,10,2,8,1,6,1\n"
                     "-1,1,4,-1,6,6,-1,-1,1,8,3,1,1,8,6,6,7,6,8,-1,8,6,-1,5,5,10,7,1,3,5,5,4,6,-1,8,4,7,8,-1,-1\n"
                     "4,1,2,9,1,8,8,7,2,8,4,2,2,9,7,7,11,2,1,3,8,5,11,6,7,11,11,2,7,8,3,3,1,5,1,1,5,1,11,7\n"
                     "9,4,10,11,5,9,11,4,1,11,11,1,9,10,6,8,9,9,2,8,5,6,1,9,3,5,9,9,6,9,8,3,5,6,6,10,4,5,2,8\n"
                     "9,2,8,10,4,6,6,6,4,8,6,1,6,10,11,10,3,1,11,1,1,7,8,10,6,7,8,2,1,3,2,1,9,2,11,5,8,9,3,4\n"
                     "10,10,10,4,8,9,6,4,1,5,9,7,5,6,5,3,1,2,5,5,9,7,7,6,9,10,3,9,1,7,2,10,5,1,6,5,1,1,9,6\n"
                     "10,7,1,7,5,7,10,10,1,7,3,10,6,2,8,7,5,3,5,5,10,11,7,7,3,1,5,8,6,2,2,5,1,4,4,10,3,3,8,4\n"
                     "2,4,6,9,6,6,4,3,9,1,8,1,1,3,11,7,9,4,3,3,11,10,8,4,6,5,3,9,8,3,5,2,7,3,11,6,1,4,9,2\n"
                     "9,10,2,10,5,2,9,2,10,1,6,9,11,6,2,9,11,5,6,11,8,3,2,8,6,5,2,11,1,3,1,11,1,8,9,7,2,6,1,1\n"
                     "11,11,10,2,6,1,11,9,9,9,1,9,1,7,5,10,1,11,9,2,3,11,1,8,7,2,7,9,1,9,1,1,8,11,6,6,3,6,8,4\n"
                     "7,9,2,8,4,11,6,4,3,8,10,10,11,11,6,6,1,2,7,6,3,8,6,3,1,4,10,3,2,6,8,10,7,2,6,3,5,4,7,8\n"
                     "4,6,6,3,-1,5,-1,3,7,8,-1,10,5,7,1,5,11,3,-1,2,1,-1,-1,-1,6,10,3,-1,6,11,-1,11,-1,11,2,6,4,4,1,3\n"
                     "1,10,5,9,5,10,6,5,6,7,11,7,7,11,8,2,1,3,6,7,2,10,6,3,9,9,2,5,1,3,8,5,2,5,3,11,4,9,4,10\n"
                     "4,3,9,4,6,9,10,7,1,8,3,7,6,1,3,4,10,5,1,3,1,2,9,6,7,4,6,3,1,10,5,10,6,3,6,4,4,4,1,9\n"
                     "1,7,5,6,8,1,2,11,5,4,6,9,6,7,4,5,11,10,9,5,1,2,3,10,9,9,3,6,5,7,3,9,2,1,3,2,1,10,5,9\n"
                     "6,1,7,4,7,11,9,11,9,10,4,1,5,7,1,2,8,3,1,5,10,4,2,4,8,5,10,9,7,4,6,1,8,5,5,7,4,7,6,5\n"
                     "5,10,7,10,-1,11,5,-1,2,5,2,4,1,4,-1,10,2,2,11,-1,6,5,3,6,3,-1,2,7,7,8,5,5,11,4,3,8,3,8,10,5\n"
                     "6,1,1,7,5,1,5,11,7,8,8,2,6,3,1,9,4,2,8,3,3,1,8,2,5,4,2,8,4,1,5,10,5,6,6,2,11,3,1,7\n"
                     "1,1,1,6,5,5,7,1,8,3,4,3,5,5,5,2,9,11,11,1,4,8,4,9,7,10,3,10,5,4,9,9,5,2,7,10,8,2,3,4\n"
                     "10,8,7,3,5,4,9,2,7,1,7,11,9,11,1,4,1,3,6,11,11,4,8,5,6,8,7,2,2,11,10,1,11,5,7,4,1,5,10,9\n"
                     "5,9,1,6,9,5,2,2,1,9,1,1,1,2,9,11,10,4,2,4,7,1,5,6,10,4,2,11,1,4,8,7,2,1,5,3,6,8,5,6\n"
                     "5,7,6,10,-1,3,-1,11,-1,3,3,7,4,-1,6,6,5,-1,5,10,5,6,5,11,7,3,2,5,11,11,11,8,6,10,10,7,5,7,6,-1\n"
                     "3,2,9,11,2,3,5,11,3,10,10,1,8,7,3,7,10,5,1,1,5,4,9,3,2,7,11,11,7,9,1,2,11,10,1,6,1,6,5,8\n"
                     "8,7,1,5,7,4,1,5,2,1,11,11,9,1,2,3,1,5,2,7,3,3,1,2,1,2,8,6,8,6,7,8,1,8,1,8,1,6,6,6\n"
                     "11,5,5,8,9,8,11,9,5,5,8,8,1,9,11,2,11,11,1,11,5,8,8,11,4,1,11,8,7,9,3,10,6,1,6,4,8,9,1,6\n"
                     "3,10,2,4,7,5,10,11,5,3,10,2,11,10,5,7,1,5,4,11,2,11,10,9,11,8,1,1,10,2,6,1,4,8,9,1,6,11,11,11\n"
                     "3,1,5,2,4,11,10,4,4,6,7,10,5,-1,7,8,10,-1,8,8,7,2,1,11,3,10,11,-1,-1,2,-1,-1,8,5,3,-1,8,5,8,4\n"
                     "11,3,3,8,5,2,4,3,7,5,3,2,7,4,1,2,2,5,3,3,11,7,8,7,5,3,7,1,8,3,6,11,11,1,7,8,3,3,3,10\n"
                     "8,6,4,8,10,6,2,4,3,6,11,2,1,7,10,6,10,9,1,10,1,6,9,4,7,8,1,2,1,3,5,8,9,9,8,11,7,11,7,10\n"
                     "5,10,5,10,6,3,9,8,1,9,7,5,7,4,9,6,5,9,8,5,4,5,5,5,7,6,4,2,5,3,5,2,2,10,1,1,1,1,1,5\n"
                     "10,7,3,9,4,1,3,9,2,4,6,10,9,3,4,4,9,8,11,2,4,4,8,10,6,1,2,11,2,2,4,5,10,7,2,6,1,6,7,5 \n"
                     "0,0 \n"
                     "39,39 \n";


    //42x42
    string input42 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4,11,8,3,-1,2,2,2,7,7,7,5,6,6,6,5,3,1,4,7,10,-1,-1\n"
                     "9,11,8,1,2,8,11,6,5,10,7,8,8,9,2,2,4,1,9,9,8,3,8,5,10,9,1,5,1,3,6,9,2,3,2,8,3,2,7,1,1,2\n"
                     "8,1,3,11,2,7,1,1,8,1,7,4,10,6,6,11,3,10,2,10,11,9,5,2,9,1,4,8,1,8,2,1,9,5,4,11,4,9,3,1,9,11\n"
                     "9,11,9,7,3,4,5,9,6,5,10,11,11,8,4,3,8,5,3,11,6,1,4,11,4,9,1,11,2,1,2,3,1,11,11,4,8,8,1,2,1,4\n"
                     "2,4,1,10,11,8,3,3,11,1,3,4,4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,1,9,8,4,7,7,5,2,2,4,4,10\n"
                     "-1,-1,-1,-1,5,-1,8,3,6,11,2,11,4,5,4,6,5,11,2,10,-1,2,6,8,1,3,3,4,8,11,2,-1,11,3,10,8,4,10,11,10,-1,1\n"
                     "1,6,10,5,1,8,4,6,6,5,8,4,6,2,8,9,6,8,1,1,8,11,3,10,8,11,9,11,9,10,1,2,4,3,7,5,11,4,3,9,1,1\n"
                     "2,7,2,2,8,1,10,8,1,6,1,7,9,1,7,6,11,8,4,4,3,9,8,2,6,11,6,9,1,1,1,7,11,7,9,8,7,7,8,11,5,1\n"
                     "11,2,1,10,1,4,10,5,8,1,6,8,4,1,8,2,1,9,2,7,4,2,2,5,2,2,1,2,5,9,3,4,1,7,2,4,11,5,9,8,6,7\n"
                     "4,10,11,4,1,1,5,7,8,1,1,2,6,3,4,10,10,2,8,1,6,1,1,1,4,1,6,6,1,1,1,8,3,1,1,8,6,6,7,6,8,9\n"
                     "8,6,-1,5,5,10,7,1,3,5,5,4,6,-1,8,4,7,8,-1,-1,4,-1,2,-1,-1,8,8,7,2,8,4,2,2,-1,7,7,11,2,-1,3,8,5\n"
                     "11,6,7,11,11,2,7,8,3,3,1,5,1,1,5,1,11,7,9,4,10,11,5,9,11,4,1,11,11,1,9,10,6,8,9,9,2,8,5,6,1,9\n"
                     "3,5,9,9,6,9,8,3,5,6,6,10,4,5,2,8,9,2,8,10,4,6,6,6,4,8,6,1,6,10,11,10,3,1,11,1,1,7,8,10,6,7\n"
                     "8,2,1,3,2,1,9,2,11,5,8,9,3,4,10,10,10,4,8,9,6,4,1,5,9,7,5,6,5,3,1,2,5,5,9,7,7,6,9,10,3,9\n"
                     "1,7,2,10,5,1,6,5,1,1,9,6,10,7,1,7,5,7,10,10,1,7,3,10,6,2,8,7,5,3,5,5,10,11,7,7,3,1,5,8,6,2\n"
                     "2,5,1,4,4,10,3,3,8,4,2,4,6,-1,6,6,4,3,-1,1,8,-1,-1,3,11,7,-1,4,3,3,11,10,8,4,6,5,3,-1,8,3,5,2\n"
                     "7,3,11,6,1,4,9,2,9,10,2,10,5,2,9,2,10,1,6,9,11,6,2,9,11,5,6,11,8,3,2,8,6,5,2,11,1,3,1,11,1,8\n"
                     "9,7,2,6,1,1,11,11,10,2,6,1,11,9,9,9,1,9,1,7,5,10,1,11,9,2,3,11,1,8,7,2,7,9,1,9,1,1,8,11,6,6\n"
                     "3,6,8,4,7,9,2,8,4,11,6,4,3,8,10,10,11,11,6,6,1,2,7,6,3,8,6,3,1,4,10,3,2,6,8,10,7,2,6,3,5,4\n"
                     "7,8,4,6,6,3,9,5,9,3,7,8,9,10,5,7,1,5,11,3,1,2,1,1,1,1,6,10,3,1,6,11,1,11,9,11,2,6,4,4,1,3\n"
                     "-1,10,5,-1,5,10,6,5,6,7,11,7,7,11,8,2,1,3,6,7,2,10,6,3,-1,-1,2,5,1,3,8,5,2,5,3,11,4,-1,4,10,4,3\n"
                     "9,4,6,9,10,7,1,8,3,7,6,1,3,4,10,5,1,3,1,2,9,6,7,4,6,3,1,10,5,10,6,3,6,4,4,4,1,9,1,7,5,6\n"
                     "8,1,2,11,5,4,6,9,6,7,4,5,11,10,9,5,1,2,3,10,9,9,3,6,5,7,3,9,2,1,3,2,1,10,5,9,6,1,7,4,7,11\n"
                     "9,11,9,10,4,1,5,7,1,2,8,3,1,5,10,4,2,4,8,5,10,9,7,4,6,1,8,5,5,7,4,7,6,5,5,10,7,10,9,11,5,9\n"
                     "2,5,2,4,1,4,1,10,2,2,11,9,6,5,3,6,3,1,2,7,7,8,5,5,11,4,3,8,3,8,10,5,6,1,1,7,5,1,5,11,7,8\n"
                     "8,2,6,3,-1,-1,4,2,8,3,3,1,8,2,5,4,2,8,4,-1,5,10,5,6,6,2,11,3,1,7,-1,1,1,6,5,5,7,1,8,3,4,3\n"
                     "5,5,5,2,9,11,11,1,4,8,4,9,7,10,3,10,5,4,9,9,5,2,7,10,8,2,3,4,10,8,7,3,5,4,9,2,7,1,7,11,9,11\n"
                     "1,4,1,3,6,11,11,4,8,5,6,8,7,2,2,11,10,1,11,5,7,4,1,5,10,9,5,9,1,6,9,5,2,2,1,9,1,1,1,2,9,11\n"
                     "10,4,2,4,7,1,5,6,10,4,2,11,1,4,8,7,2,1,5,3,6,8,5,6,5,7,6,10,9,3,9,11,1,3,3,7,4,1,6,6,5,1\n"
                     "5,10,5,6,5,11,7,3,2,5,11,11,11,8,6,10,10,7,5,7,6,9,3,2,9,11,2,3,5,11,3,10,10,1,8,7,3,7,10,5,1,1\n"
                     "5,4,-1,3,2,7,11,11,7,-1,1,2,11,10,1,6,1,6,5,8,8,7,1,5,7,4,-1,5,2,1,11,11,-1,-1,2,3,-1,5,2,7,3,3\n"
                     "1,2,1,2,8,6,8,6,7,8,1,8,1,8,1,6,6,6,11,5,5,8,9,8,11,9,5,5,8,8,1,9,11,2,11,11,1,11,5,8,8,11\n"
                     "4,1,11,8,7,9,3,10,6,1,6,4,8,9,1,6,3,10,2,4,7,5,10,11,5,3,10,2,11,10,5,7,1,5,4,11,2,11,10,9,11,8\n"
                     "1,1,10,2,6,1,4,8,9,1,6,11,11,11,3,1,5,2,4,11,10,4,4,6,7,10,5,9,7,8,10,1,8,8,7,2,1,11,3,10,11,9\n"
                     "9,2,1,1,8,5,3,1,8,5,8,4,11,3,3,8,5,2,4,3,7,5,3,2,7,4,1,2,2,5,3,3,11,7,8,7,5,3,7,1,8,3\n"
                     "6,11,11,1,7,8,3,3,3,10,8,6,4,8,10,6,2,4,3,6,11,2,1,7,10,6,10,-1,-1,10,1,6,-1,4,7,8,-1,2,-1,3,5,8\n"
                     "9,9,8,11,7,11,7,10,5,10,5,10,6,3,9,8,1,9,7,5,7,4,9,6,5,9,8,5,4,5,5,5,7,6,4,2,5,3,5,2,2,10\n"
                     "1,1,1,1,1,5,10,7,3,9,4,1,3,9,2,4,6,10,9,3,4,4,9,8,11,2,4,4,8,10,6,1,2,11,2,2,4,5,10,7,2,6\n"
                     "1,6,7,6,10,1,4,11,8,8,4,6,9,7,1,5,3,9,3,9,10,5,8,4,11,4,9,1,1,1,7,4,6,2,2,4,7,6,3,8,7,11\n"
                     "6,8,10,6,1,1,7,4,10,9,1,6,2,4,11,11,6,3,11,1,11,9,8,1,5,7,11,1,7,6,1,1,2,3,1,7,4,7,3,7,9,4\n"
                     "5,11,-1,8,2,7,11,6,-1,2,3,8,7,-1,8,7,10,3,5,2,-1,-1,-1,-1,7,2,8,11,1,5,7,6,8,8,3,11,3,6,-1,4,1,4\n"
                     "4,8,1,4,3,3,8,9,10,5,1,11,6,8,5,2,11,6,8,7,1,4,7,8,7,11,2,4,7,3,9,11,4,2,4,7,10,4,8,1,1,5 \n"
                     "0,0 \n"
                     "41,41 \n";



    //45x45
    string input45 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4,11,8,3,-1,2,2,2,7,7,7,5,6,6,6,5,3,1,4,7,10,-1,-1,-1,11,8\n"
                     "1,2,8,11,6,5,10,7,8,8,9,2,2,4,1,9,9,8,3,8,5,10,9,1,5,1,3,6,9,2,3,2,8,3,2,7,1,1,2,8,1,3,11,2,7\n"
                     "1,1,8,1,7,4,10,6,6,11,3,10,2,10,11,9,5,2,9,1,4,8,1,8,2,1,9,5,4,11,4,9,3,1,9,11,9,11,9,7,3,4,5,9,6\n"
                     "5,10,11,11,8,4,3,8,5,3,11,6,1,4,11,4,9,1,11,2,1,2,3,1,11,11,4,8,8,1,2,1,4,2,4,1,10,11,8,3,3,11,1,3,4\n"
                     "4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,1,9,8,4,7,7,5,2,2,4,4,10,1,1,9,9,5,1,8,3,6,11,2,11,4,5,4\n"
                     "6,5,11,2,10,-1,2,6,8,1,3,3,4,8,11,2,-1,11,3,10,8,4,10,11,10,-1,1,1,6,10,5,-1,8,4,6,6,5,8,4,6,2,8,-1,6,8\n"
                     "1,1,8,11,3,10,8,11,9,11,9,10,1,2,4,3,7,5,11,4,3,9,1,1,2,7,2,2,8,1,10,8,1,6,1,7,9,1,7,6,11,8,4,4,3\n"
                     "9,8,2,6,11,6,9,1,1,1,7,11,7,9,8,7,7,8,11,5,1,11,2,1,10,1,4,10,5,8,1,6,8,4,1,8,2,1,9,2,7,4,2,2,5\n"
                     "2,2,1,2,5,9,3,4,1,7,2,4,11,5,9,8,6,7,4,10,11,4,1,1,5,7,8,1,1,2,6,3,4,10,10,2,8,1,6,1,1,1,4,1,6\n"
                     "6,1,1,1,8,3,1,1,8,6,6,7,6,8,9,8,6,1,5,5,10,7,1,3,5,5,4,6,9,8,4,7,8,9,9,4,1,2,9,1,8,8,7,2,8\n"
                     "4,2,2,-1,7,7,11,2,-1,3,8,5,11,6,7,11,11,2,7,8,3,3,-1,5,1,-1,5,1,11,7,-1,4,10,11,5,-1,11,4,-1,11,11,-1,-1,10,6\n"
                     "8,9,9,2,8,5,6,1,9,3,5,9,9,6,9,8,3,5,6,6,10,4,5,2,8,9,2,8,10,4,6,6,6,4,8,6,1,6,10,11,10,3,1,11,1\n"
                     "1,7,8,10,6,7,8,2,1,3,2,1,9,2,11,5,8,9,3,4,10,10,10,4,8,9,6,4,1,5,9,7,5,6,5,3,1,2,5,5,9,7,7,6,9\n"
                     "10,3,9,1,7,2,10,5,1,6,5,1,1,9,6,10,7,1,7,5,7,10,10,1,7,3,10,6,2,8,7,5,3,5,5,10,11,7,7,3,1,5,8,6,2\n"
                     "2,5,1,4,4,10,3,3,8,4,2,4,6,9,6,6,4,3,9,1,8,1,1,3,11,7,9,4,3,3,11,10,8,4,6,5,3,9,8,3,5,2,7,3,11\n"
                     "6,1,4,-1,2,-1,10,2,10,5,2,-1,2,10,1,6,-1,11,6,2,-1,11,5,6,11,8,3,2,8,6,5,2,11,1,3,1,11,1,8,-1,7,2,6,1,-1\n"
                     "11,11,10,2,6,1,11,9,9,9,1,9,1,7,5,10,1,11,9,2,3,11,1,8,7,2,7,9,1,9,1,1,8,11,6,6,3,6,8,4,7,9,2,8,4\n"
                     "11,6,4,3,8,10,10,11,11,6,6,1,2,7,6,3,8,6,3,1,4,10,3,2,6,8,10,7,2,6,3,5,4,7,8,4,6,6,3,9,5,9,3,7,8\n"
                     "9,10,5,7,1,5,11,3,1,2,1,1,1,1,6,10,3,1,6,11,1,11,9,11,2,6,4,4,1,3,1,10,5,9,5,10,6,5,6,7,11,7,7,11,8\n"
                     "2,1,3,6,7,2,10,6,3,9,9,2,5,1,3,8,5,2,5,3,11,4,9,4,10,4,3,9,4,6,9,10,7,1,8,3,7,6,1,3,4,10,5,1,3\n"
                     "-1,2,-1,6,7,4,6,3,1,10,5,10,6,3,6,4,4,4,-1,-1,-1,7,5,6,8,-1,2,11,5,4,6,-1,6,7,4,5,11,10,-1,5,-1,2,3,10,-1\n"
                     "9,3,6,5,7,3,9,2,1,3,2,1,10,5,9,6,1,7,4,7,11,9,11,9,10,4,1,5,7,1,2,8,3,1,5,10,4,2,4,8,5,10,9,7,4\n"
                     "6,1,8,5,5,7,4,7,6,5,5,10,7,10,9,11,5,9,2,5,2,4,1,4,1,10,2,2,11,9,6,5,3,6,3,1,2,7,7,8,5,5,11,4,3\n"
                     "8,3,8,10,5,6,1,1,7,5,1,5,11,7,8,8,2,6,3,1,9,4,2,8,3,3,1,8,2,5,4,2,8,4,1,5,10,5,6,6,2,11,3,1,7\n"
                     "1,1,1,6,5,5,7,1,8,3,4,3,5,5,5,2,9,11,11,1,4,8,4,9,7,10,3,10,5,4,9,9,5,2,7,10,8,2,3,4,10,8,7,3,5\n"
                     "4,-1,2,7,-1,7,11,-1,11,-1,4,1,3,6,11,11,4,8,5,6,8,7,2,2,11,10,-1,11,5,7,4,1,5,10,-1,5,-1,-1,6,-1,5,2,2,-1,-1\n"
                     "1,1,1,2,9,11,10,4,2,4,7,1,5,6,10,4,2,11,1,4,8,7,2,1,5,3,6,8,5,6,5,7,6,10,9,3,9,11,1,3,3,7,4,1,6\n"
                     "6,5,1,5,10,5,6,5,11,7,3,2,5,11,11,11,8,6,10,10,7,5,7,6,9,3,2,9,11,2,3,5,11,3,10,10,1,8,7,3,7,10,5,1,1\n"
                     "5,4,9,3,2,7,11,11,7,9,1,2,11,10,1,6,1,6,5,8,8,7,1,5,7,4,1,5,2,1,11,11,9,1,2,3,1,5,2,7,3,3,1,2,1\n"
                     "2,8,6,8,6,7,8,1,8,1,8,1,6,6,6,11,5,5,8,9,8,11,9,5,5,8,8,1,9,11,2,11,11,1,11,5,8,8,11,4,1,11,8,7,9\n"
                     "3,10,6,-1,6,4,8,-1,1,6,3,10,2,4,7,5,10,11,5,3,10,2,11,10,5,7,-1,5,4,11,2,11,10,-1,11,8,1,-1,10,2,6,1,4,8,-1\n"
                     "1,6,11,11,11,3,1,5,2,4,11,10,4,4,6,7,10,5,9,7,8,10,1,8,8,7,2,1,11,3,10,11,9,9,2,1,1,8,5,3,1,8,5,8,4\n"
                     "11,3,3,8,5,2,4,3,7,5,3,2,7,4,1,2,2,5,3,3,11,7,8,7,5,3,7,1,8,3,6,11,11,1,7,8,3,3,3,10,8,6,4,8,10\n"
                     "6,2,4,3,6,11,2,1,7,10,6,10,9,1,10,1,6,9,4,7,8,1,2,1,3,5,8,9,9,8,11,7,11,7,10,5,10,5,10,6,3,9,8,1,9\n"
                     "7,5,7,4,9,6,5,9,8,5,4,5,5,5,7,6,4,2,5,3,5,2,2,10,1,1,1,1,1,5,10,7,3,9,4,1,3,9,2,4,6,10,9,3,4\n"
                     "4,-1,8,11,2,4,4,8,10,6,1,2,11,2,2,4,5,10,7,2,6,-1,6,7,6,10,1,4,11,8,8,4,6,-1,7,-1,5,3,-1,3,-1,10,5,8,4\n"
                     "11,4,9,1,1,1,7,4,6,2,2,4,7,6,3,8,7,11,6,8,10,6,1,1,7,4,10,9,1,6,2,4,11,11,6,3,11,1,11,9,8,1,5,7,11\n"
                     "1,7,6,1,1,2,3,1,7,4,7,3,7,9,4,5,11,9,8,2,7,11,6,1,2,3,8,7,9,8,7,10,3,5,2,9,1,9,9,7,2,8,11,1,5\n"
                     "7,6,8,8,3,11,3,6,9,4,1,4,4,8,1,4,3,3,8,9,10,5,1,11,6,8,5,2,11,6,8,7,1,4,7,8,7,11,2,4,7,3,9,11,4\n"
                     "2,4,7,10,4,8,1,1,9,11,7,10,5,9,9,3,9,8,4,6,4,4,1,7,11,10,2,6,11,5,10,5,1,6,3,9,6,7,10,8,11,9,10,8,11\n"
                     "11,11,8,8,8,2,4,-1,8,11,11,6,5,6,5,2,4,10,4,2,6,1,1,5,4,-1,4,1,11,-1,4,10,-1,1,10,-1,7,2,-1,3,5,-1,1,2,10\n"
                     "6,5,2,9,9,9,7,2,10,1,6,11,9,1,10,1,4,8,1,9,7,5,9,1,6,1,7,10,2,9,8,1,6,2,1,3,11,8,10,1,1,4,1,10,8\n"
                     "2,11,5,11,5,6,10,10,3,3,8,4,2,6,10,4,2,10,10,5,4,6,8,1,4,10,5,1,10,7,9,1,7,6,4,4,1,6,6,8,9,3,4,4,9\n"
                     "2,8,4,4,6,9,1,1,5,1,4,3,10,5,6,6,6,11,5,4,3,9,8,1,7,4,2,10,8,6,1,2,2,4,11,9,1,11,1,10,4,6,6,3,3\n"
                     "1,1,1,11,6,5,6,3,1,11,10,10,1,1,10,8,1,5,10,5,8,11,10,11,1,8,4,11,6,11,2,6,4,3,9,10,1,7,5,1,6,7,3,8,5 \n"
                     "0,0 \n"
                     "44,44 \n";


    string input50 = "2,10,-1,7,5,7,10,-1,-1,1,2,7,2,7,11,10,-1,6,4,4,11,8,3,-1,2,2,2,7,7,7,5,6,6,6,5,3,1,4,7,10,-1,-1,-1,11,8,1,2,8,11,6\n"
                     "5,10,7,8,8,9,2,2,4,1,9,9,8,3,8,5,10,9,1,5,1,3,6,9,2,3,2,8,3,2,7,1,1,2,8,1,3,11,2,7,1,1,8,1,7,4,10,6,6,11\n"
                     "3,10,2,10,11,9,5,2,9,1,4,8,1,8,2,1,9,5,4,11,4,9,3,1,9,11,9,11,9,7,3,4,5,9,6,5,10,11,11,8,4,3,8,5,3,11,6,1,4,11\n"
                     "4,9,1,11,2,1,2,3,1,11,11,4,8,8,1,2,1,4,2,4,1,10,11,8,3,3,11,1,3,4,4,11,5,4,11,11,6,1,2,7,5,1,3,1,2,8,3,3,1,9\n"
                     "8,4,7,7,5,2,2,4,4,10,1,1,9,9,5,1,8,3,6,11,2,11,4,5,4,6,5,11,2,10,9,2,6,8,1,3,3,4,8,11,2,1,11,3,10,8,4,10,11,10\n"
                     "-1,1,1,6,10,5,-1,8,4,6,6,5,8,4,6,2,8,-1,6,8,-1,-1,8,11,3,10,8,11,-1,11,-1,10,1,2,4,3,7,5,11,4,3,-1,1,-1,2,7,2,2,8,-1\n"
                     "10,8,1,6,1,7,9,1,7,6,11,8,4,4,3,9,8,2,6,11,6,9,1,1,1,7,11,7,9,8,7,7,8,11,5,1,11,2,1,10,1,4,10,5,8,1,6,8,4,1\n"
                     "8,2,1,9,2,7,4,2,2,5,2,2,1,2,5,9,3,4,1,7,2,4,11,5,9,8,6,7,4,10,11,4,1,1,5,7,8,1,1,2,6,3,4,10,10,2,8,1,6,1\n"
                     "1,1,4,1,6,6,1,1,1,8,3,1,1,8,6,6,7,6,8,9,8,6,1,5,5,10,7,1,3,5,5,4,6,9,8,4,7,8,9,9,4,1,2,9,1,8,8,7,2,8\n"
                     "4,2,2,9,7,7,11,2,1,3,8,5,11,6,7,11,11,2,7,8,3,3,1,5,1,1,5,1,11,7,9,4,10,11,5,9,11,4,1,11,11,1,9,10,6,8,9,9,2,8\n"
                     "5,6,-1,-1,3,5,-1,-1,6,-1,8,3,5,6,6,10,4,5,2,8,-1,2,8,10,4,6,6,6,4,8,6,1,6,10,11,10,3,-1,11,1,1,7,8,10,6,7,8,2,-1,3\n"
                     "2,1,9,2,11,5,8,9,3,4,10,10,10,4,8,9,6,4,1,5,9,7,5,6,5,3,1,2,5,5,9,7,7,6,9,10,3,9,1,7,2,10,5,1,6,5,1,1,9,6\n"
                     "10,7,1,7,5,7,10,10,1,7,3,10,6,2,8,7,5,3,5,5,10,11,7,7,3,1,5,8,6,2,2,5,1,4,4,10,3,3,8,4,2,4,6,9,6,6,4,3,9,1\n"
                     "8,1,1,3,11,7,9,4,3,3,11,10,8,4,6,5,3,9,8,3,5,2,7,3,11,6,1,4,9,2,9,10,2,10,5,2,9,2,10,1,6,9,11,6,2,9,11,5,6,11\n"
                     "8,3,2,8,6,5,2,11,1,3,1,11,1,8,9,7,2,6,1,1,11,11,10,2,6,1,11,9,9,9,1,9,1,7,5,10,1,11,9,2,3,11,1,8,7,2,7,9,1,9\n"
                     "1,-1,8,11,6,6,3,6,8,4,7,-1,2,8,4,11,6,4,3,8,10,10,11,11,6,6,1,2,7,6,3,8,6,3,-1,4,10,3,2,6,8,10,7,2,6,3,5,4,7,8\n"
                     "4,6,6,3,9,5,9,3,7,8,9,10,5,7,1,5,11,3,1,2,1,1,1,1,6,10,3,1,6,11,1,11,9,11,2,6,4,4,1,3,1,10,5,9,5,10,6,5,6,7\n"
                     "11,7,7,11,8,2,1,3,6,7,2,10,6,3,9,9,2,5,1,3,8,5,2,5,3,11,4,9,4,10,4,3,9,4,6,9,10,7,1,8,3,7,6,1,3,4,10,5,1,3\n"
                     "1,2,9,6,7,4,6,3,1,10,5,10,6,3,6,4,4,4,1,9,1,7,5,6,8,1,2,11,5,4,6,9,6,7,4,5,11,10,9,5,1,2,3,10,9,9,3,6,5,7\n"
                     "3,9,2,1,3,2,1,10,5,9,6,1,7,4,7,11,9,11,9,10,4,1,5,7,1,2,8,3,1,5,10,4,2,4,8,5,10,9,7,4,6,1,8,5,5,7,4,7,6,5\n"
                     "5,10,7,10,-1,11,5,-1,2,5,2,4,1,4,-1,10,2,2,11,-1,6,5,3,6,3,-1,2,7,7,8,5,5,11,4,3,8,3,8,10,5,6,-1,1,7,5,1,5,11,7,8\n"
                     "8,2,6,3,1,9,4,2,8,3,3,1,8,2,5,4,2,8,4,1,5,10,5,6,6,2,11,3,1,7,1,1,1,6,5,5,7,1,8,3,4,3,5,5,5,2,9,11,11,1\n"
                     "4,8,4,9,7,10,3,10,5,4,9,9,5,2,7,10,8,2,3,4,10,8,7,3,5,4,9,2,7,1,7,11,9,11,1,4,1,3,6,11,11,4,8,5,6,8,7,2,2,11\n"
                     "10,1,11,5,7,4,1,5,10,9,5,9,1,6,9,5,2,2,1,9,1,1,1,2,9,11,10,4,2,4,7,1,5,6,10,4,2,11,1,4,8,7,2,1,5,3,6,8,5,6\n"
                     "5,7,6,10,9,3,9,11,1,3,3,7,4,1,6,6,5,1,5,10,5,6,5,11,7,3,2,5,11,11,11,8,6,10,10,7,5,7,6,9,3,2,9,11,2,3,5,11,3,10\n"
                     "10,-1,8,7,3,7,10,5,-1,1,5,4,-1,3,2,7,11,11,7,-1,1,2,11,10,1,6,1,6,5,8,8,7,1,5,7,4,-1,5,2,1,11,11,-1,-1,2,3,-1,5,2,7\n"
                     "3,3,1,2,1,2,8,6,8,6,7,8,1,8,1,8,1,6,6,6,11,5,5,8,9,8,11,9,5,5,8,8,1,9,11,2,11,11,1,11,5,8,8,11,4,1,11,8,7,9\n"
                     "3,10,6,1,6,4,8,9,1,6,3,10,2,4,7,5,10,11,5,3,10,2,11,10,5,7,1,5,4,11,2,11,10,9,11,8,1,1,10,2,6,1,4,8,9,1,6,11,11,11\n"
                     "3,1,5,2,4,11,10,4,4,6,7,10,5,9,7,8,10,1,8,8,7,2,1,11,3,10,11,9,9,2,1,1,8,5,3,1,8,5,8,4,11,3,3,8,5,2,4,3,7,5\n"
                     "3,2,7,4,1,2,2,5,3,3,11,7,8,7,5,3,7,1,8,3,6,11,11,1,7,8,3,3,3,10,8,6,4,8,10,6,2,4,3,6,11,2,1,7,10,6,10,9,1,10\n"
                     "1,6,-1,4,7,8,-1,2,-1,3,5,8,-1,-1,8,11,7,11,7,10,5,10,5,10,6,3,-1,8,-1,-1,7,5,7,4,-1,6,5,-1,8,5,4,5,5,5,7,6,4,2,5,3\n"
                     "5,2,2,10,1,1,1,1,1,5,10,7,3,9,4,1,3,9,2,4,6,10,9,3,4,4,9,8,11,2,4,4,8,10,6,1,2,11,2,2,4,5,10,7,2,6,1,6,7,6\n"
                     "10,1,4,11,8,8,4,6,9,7,1,5,3,9,3,9,10,5,8,4,11,4,9,1,1,1,7,4,6,2,2,4,7,6,3,8,7,11,6,8,10,6,1,1,7,4,10,9,1,6\n"
                     "2,4,11,11,6,3,11,1,11,9,8,1,5,7,11,1,7,6,1,1,2,3,1,7,4,7,3,7,9,4,5,11,9,8,2,7,11,6,1,2,3,8,7,9,8,7,10,3,5,2\n"
                     "9,1,9,9,7,2,8,11,1,5,7,6,8,8,3,11,3,6,9,4,1,4,4,8,1,4,3,3,8,9,10,5,1,11,6,8,5,2,11,6,8,7,1,4,7,8,7,11,2,4\n"
                     "7,3,-1,11,4,2,4,7,10,4,8,-1,1,-1,11,7,10,5,-1,-1,3,-1,8,4,6,4,4,1,7,11,10,2,6,11,5,10,5,1,6,3,-1,6,7,10,8,11,-1,10,8,11\n"
                     "11,11,8,8,8,2,4,1,8,11,11,6,5,6,5,2,4,10,4,2,6,1,1,5,4,9,4,1,11,1,4,10,1,1,10,1,7,2,1,3,5,1,1,2,10,6,5,2,9,9\n"
                     "9,7,2,10,1,6,11,9,1,10,1,4,8,1,9,7,5,9,1,6,1,7,10,2,9,8,1,6,2,1,3,11,8,10,1,1,4,1,10,8,2,11,5,11,5,6,10,10,3,3\n"
                     "8,4,2,6,10,4,2,10,10,5,4,6,8,1,4,10,5,1,10,7,9,1,7,6,4,4,1,6,6,8,9,3,4,4,9,2,8,4,4,6,9,1,1,5,1,4,3,10,5,6\n"
                     "6,6,11,5,4,3,9,8,1,7,4,2,10,8,6,1,2,2,4,11,9,1,11,1,10,4,6,6,3,3,1,1,1,11,6,5,6,3,1,11,10,10,1,1,10,8,1,5,10,5\n"
                     "8,11,10,11,1,8,4,11,6,11,2,6,4,3,-1,10,-1,7,5,1,6,7,3,8,8,2,8,1,7,6,6,3,6,8,2,11,5,10,10,3,1,-1,10,5,7,11,3,7,11,-1\n"
                     "1,5,8,4,5,4,10,1,6,5,1,4,1,10,1,2,9,10,5,7,1,10,11,3,4,6,3,11,5,6,1,5,11,8,1,9,4,11,2,10,8,2,7,8,1,8,3,9,10,1\n"
                     "8,3,10,7,7,2,1,2,6,10,8,6,8,11,6,9,1,10,1,3,1,1,9,8,10,10,8,5,11,6,5,1,9,7,7,8,10,1,10,8,11,10,2,7,2,8,9,2,6,2\n"
                     "5,7,3,3,7,1,5,3,10,8,1,7,8,3,3,8,11,5,9,2,1,1,4,3,8,6,3,9,9,1,11,6,9,2,1,8,8,6,1,6,7,1,6,3,4,9,3,8,2,1\n"
                     "2,3,1,6,10,1,1,1,2,2,2,1,8,3,7,10,1,3,8,4,2,3,5,1,11,2,9,2,2,3,7,4,6,1,2,8,5,3,9,7,5,3,8,6,11,7,8,11,3,4\n"
                     "3,-1,-1,-1,-1,11,6,6,5,-1,-1,4,4,7,4,7,3,-1,2,4,8,-1,11,8,10,10,4,6,1,7,10,8,4,10,-1,1,1,7,11,11,8,-1,3,4,7,-1,3,2,1,6\n"
                     "6,10,10,5,10,8,8,2,2,9,1,4,6,9,7,7,2,8,6,1,11,2,1,7,11,1,11,2,2,1,1,1,2,10,6,1,10,6,7,1,3,9,9,1,10,4,1,1,4,7\n"
                     "6,4,1,1,11,1,1,10,7,7,2,7,7,5,10,5,10,1,11,9,5,7,6,2,8,9,6,9,10,10,8,8,2,9,8,5,2,1,7,9,8,10,8,7,7,10,1,9,11,4\n"
                     "6,4,11,5,6,8,2,1,9,4,2,5,1,5,6,9,2,8,2,10,9,2,1,6,9,7,8,2,8,7,7,2,3,6,7,9,6,1,1,7,5,4,4,6,1,11,7,7,7,1\n"
                     "5,5,3,9,3,4,8,11,7,4,7,6,11,2,4,6,1,3,1,5,10,5,1,3,3,6,2,2,2,1,7,11,10,10,9,1,7,9,5,2,2,4,1,1,6,4,11,6,11,15 \n"
                     "0,0 \n"
                     "49,49 \n";

//     bfs :
//    BFS_DFS<vector<State<Node> *>, Node> b(new Queue<State<Node> *>);
//    vector<State<Node> *> vec = b.search(&m);
/*
    SearchableSolver s;
    string p = s.solve(input25);
    FileCacheManager fileCacheManager;
    fileCacheManager.save(input25, p);
    fileCacheManager.saveToFile();
*/


/*
    int avg = m.getAverageWeight();
    BestFS_Astar<vector<State<Node>*>, Node, ManhattenAverageWeight>
            b(new MinHeap<State<Node>*>,new ManhattenAverageWeight(avg));
    vector<State<Node>*> vec = b.search(&m);
*/
//    cout << vec.at(0)->getCost() <<"," << b.getNumberOfNodesEvaluated() <<  endl;

}
