//
// Created by tal on 1/12/19.
//

#ifndef SERVER_CLIENT_PROJECT_PRIORITYQUEUE_H
#define SERVER_CLIENT_PROJECT_PRIORITYQUEUE_H

template<class T>
class PriorityQueue {
public:

    virtual void push(T element) = 0;

    virtual T pop() = 0;

    virtual int find(T element) = 0;

    virtual void replace(T element, int index) = 0;

    virtual T getElement(int i) = 0;

    virtual bool isEmpty() = 0;
};

#endif //SERVER_CLIENT_PROJECT_PRIORITYQUEUE_H
