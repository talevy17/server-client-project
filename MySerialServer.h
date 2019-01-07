#ifndef SERVER_CLIENT_PROJECT_MYSERIALSERVER_H
#define SERVER_CLIENT_PROJECT_MYSERIALSERVER_H
#include "server_side.h"
#include "vector"
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "strings.h"

using namespace server_side;

class MySerialServer : public Server {
    int sockfd;
    int newsockfd;
    bool isConnected;

public:

    virtual void open(int port, ClientHandler* client);

    virtual void stop();
};

#endif //SERVER_CLIENT_PROJECT_MYSERIALSERVER_H
