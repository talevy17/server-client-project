#ifndef SERVER_CLIENT_PROJECT_FIRSTSEARCHNODE_H
#define SERVER_CLIENT_PROJECT_FIRSTSEARCHNODE_H

#include "Node.h"
#include "State.h"
#include "Matrix.h"

enum Visit{WHITE = 0, GRAY = 1, BLACK = 2};
class FirstSearchVisit{
    int row;
    int col;
    Visit ** matrix;
public:
    FirstSearchVisit(int row, int col);
    void initMatrix ();
    Visit getVisitState(int i, int j);
    void setVisitState(int i, int j);
};


#endif //SERVER_CLIENT_PROJECT_FIRSTSEARCHNODE_H
