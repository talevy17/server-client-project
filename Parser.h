#ifndef SERVER_CLIENT_PROJECT_PARSER_H
#define SERVER_CLIENT_PROJECT_PARSER_H

#include <string>
#include "Matrix.h"

using namespace std;

class Parser {
public:
    //main function, from matrix to sring
    Matrix stringToMatrix (string matrix, string init, string goal);
};


#endif //SERVER_CLIENT_PROJECT_PARSER_H
