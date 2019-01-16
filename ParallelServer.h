#ifndef SERVER_CLIENT_PROJECT_PARALLELSERVER_H
#define SERVER_CLIENT_PROJECT_PARALLELSERVER_H


#include "server_side.h"
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <vector>

/**
 * accepts clients on parallel threads and handle their requests.
 */
class ParallelServer : public server_side::Server {
    int sockfd;
    bool isRunning;
    std::vector<thread> threads;

    int acceptClient();
public:

    /**
    * opens the connection and starts accepting clients and handling them parallel.
    * @param port
    * @param client
    */
    virtual void open(int port, ClientHandler *client);

    /**
    * check if the server is still accepting clients for outside use.
    * @return bool isRunning
    */
    virtual bool isConnected();

    /**
    * waits for all the threads to finish their client handling and closes the socket.
    */
    virtual void stop();
};


#endif //SERVER_CLIENT_PROJECT_PARALLELSERVER_H
