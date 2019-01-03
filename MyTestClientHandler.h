#ifndef SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
    //solution solve(problem p);
    virtual void handleClient(ofstream &output, ifstream &input);
};


#endif //SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
