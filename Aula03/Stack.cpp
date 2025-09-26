// arquivo de implementação
#include "Stack.hpp"

Stack::Stack(int size) { // OK
    if (size <= 0) {
        cout << "ERROR: invalid capacity";
        size = DEFAULT_SIZE;
    }

    this->size = size;
    this->top = -1; // pilha está vazia
    this->data = new int [this->size];
} 

// tem um problema que não consigo identificar
Stack::Stack(const Stack & stack) { // OK
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

// auxiliar
int Stack::getSize() const {
    return this->size; // retorna o tamanho
}

// auxiliar
int Stack::getTop() const {
    return this->top; // retorna a posição do topo
}

// auxiliar
int Stack::quantityElements() const {
    return this->getTop() + 1;
}

// auxiliar
void Stack::removeLast() {
    this->top--;
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
    // TO DO - Não consegui fazer utilizando retorno de função
    // Alterei pra uma função chamada removeLast do tipo void
}

int Stack::peek() const { // OK
    return this->data[top];
}

void Stack::clear() { // OK
    this->top = -1;
}

bool Stack::isEmpty() const { // OK
    return this->top != -1;
}

void Stack::printStack() const { // OK
    cout << "\nStack: \n";
    for (int i = 0; i <= this->top; i++) {
        cout << this->data[i] << " ";
    }
    cout << "\n";
}

void Stack::resize(int newSize) { // OK
    int * temp = new int[newSize];

    for (int i = 0; i < this->top; i++) {
        temp[i] = this->data[i];
    }

    delete [] data;
    data = temp;

    this->size = newSize;
}

// tem um problema que não consigo identificar
const Stack & Stack::operator=(const Stack & stack) {
    this->size = stack.size;
    this->top = stack.top;

    delete [] this->data;

    this->data = new int[this->size];

    for (int i = 0; i < stack.top; i++) {
        this->data[i] = stack.data[i];
    }

    return *this;
}