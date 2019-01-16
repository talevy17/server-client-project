

#ifndef SERVER_CLIENT_PROJECT_MINHEAP_H
#define SERVER_CLIENT_PROJECT_MINHEAP_H

#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

/**
 * Minimum heap priority queue implementation.
 * @tparam T
 */
template<class T>
class MinHeap : public PriorityQueue<T> {
    std::vector<T> elements;

    /**
     * swapping two elements, for heapify methods.
     * @param i
     * @param j
     */
    void swap(int i, int j) {
        T temp = this->elements.at(i);
        this->elements.at(i) = this->elements.at(j);
        this->elements.at(j) = temp;
    }

    /**
     * parent index getter.
     * @param i
     * @return int parentIndex.
     */
    int parent(int i) { return (i - 1) / 2; }

    /**
     * left child index getter.
     * @param i
     * @return int leftChildIndex
     */
    int leftChild(int i) { return (2 * i) + 1; }

    /**
     * fight child index getter.
     * @param i
     * @return int rightChildIndex
     */
    int rightChild(int i) { return (2 * i) + 1; }

    /**
     * heapify from the given index to re-balance the heap.
     * @param i index
     */
    void heapify(int i) {
        size_t size = elements.size();
        int l = leftChild(i);
        int r = rightChild(i);
        //compare the two children with the parent.
        int smallest = i;
        if (l < this->elements.size() && this->elements.at(l) <= this->elements.at(i))
            smallest = l;
        if (r < this->elements.size() && this->elements.at(r) <= this->elements.at(smallest))
            smallest = r;
        //if a smaller node was found below, swap the parent with the child and call heapify again.
        if (smallest != i)
        {
            swap(i, smallest);
            heapify(smallest);
        }
    }

public:
    /**
     * default CTOR.
     */
    MinHeap() {}

    /**
     * CTOR.
     * @param element
     */
    MinHeap(T element) {
        this->elements.push_back(element);
    }

    /**
     * add an element to the heap, assuming the element as the > operator overloaded.
     * @param element
     */
    void push(T element) {
        this->elements.push_back(element);
        int i = this->elements.size() - 1;
        while (i != 0 && *(this->elements.at(parent(i))) >= *(this->elements.at(i))) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    /**
     * extracting the minimum from the heap.
     * @return T min
     */
    T pop() {
        T min = this->elements.at(0);
        reverse(this->elements.begin(), this->elements.end());
        this->elements.pop_back();
        reverse(this->elements.begin(), this->elements.end());
        heapify(0);
        return min;
    }

    /**
     * find an element in the heap, returns the index if found, -1 if it doesnt exist.
     * @param element to find
     * @return int index.
     */
    int find(T element) {
        size_t size = this->elements.size();
        for (unsigned long i = 0; i < size; ++i) {
            if (*(this->elements.at(i)) == *(element)) {
                return i;
            }
        }
        return -1;
    }

    /**
     * decreasing the key of an element in the index given.
     * @param element the element to add
     * @param index the index to replace.
     */
    void replace(T element, int index) {
        //the index is invalid.
        if (index >= this->elements.size() || index < 0) {
            return;
        }
        //swap the index'th element.
        this->elements.at(index) = element;
        int i = index;
        //while the replaced element is smaller than his parent, swap them.
        while (i != 0 && *(this->elements.at(parent(i))) >= *(this->elements.at(i)))
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    /**
     * returns the ith element in the heap.
     * @param i
     * @return T element.
     */
    T getElement(int i) {
        if (this->elements.size() <= i) {
            throw "invalid index";
        }
        return this->elements.at(i);
    }

    /**
     * checks if the heap is empty.
     * @return bool isEmpty.
     */
    bool isEmpty() {return this->elements.empty();}

    virtual ~MinHeap() {
        while (!this->elements.empty()) {
            T elem = this->elements.back();
            this->elements.pop_back();
            delete (elem);
        }
    }
};


#endif //SERVER_CLIENT_PROJECT_MINHEAP_H
