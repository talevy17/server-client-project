//
// Created by tal on 1/12/19.
//

#ifndef SERVER_CLIENT_PROJECT_STACK_H
#define SERVER_CLIENT_PROJECT_STACK_H

#include "PriorityQueue.h"
#include <stack>
template <class T>
class Stack : public PriorityQueue<T> {
    std::stack<T> elements;
public:
    virtual void push(T element) {
        this->elements.push(element);
    }

    virtual T pop() {
        T elem = this->elements.top();
        this->elements.pop();
        return elem;
    }

    virtual int find(T element) {
        return -1;
    }

    virtual void replace(T element, int index) { return; }

    virtual T getElement(int i) { return this->elements.top(); }

    virtual bool isEmpty() { return this->elements.empty(); }

    virtual ~Stack() {
        while (!this->elements.empty()) {
            T elem = this->elements.top();
            this->elements.pop();
            delete elem;
        }
    }

};
#endif //SERVER_CLIENT_PROJECT_STACK_H
