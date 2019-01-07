#ifndef SERVER_CLIENT_PROJECT_STRINGREVERSER_H
#define SERVER_CLIENT_PROJECT_STRINGREVERSER_H

#include "string"
#include "Solver.h"
class StringReverser : public Solver<std::string, std::string> {
    virtual std::string solve(std::string problem);
};


#endif //SERVER_CLIENT_PROJECT_STRINGREVERSER_H
