#ifndef SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"

using namespace std;

class MatrixClientHandler : public ClientHandler {
    CacheManager<string,string>* manager;
    Solver<string,string>* solver;
    int sockfd;
    bool stop;;
public:
    /**
     * constructor
     * @param cacheManager
     * @param solver
     * @param mutex1
     */
    MatrixClientHandler(CacheManager<string, string>* cacheManager,
            Solver<string,string>* solver);
    /**
     * connect to client, get input and solve problems
     * @param sockfd
     */
    virtual void handleClient(int sockfd);
    /**
     * get input from client
     * @param str
     */
    void getInput(string &str);
    /**
     *
     * @return true if there is no input, false else.
     */
    virtual bool shouldStop();

    virtual void setStop ();
};


#endif //SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
