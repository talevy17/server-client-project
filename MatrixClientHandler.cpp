#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include "MatrixClientHandler.h"

#define BUF 256

/**
 * constructor
 * @param cacheManager
 * @param solver
 */
MatrixClientHandler::MatrixClientHandler(CacheManager<string, string> *cacheManager,
                                         Solver<string, string> *solver,
                                         pthread_mutex_t &mutex) : mutex(mutex) {
    this->manager = cacheManager;
    this->solver = solver;
    this->stop = false;
}

/**
 * the function read line - gets problem
 * and check if there is an available solution
 * if there isn't - solve and return it to the server.
 * @param sockfd
 */
void MatrixClientHandler::handleClient(int sockfd) {
    this->sockfd = sockfd;
    string problem;
    getInput(problem);
    string solution;
    //gets the solution
    if (this->manager->isThereASolution(problem)) {
        pthread_mutex_lock(&mutex);
        solution = this->manager->getSolution(problem);
        pthread_mutex_unlock(&mutex);
    } else {
        solution = this->solver->solve(problem);
        pthread_mutex_lock(&mutex);
        this->manager->save(problem,solution);
        pthread_mutex_unlock(&mutex);
    }
    ::send(this->sockfd, solution.c_str(), strlen(solution.c_str()), 0);
}

/**
 * the function read lines of input from the server
 * @return string - problem
 */
void MatrixClientHandler::getInput(string &problem) {
    ssize_t valread;
    char buffer[BUF] = {0};
    listen(this->sockfd, 5);
    //while the user didn't send "end"
    while (true) {
        valread = read(sockfd, buffer, BUF);
        if (valread < 0) {
            perror("Error reading from socket");
        }
        std::string line(buffer, BUF);
        if (line == ("end")) { return; }
        problem.append(buffer);
    }
}

/**
 * @return true - if should stop, false - else
 */
bool MatrixClientHandler::shouldStop() {
    return this->stop;
}