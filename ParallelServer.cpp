
#include "ParallelServer.h"

static void *start(int sockfd, ClientHandler *client) {
    while (!client->shouldStop()) {
        client->handleClient(sockfd);
    }
    close(sockfd);
    pthread_exit(nullptr);
}


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
            } else{
                perror("other error");
                exit(EXIT_FAILURE);
            }
        }
        thread t1(start,newsockfd, client);
        this->threads.push(t1);
    }
}

bool ParallelServer::isConnected() {return this->isRunning;}

void ParallelServer::stop() {
    while (!this->threads.empty()) {
        this->threads.front().join();
        this->threads.pop();
    }
    close(this->sockfd);
}