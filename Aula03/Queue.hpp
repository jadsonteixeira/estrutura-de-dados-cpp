// Header file queue.hpp
#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>

using namespace std;

#define DEFAULT_CAPACITY 10

class Queue {
    private:
        int * data;
        int capacity;
        int front;
        int rear;

        void resize(int newCapacity);
        void deallocate();

        bool isFull() const;
        bool isEmpty() const;

    public:
        Queue(int capacity = DEFAULT_CAPACITY);
        Queue(const Queue & queue);

        ~Queue();

        void enqueue(int value);
        int dequeue();

        int getCapacity() const;

        void clear();

        void print();

        const Queue & operator=(const Queue & queue);

        int getFront() const;
        int getRear() const;
    
};

#endif