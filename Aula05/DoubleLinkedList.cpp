#include "DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList() {
    this->head = this->tail = nullptr;
    this->length = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList & list) {

}

DoubleLinkedList::~DoubleLinkedList() {
    this->clear();
}

bool DoubleLinkedList::isEmpty() const {
    return this->head == nullptr;
}

int DoubleLinkedList::getLength() const {
    return this->length;
}

void DoubleLinkedList::clear() {
    if (!this->isEmpty()) {
        Node * current = this->head;
        Node * aux;

        while (current != nullptr) {
            aux = current;
            current = current->next;
            delete aux;
        }

        this->head = this->tail = nullptr;
        this->length = 0;
    }
}

void DoubleLinkedList::print(Order order) const {
    Node * current = (order == Order::FORWARD) ? this->head : this->tail;

    while (current != nullptr) {
        cout << current->key << " ";
        current = (order == Order::FORWARD) ? current->next : current->previous;
    }
}

const Node * DoubleLinkedList::search(int key) const {
    Node * current = this->head;

    while (current != nullptr && current->key < key) {
        current = current->next;
    }

    if (current != nullptr && current->key == key) {
        return current;
    }

    return nullptr;
}

bool DoubleLinkedList::insert(int key) {
    Node * current = this->head;
    Node * previous = nullptr;

    // percorre até encontrar o ponto onde o novo nó entra
    while (current != nullptr && current->key < key) {
        previous = current;
        current = current->next;
    }

    // se encontrar um nó com a mesma key, não insere
    if (current != nullptr && current->key == key) {
        return false;
    }
    
    Node * newNode = new Node();
    newNode->key = key;

    // inserir no início
    if (previous == nullptr) {
        newNode->next = head;
        newNode->previous = nullptr;

        // se lista não estava vazia, ajusta o prev do head anterior
        if (this->head != nullptr) {
            this->head->previous = newNode;
        } else {
            // se estava vazia
            this->tail = newNode;
        }

        this->head = newNode;
    } else {
        newNode->next = current;
        newNode->previous = previous;
        previous->next = newNode;

        // insere no meio
        if (current != nullptr) {
            current->previous = newNode;
        } else {
            // insere no fim
            this->tail = newNode;
        }
    }

    this->length++;

    return true;
}

bool DoubleLinkedList::remove(int key) {

}

void DoubleLinkedList::concatenate(const DoubleLinkedList & list) {
    Node * current = list.head;

    while (current != nullptr) {
        this->insert(current->key);  // insere mantendo ordenação
        current = current->next;
    }
}

const DoubleLinkedList & DoubleLinkedList::operator=(const DoubleLinkedList & list) {

}

const DoubleLinkedList & DoubleLinkedList::operator+(const DoubleLinkedList & list) {

}