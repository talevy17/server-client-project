#ifndef SERVER_CLIENT_PROJECT_CLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_CLIENTHANDLER_H

#include <fstream>

using namespace std;

class ClientHandler {
    virtual void handleClient(ofstream &output, ifstream &input) = 0;
};

#endif //SERVER_CLIENT_PROJECT_CLIENTHANDLER_H
