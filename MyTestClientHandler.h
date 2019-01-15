#ifndef SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
#define SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"

using namespace std;

class MyTestClientHandler : public ClientHandler {
    CacheManager<string,string>* manager;
    Solver<string,string>* solver;
    int sockfd;
    bool stop;
public:
    MyTestClientHandler(CacheManager<string, string>* cacheManager,
            Solver<string,string>* solver);
    virtual void handleClient(int sockfd);
    void getInput(string &str);
    virtual bool shouldStop();
};


#endif //SERVER_CLIENT_PROJECT_MYTESTCLIENTHANDLER_H
