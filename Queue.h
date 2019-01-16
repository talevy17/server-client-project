
#ifndef SERVER_CLIENT_PROJECT_QUEUE_H
#define SERVER_CLIENT_PROJECT_QUEUE_H

#include "PriorityQueue.h"
#include <queue>

template<class T>
class Queue : public PriorityQueue<T> {
    std::queue<T> elements;
public:
    virtual void push(T element) {
        this->elements.push(element);
    }

    virtual T pop() {
        T elem = this->elements.front();
        this->elements.pop();
        return elem;
    }

    virtual int find(T element) {
        return -1;
    }

    virtual void replace(T element, int index) { return; }

    virtual T getElement(int i) { return this->elements.front(); }

    virtual bool isEmpty() { return this->elements.empty(); }

    virtual ~Queue() {
        while (!this->elements.empty()) {
            T elem = this->elements.front();
            this->elements.pop();
            delete elem;
        }
    }
};

#endif //SERVER_CLIENT_PROJECT_QUEUE_H
