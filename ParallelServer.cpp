
#include "ParallelServer.h"

/**
 * thread function, handles a client and closes the socket when done.
 * @param sockfd
 * @param client
 * @return
 */
static void *start(int sockfd, ClientHandler *client) {
    while (!client->shouldStop()) {
        client->handleClient(sockfd);
    }
    close(sockfd);
    pthread_exit(nullptr);
}

/**
 * opens the connection and starts accepting clients and handling them parallel.
 * @param port
 * @param client
 */
void ParallelServer::open(int port, ClientHandler *client) {
    int opt = 1;
    struct sockaddr_in server;
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    this->isRunning = true;
    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    while (this->isRunning) {
        //Accept and incoming connection
        socklen_t addrlen = sizeof(sockaddr_in);
        struct sockaddr_in clie;
        //if this is not the first client - wait only 1 sec for connection
        int newsockfd = accept(sockfd, (struct sockaddr *) &clie, &addrlen);
        if (newsockfd < 0) {
            if (errno == EWOULDBLOCK) {
                this->isRunning = false;
                break;
            } else {
                perror("other error");
                exit(EXIT_FAILURE);
            }
        }
        thread *t1 = new thread (start, newsockfd, client);
        this->threads.push_back(t1);
        //this->threads.push_back(t1);
    }
}

/**
 * check if the server is still accepting clients for outside use.
 * @return bool isRunning
 */
bool ParallelServer::isConnected() { return this->isRunning; }

/**
 * waits for all the threads to finish their client handling and closes the socket.
 */
void ParallelServer::stop() {
    for (auto tr: this->threads) {
        tr->join();
        delete tr;
    }
    close(this->sockfd);
}