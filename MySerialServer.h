#ifndef SERVER_CLIENT_PROJECT_MYSERIALSERVER_H
#define SERVER_CLIENT_PROJECT_MYSERIALSERVER_H

#include "server_side.h"

using namespace server_side;

class MySerialServer : public Server {
    int sockfd;

public:

    virtual void open(int port, ClientHandler* client);

    virtual void stop();
};

#endif //SERVER_CLIENT_PROJECT_MYSERIALSERVER_H
