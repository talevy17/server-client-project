#include <iostream>
#include "SearchableSolver.h"
#include "MatrixCacheManager.h"
#include "MatrixClientHandler.h"
#include "ParallelServer.h"

using namespace std;

/**
 * create parallel server, get port from the user
 * and start solving problems!
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char  *argv[]) {
    if (argc<2){throw "Not enough arguments";}
    int port = stoi(argv[1]);
    pthread_mutex_t mutex;
    SearchableSolver searchableSolver;
    MatrixCacheManager matrixManager;
    MatrixClientHandler matrixClientHandler(&matrixManager, &searchableSolver, mutex);
    ParallelServer server;
    server.open(port,&matrixClientHandler);
    //while there are clients.
    while (server.isConnected()){}
    matrixManager.saveToFile();
}