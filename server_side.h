#ifndef SERVER_CLIENT_PROJECT_SERVER_SIDE_H
#define SERVER_CLIENT_PROJECT_SERVER_SIDE_H

#include "ClientHandler.h"

namespace server_side {
    class Server {

        virtual void open(int port, ClientHandler* client) = 0;

        virtual bool isConnected() = 0;

        virtual void stop() = 0;
    };
}


#endif //SERVER_CLIENT_PROJECT_SERVER_SIDE_H