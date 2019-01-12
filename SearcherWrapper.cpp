
#include "SearcherWrapper.h"

SearcherWrapper::SearcherWrapper(PriorityQueue<State<Node>> *pq) {
    this->openList = pq;
    this->evaluatedNodes = 0;
}

int SearcherWrapper::getNumberOfNodesEvaluated() { return this->evaluatedNodes; }

State<Node> SearcherWrapper::popOpenList() {
    if (!this->openList->isEmpty()) {
        this->evaluatedNodes++;
        return this->openList->pop();
    }
    return State<Node>(Node(-1, -1), -1, nullptr);
}