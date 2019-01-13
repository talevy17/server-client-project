#ifndef SERVER_CLIENT_PROJECT_PARSER_H
#define SERVER_CLIENT_PROJECT_PARSER_H

#include <string>
#include "Matrix.h"

using namespace std;
typedef vector<string> strvec;

class Interpreter {
public:
    Matrix stringToMatrix(string input);
    Matrix parser(strvec rowVec, string init, string goal);
};


#endif //SERVER_CLIENT_PROJECT_PARSER_H
