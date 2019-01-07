#include "MySerialServer.h"

void MySerialServer:: open(int port, ClientHandler *client) {
    int opt = 1;
    struct sockaddr_in server, clie;

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

    //Accept and incoming connection
    socklen_t addrlen = sizeof(sockaddr_in);
    newsockfd = accept(sockfd, (struct sockaddr *) &clie, &addrlen);
    if (newsockfd < 0) {
        perror("failed opening socket");
        exit(EXIT_FAILURE);
    }
    this->isRunning = true;
    while (this->isRunning) {
        client->handleClient(this->newsockfd);
    }
}

bool MySerialServer::isConnected() {return this->isRunning;}

void MySerialServer:: stop() {
    if (this->isRunning) {
        close(this->sockfd);
        close(this->newsockfd);
    }
    this->isRunning = false;
}