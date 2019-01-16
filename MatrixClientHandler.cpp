#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <iostream>
#include "MatrixClientHandler.h"

#define BUF 256
#define END "end\n"

/**
 * constructor
 * @param cacheManager
 * @param solver
 */
MatrixClientHandler::MatrixClientHandler(CacheManager<string, string> *cacheManager,
                                         Solver<string, string> *solver) {
    this->manager = cacheManager;
    this->solver = solver;
    this->stop = false;
}

void MatrixClientHandler::setStop() {
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
        solution = this->manager->getSolution(problem);
    } else {
        solution = this->solver->solve(problem);
        this->manager->save(problem, solution);
    }
    ::send(this->sockfd, solution.c_str(), strlen(solution.c_str()), 0);
    this->stop = true;
}

/**
 * function delete word from string
 * @param input
 * @param delim
 */
void deleteDelim(string &input, string delim){
    ssize_t end = input.find(delim);
    input = input.substr(0,end-1);
}

/**
 * the function read lines of input from the server
 * @return string - problem
 */
void MatrixClientHandler::getInput(string &problem) {
    ssize_t valread;
    char buffer[BUF];
    string buff;
    //while the user didn't send "end"
    while (buff.find(END) == string::npos) {
        valread = read(sockfd, buffer, BUF);
        if (valread < 0) {
            perror("Error reading from socket");
        } else if (valread == 0) {
            perror("connection reset");
            return;
        }
        buffer[valread] = 0;
        buff += string(buffer);
    }
    problem.append(buff);
    deleteDelim(problem, END);
}


/**
 * @return true - if should stop, false - else
 */
bool MatrixClientHandler::shouldStop() {
    return this->stop;
}