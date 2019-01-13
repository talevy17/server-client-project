#ifndef SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
#define SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H

#include <string>
#include "SearcherWrapper.h"

using namespace std;
template <class Solution , class T>
class BFS_DFS : public SearcherWrapper<Solution,T> {
    vector<T> visit;
public:
    typedef vector<State<T>> stateVec;

    BFS_DFS(PriorityQueue<State<Node>> *pq) : SearcherWrapper<Solution,T>(pq){}

    virtual Solution search(Searchable<T> searchable){
        State<T> state = searchable.getInitialState();
        this->openList->push(state);
        while (!this->openList->isEmpty()){

        }
    }

    void bfsDfs(Searchable<T> searchable, State<T> node){
        typename stateVec :: iterator adjIter;
        for (adjIter = node.begin(); adjIter < node ; ++adjIter){
            //if not visited - visit.
            if (this->visit.find(node) != this->visit.end()) {
                this->visit.push_back(*adjIter);
                this->openList->push(*adjIter);
                bfsDfs(searchable.getAllPossibleStates(*adjIter));
            }
        }
    }
};


/**

class Graph {
    int numVertices;
    list *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list[vertices];
    visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list adjList = adjLists[vertex];

    list::iterator i;
    for(i = adjList.begin(); i != adjList.end(); ++i)
        if(!visited[*i])
            DFS(*i);
}
 */


#endif //SERVER_CLIENT_PROJECT_DEPTHFIRSTSEARCH_H
