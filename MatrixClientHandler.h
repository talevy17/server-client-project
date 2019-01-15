#ifndef SERVER_CLIENT_PROJECT_MATRIXCLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_MATRIXCLIENTHANDLER_H


#include "ClientHandler.h"

class MatrixClientHandler : public ClientHandler {
    virtual void handleClient(int sockfd);

    virtual bool shouldStop();
};


#endif //SERVER_CLIENT_PROJECT_MATRIXCLIENTHANDLER_H
