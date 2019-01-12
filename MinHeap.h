

#ifndef SERVER_CLIENT_PROJECT_MINHEAP_H
#define SERVER_CLIENT_PROJECT_MINHEAP_H

#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

template<class T>
class MinHeap : PriorityQueue<T> {
    std::vector<T> elements;

    void swap(int i, int j) {
        T temp = this->elements.at(i);
        this->elements.at(i) = this->elements.at(j);
        this->elements.at(j) = temp;
    }

    int parent(int i) { return (i - 1) / 2; }

    int leftChild(int i) { return (2 * i) + 1; }

    int rightChild(int i) { return (2 * i) + 1; }

    void heapify(int i) {
        size_t size = elements.size();
        int l = leftChild(i);
        int r = rightChild(i);
        int smallest = i;
        if (l < this->elements.size() && this->elements.at(l) < this->elements.at(i))
            smallest = l;
        if (r < this->elements.size() && this->elements.at(r) < this->elements.at(smallest))
            smallest = r;
        if (smallest != i)
        {
            swap(i, smallest);
            heapify(smallest);
        }
    }

public:
    MinHeap() {}

    MinHeap(T element) {
        this->elements.push_back(element);
    }

    void push(T element) {
        this->elements.push_back(element);
        int i = this->elements.size() - 1;
        while (i != 0 && this->elements.at(parent(i)) > this->elements.at(i)) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    T pop() {
        T min = this->elements.at(0);
        reverse(this->elements.begin(), this->elements.end());
        this->elements.pop_back();
        reverse(this->elements.begin(), this->elements.end());
        heapify(0);
        return min;
    }

    int find(T element) {
        size_t size = this->elements.size();
        for (unsigned long i = 0; i < size; ++i) {
            if (this->elements.at(i).equals(element)) {
                return i;
            }
        }
        return -1;
    }

    void replace(T element, int index) {
        if (index >= this->elements.size()) {
            return;
        }
        this->elements.at(index) = element;
        int i = index;
        while (i != 0 && this->elements.at(parent(i)) > this->elements.at(i))
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    T getElement(int i) {
        if (this->elements.size() <= i) {
            throw "invalid index";
        }
        return this->elements.at(i);
    }

    bool isEmpty() {return this->elements.empty();}
};


#endif //SERVER_CLIENT_PROJECT_MINHEAP_H
