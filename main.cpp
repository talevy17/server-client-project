#include <iostream>
#include "SearchableSolver.h"
#include "MatrixCacheManager.h"
#include "MatrixClientHandler.h"
#include "ParallelServer.h"
#include "Interpreter.h"

using namespace std;

/**
 * create parallel server, get port from the user
 * and start solving problems!
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc<2){throw "Not enough arguments";}
    int port = stoi(argv[1]);
    SearchableSolver searchableSolver;
    MatrixCacheManager matrixManager;
    MatrixClientHandler matrixClientHandler(&matrixManager, &searchableSolver);
    ParallelServer server;
    server.open(port,&matrixClientHandler);
    //while there are clients.
    while (server.isConnected()){}
    server.stop();
    matrixManager.saveToFile();
}