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

/**
 * a Server implementation, handles a single client at a time.
 */
class MySerialServer : public Server {
    int sockfd;
    int newsockfd;
    bool isRunning;

public:

    /**
     * open a socket and handle the client's requests.
     * @param port int
     * @param client ClientHandler*
     */
    virtual void open(int port, ClientHandler *client);

    /**
    * stops the current connection.
    */
    virtual void stop();

    /**
    * is there a client connected to the server
    * @return bool isConnected
    */
    virtual bool isConnected();
};

#endif //SERVER_CLIENT_PROJECT_MYSERIALSERVER_H
