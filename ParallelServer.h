

#ifndef SERVER_CLIENT_PROJECT_PARALLELSERVER_H
#define SERVER_CLIENT_PROJECT_PARALLELSERVER_H


#include "server_side.h"
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <queue>

class ParallelServer : public server_side::Server {
    int sockfd;
    bool isRunning;
    std::queue<thread> threads;
public:

    virtual void open(int port, ClientHandler *client);

    virtual bool isConnected();

    virtual void stop();
};


#endif //SERVER_CLIENT_PROJECT_PARALLELSERVER_H
