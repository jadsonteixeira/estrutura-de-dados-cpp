// arquivo de implementação
#include "Stack.hpp"

Stack::Stack(int size) {
    if (size <= 0) {
        cout << "ERROR: invalid capacity";
        size = DEFAULT_SIZE;
    }

    this->size = size;
    this->top = 0;
    this->data = new int [this->size];
} 

Stack::Stack(const Stack & stack) {
    this->size = stack.size;
    this->data = new int [this->size];

    for (int i = 0; i < stack.top; i++) {
        this->data[i] = stack.data[i];
    }

    this->top = stack.top;
}

Stack::~Stack() {
    delete [] data;
}

void Stack::push(int value) {
    if (this->size == this->top) {
        this->size *= 2;
        this->resize(this->size);
    }

    this->data[top] = value;
    this->top++;
}

int Stack::pop() {
    
}

int Stack::peek() const {
    return this->size;
}

void Stack::clear() {
    this->size = 0;
}

bool Stack::isEmpty() const {
    return this->size == 0;
}

void Stack::printStack() const {
    cout << "\nSTACK: ";
    for (int i = 0; i < this->size; i++) {
        cout << this->data[i] << " ";
    }
    cout << "\n";
}

void Stack::resize(int newSize) {
    int * temp = new int [newSize];

    for (int i = 0; i < this->top; i++) {
        temp[i] = this->data[i];
    }

    delete [] data;
    data = temp;

    this->size = newSize;
}

const Stack & Stack::operator=(const Stack & stack) {

}