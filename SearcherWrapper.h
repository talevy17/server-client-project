//
// Created by tal on 1/12/19.
//

#ifndef SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H
#define SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H

#include "PriorityQueue.h"
#include "Searcher.h"
#include "Searchable.h"
#include <string>
#include "Node.h"

class SearcherWrapper : public Searcher<std::string, Node> {
protected:
    PriorityQueue<State<Node>> *openList;
    int evaluatedNodes;

    State<Node> popOpenList();
public:
    SearcherWrapper(PriorityQueue<State<Node>> *pq);

    int getNumberOfNodesEvaluated();

};


#endif //SERVER_CLIENT_PROJECT_SEARCHERWRAPPER_H
