#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int sockfd) {
    //read line from input stream
    //check if there is solution
    //return it if there is
    //what if there is no solution
    //send it to output stream
}

/*
string handleClient :: readLine() {
    ssize_t valread;
    this->isRunning = true;
    char buffer[BUF] = {0};
    while (this->isRunning) {
        listen(this->sockfd, 5);
        valread = read(this->newsockfd, buffer, sizeof(buffer));
        if (valread < 0) {
            perror("Error reading from socket");
        }
        vector<double> values = xmlDataSplitter(buffer);
        this->data.setFlightData(values);
    }
    return "exit";
}
 */