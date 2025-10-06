// implementation file
#include "Queue.hpp"

Queue::Queue(int capacity) {
    if (capacity <= 0) {
        this->capacity = DEFAULT_CAPACITY;
        cout << "Invalid capacity! Setting default capacity!";
    } else {
        this->capacity = capacity;
    }

    this->data = new int [this->capacity];
    this->front = -1;
    this->rear = -1;
}

Queue::Queue(const Queue & queue) {

}

Queue::~Queue() {

}

void Queue::enqueue(int value) {
    if (this->isEmpty()) {
        this->front = 0;
        this->data[this->front] = value;
        this->rear++;
    } else {
        this->data[rear] = value;
        this->rear++;
    }
}

int Queue::dequeue() {

}

int Queue::getCapacity() const {
    return this->capacity;
}

void Queue::clear() {

}

void Queue::print() {
    for (int i = 0; i < this->rear; i++) {
        cout << this->data[i] << " ";
    }
}

const Queue & Queue::operator=(const Queue & queue) {

}

void Queue::resize(int newCapacity) {
    int * newData = new int [newCapacity];

    for (int i = 0; i < this->capacity; i++) {
        newData[i] = this->data[i];
    }

    this->deallocate();
    this->data = newData;
    this->capacity = newCapacity;
}

void Queue::deallocate() {
    delete [] this->data;
}

bool Queue::isFull() const {
    return this->rear == (this->capacity - 1);
}

bool Queue::isEmpty() const {
    return this->front == -1 && this->rear == -1;
}

int Queue::getFront() const {
    return this->front;
}

int Queue::getRear() const {
    return this->rear;
}