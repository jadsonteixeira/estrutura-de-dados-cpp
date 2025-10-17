#include "DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList() {
    this->head = this->tail = nullptr;
    this->lenght = 0;
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
    return this->lenght;
}

void DoubleLinkedList::clear() {
    if(!this->isEmpty()) {
        Node * current = this->head;
        Node * aux;

        while(current != nullptr) {
            aux = current;
            current = current->next;
            delete aux;
        }

        this->head = this->tail = nullptr;
        this->lenght = 0;
    }
}

void DoubleLinkedList::print(Order order) const {
    Node * current = (order == Order::FORWARD) ? this->head : this->tail;

    while(current != nullptr) {
        cout << current->key << " ";     
        current = (order == Order::FORWARD) ? current->next : current->previous;     
    }    
}

const Node * DoubleLinkedList::search(int key) const {
    Node * current = this->head;

    while(current != nullptr && current->key < key) {
        current = current->next;
    }

    if(current != nullptr && current->key == key) {
        return current;
    }

    return nullptr;
}

bool DoubleLinkedList::insert(int key) {
    Node * current = this->head;

    while(current != nullptr && current->key < key) {
        current = current->next;
    }

    if(current != nullptr && current->key == key) {
        return false;
    } else {
        Node * newNode = new Node();
        newNode->key = key;

        if(current == this->head) {
            newNode->next = this->head;
            this->head = newNode;
            newNode->previous = nullptr;
            if(newNode->next != nullptr) {
                newNode->next->previous = newNode;
            } else {
                this->tail = newNode;
            }
        }

        return true;
    }
}

bool DoubleLinkedList::remove(int key) {

}

void DoubleLinkedList::concatenate(const DoubleLinkedList &list) {

}

const DoubleLinkedList & DoubleLinkedList::operator=(const DoubleLinkedList &list) {

}

const DoubleLinkedList & DoubleLinkedList::operator+(const DoubleLinkedList &list) {

}