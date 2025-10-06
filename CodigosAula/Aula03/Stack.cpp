// Arquivo de implementação
#include "Stack.hpp"

Stack::Stack(int capacity) {
    if(capacity <= 0) {
        this->capacity = DEFAULT_CAPACITY;
        cout << " Invalid capacity! Setting default capacity!";
    } else {
        this->capacity = capacity;
    }

    this->data = new int [this->capacity];
    this->top = -1;
}

Stack::Stack(const Stack &stack) {
    this->deallocate();

    this->capacity = stack.capacity;
    this->data = new int [this->capacity];
    
    for(int i = 0; i <= stack.top; i++) {
        this->data[i] = stack.data[i];
    }

    this->top = stack.top;
}

Stack::~Stack() {
    this->deallocate();
}

void Stack::push(int value) {
    if(this->isFull()) {
        this->resize(this->capacity * 1.5);
    }

    this->top++;
    this->data[this->top] = value;
}

int Stack::pop() {
    if(!this->isEmpty()) {        
        return this->data[this->top--];
    }

    cout << "\n Empty stack!" << endl;
    return ERROR_EMPTY;
}

int Stack::peek() const {
    if(!this->isEmpty()) {
        return this->data[this->top];
    }

    cout << "\n Empty stack!" << endl;
    return ERROR_EMPTY;
}

int Stack::getCapacity() const {
    return this->capacity;
}

int Stack::getSize() const {
    return this->top + 1;
}

void Stack::clear() {
    this->top = -1;
}

bool Stack::isEmpty() const {
    return this->top == -1;
}

void Stack::print(const string & header) const {
    if(!this->isEmpty()) {
        if(header.empty()) {
            cout << "\n Stack: ";
        } else {
            cout << "\n " << header;
        }
        for(int i = this->top; i >= 0; i--) {
            cout << this->data[i] << " ";
        }
    } else {
        cout << " Empty stack!";
    }
}

const Stack &Stack::operator=(const Stack &stack) {
    this->deallocate();

    this->data = new int [stack.capacity];
    for(int i = 0; i <stack.capacity; i++) {
        this->data[i] = stack.data[i];
    }

    this->top = stack.top;
    this->capacity = stack.capacity;

    return *this;
}

ostream & operator<<(ostream & os, const Stack & stack) {

    for(int i = stack.top; i >= 0; i--) {
        os << stack.data[i] << " ";
    }
    
    return os;
}

void Stack::resize(int newCapacity) {
    int * newData = new int [newCapacity];

    for(int i = 0; i < this->capacity; i++) {
        newData[i] = this->data[i];
    }

    this->deallocate();
    this->data = newData;
    this->capacity = newCapacity;
}

void Stack::deallocate() {
    delete [] this->data;
}

bool Stack::isFull() const {
    return this->top == (this->capacity - 1);
}