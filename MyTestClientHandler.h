#ifndef SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
    virtual void handleClient(int sockfd);
};


#endif //SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
