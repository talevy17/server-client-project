#include <iostream>
#include "MySerialServer.h"

static void *threadLoop(int sockfd, ClientHandler *client, bool* isRunning) {
    bool first = true;
    while (*isRunning) {
        //Accept and incoming connection
        socklen_t addrlen = sizeof(sockaddr_in);
        struct sockaddr_in clie;
        //if this is not the first client - wait only 1 sec for connection
        if (!first) {
            timeval timeout;
            timeout.tv_sec = 10;
            timeout.tv_usec = 0;
            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        }
        int newsockfd = accept(sockfd, (struct sockaddr *) &clie, &addrlen);
        if (newsockfd < 0) {
            if (errno == EWOULDBLOCK) {
                perror("timeout");
                exit(EXIT_FAILURE);
            } else{
                perror("other error");
                exit(EXIT_FAILURE);
            }
        }
        while (!client->shouldStop()) {
            client->handleClient(newsockfd);
        }
        first = false;
        close(newsockfd);
    }
    pthread_exit(nullptr);
}

/**
* open a socket and handle the client's requests.
* @param port int
* @param client ClientHandler*
*/
void MySerialServer::open(int port, ClientHandler *client) {
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
    thread t1(threadLoop,sockfd, client, &isRunning);
    t1.join();
}

/**
 * is there a client connected to the server
 * @return bool isConnected
 */
bool MySerialServer::isConnected() { return this->isRunning; }

/**
 * stops the current connection.
 */
void MySerialServer::stop() {
    if (this->isRunning) {
        close(this->sockfd);
    }
    this->isRunning = false;
}
