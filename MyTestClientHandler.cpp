#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include "MyTestClientHandler.h"

#define BUF 256

/**
 * the function read line - gets problem
 * and check if there is an available solution
 * if there isn't - solve and return it to the server.
 * @param sockfd
 */
void MyTestClientHandler::handleClient(int sockfd) {
//if there is no input
    this->sockfd = sockfd;
    string problem = readLine();
    string solution;
    //gets the solution
    if (this->manager->isThereASolution(problem)) {
        solution = this->manager->getSolution(problem);
    } else {
        solution = this->solver->solve(problem);
    }
    ::send(this->sockfd, solution.c_str(), strlen(solution.c_str()), 0);
}

/**
 * the function read line by gets input from the server
 * @return string - problem
 */
string MyTestClientHandler::readLine() {
    ssize_t valread;
    char buffer[BUF] = {0};
    listen(this->sockfd, 5);
    valread = read(this->sockfd, buffer, sizeof(buffer));
    if (valread < 0) {
        perror("Error reading from socket");
    }
    std::string myString(buffer, BUF);
    return buffer;
}

/**
 * @return true - if should stop, false - else
 */
bool MyTestClientHandler::shouldStop() {
    return this->stop;
}