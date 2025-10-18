// implementation file
#include "Queue.hpp"

Queue::Queue(int capacity) {
    if (capacity <= 0) {
        cout << "ERROR: invalid capacity";
        capacity = DEFAULT_CAPACITY;
    }

    this->capacity = capacity;
    this->front = 0;
    this->rear = -1;
    this->quantityElements = 0;
    this->data = new int [this->capacity];
}

Queue::Queue(const Queue & queue) {
    this->capacity = queue.capacity;
    this->data = new int [this->capacity];

    for (int i = 0; i < queue.getQuantityElements(); i++) {
        this->data[i] = queue.data[i];
    }

    this->rear = queue.rear;
    this->quantityElements = queue.getQuantityElements();
}

Queue::~Queue() {
    this->deallocate();
}

void Queue::enqueue(int value) {
    if (this->getRear() + 1 == this->getCapacity()) {
        this->capacity *= 2;
        this->resize(this->capacity);
    }

    this->data[this->rear + 1] = value;
    this->rear++;
    this->quantityElements++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Queue is empty");
    }

    int value = this->data[this->front];

    for (int i = 0; i < this->getQuantityElements(); i++) {
        this->data[i] = this->data[i + 1];
    }

    this->rear--;
    this->quantityElements--;

    return value;
}

int Queue::getCapacity() const {
    return this->capacity;
}

void Queue::clear() {
    this->quantityElements = 0;
    this->rear = -1;
}

void Queue::print() {
    cout << "\nQueue: \n";
    for (int i = 0; i < this->getQuantityElements(); i++) {
        cout << this->data[i] << " ";
    }
    cout << "\n";
}

const Queue & Queue::operator=(const Queue & queue) {
    this->capacity = queue.getCapacity();
    this->rear = queue.getRear();

    delete [] this->data;

    this->data = new int[this->capacity];

    for (int i = 0; i < queue.getCapacity(); i++) {
        this->data[i] = queue.data[i];
    }

    return *this;
    
}

void Queue::resize(int newCapacity) {
    int * temp = new int[newCapacity];

    for (int i = 0; i < this->getQuantityElements(); i++) {
        temp[i] = this->data[i];
    }

    delete [] data;
    data = temp;

    this->capacity = newCapacity;
}

void Queue::deallocate() {
    delete [] data;
}

bool Queue::isFull() const {
    return this->rear == this->getCapacity();
}

bool Queue::isEmpty() const {
    return this->rear == -1;
}

int Queue::getFront() const {
    return this->front;
}

int Queue::getRear() const {
    return this->rear;
}

int Queue::getQuantityElements() const {
    return this->quantityElements;
}