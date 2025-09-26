// implementation file
#include "Stack.hpp"

Stack::Stack(int size) {
    if (size <= 0) {
        cout << "ERROR: invalid capacity";
        size = DEFAULT_SIZE;
    }

    this->size = size;
    this->top = -1;
    this->data = new int [this->size];
} 

Stack::Stack(const Stack & stack) {
    this->size = stack.size;
    this->data = new int [this->size];

    for (int i = 0; i <= stack.top; i++) {
        this->data[i] = stack.data[i];
    }

    this->top = stack.top;
}

Stack::~Stack() {
    delete [] data;
}

int Stack::getSize() const {
    return this->size;
}

int Stack::getTop() const {
    return this->top;
}

int Stack::quantityElements() const {
    return this->getTop() + 1;
}

void Stack::push(int value) {
    if (this->quantityElements() == this->size) {
        this->size *= 2;
        this->resize(this->size);
    }

    this->data[this->top + 1] = value;
    this->top++;
}

int Stack::pop() {
    if (isEmpty()) {
        throw out_of_range("Stack is empty");
    }

    int value = this->data[this->top];
    this->top--;
    return value;
}

int Stack::peek() const {
    return this->data[top];
}

void Stack::clear() {
    this->top = -1;
}

bool Stack::isEmpty() const {
    return this->top == -1;
}

void Stack::printStack() const {
    cout << "\nStack: \n";
    for (int i = 0; i <= this->top; i++) {
        cout << this->data[i] << " ";
    }
    cout << "\n";
}

void Stack::resize(int newSize) {
    int * temp = new int[newSize];

    for (int i = 0; i <= this->top; i++) {
        temp[i] = this->data[i];
    }

    delete [] data;
    data = temp;

    this->size = newSize;
}

const Stack & Stack::operator=(const Stack & stack) {
    this->size = stack.size;
    this->top = stack.top;

    delete [] this->data;

    this->data = new int[this->size];

    for (int i = 0; i <= stack.top; i++) {
        this->data[i] = stack.data[i];
    }

    return *this;
}