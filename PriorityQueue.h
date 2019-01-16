
#ifndef SERVER_CLIENT_PROJECT_PRIORITYQUEUE_H
#define SERVER_CLIENT_PROJECT_PRIORITYQUEUE_H

/**
 * priority queue interface, keeping the dependency inversion intact.
 * @tparam T
 */
template<class T>
class PriorityQueue {
public:

    /**
     * push an element to the queue.
     * @param element
     */
    virtual void push(T element) = 0;

    /**
     * pop an element from the queue
     * @return T element
     */
    virtual T pop() = 0;

    /**
     * find an element in the queue.
     * @param element
     * @return int index.
     */
    virtual int find(T element) = 0;

    /**
     * replace an element in the queue.
     * @param element to add
     * @param index of an element to replace.
     */
    virtual void replace(T element, int index) = 0;

    /**
     * element getter
     * @param i index
     * @return the i'th element.
     */
    virtual T getElement(int i) = 0;

    /**
     * check if the queue is empty.
     * @return bool isEmpty.
     */
    virtual bool isEmpty() = 0;

    virtual ~PriorityQueue(){ }
};

#endif //SERVER_CLIENT_PROJECT_PRIORITYQUEUE_H
