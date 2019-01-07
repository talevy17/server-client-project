#ifndef SERVER_CLIENT_PROJECT_CLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_CLIENTHANDLER_H

#include <fstream>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int sockfd) = 0;
};

#endif //SERVER_CLIENT_PROJECT_CLIENTHANDLER_H
