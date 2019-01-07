#ifndef SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
public:
    virtual void handleClient(int sockfd);
    //string readLine();
};


#endif //SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
