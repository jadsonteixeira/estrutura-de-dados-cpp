#ifndef _DOUBLE_LINKED_LIST_
#define _DOUBLE_LINKED_LIST_

#include <iostream>
#include <cstdlib>

using std::cout; // puxa apenas a função do cout

struct Node {
    Node * previous;
    int key;
    Node * next;
};

enum Order {
    FORWARD,
    BACKWARD
};

class DoubleLinkedList {
    private:
        Node * head;
        Node * tail;

        int length;

    public:
        DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList & list); // const deixa claro que a list não será modificada dentro do método

        ~DoubleLinkedList();

        bool isEmpty() const;
        int getLength() const;

        void clear();
        void print(Order order = Order::FORWARD) const;

        const Node * search(int key) const;
        bool insert(int key);
        bool remove(int key);

        void concatenate(const DoubleLinkedList & list);

        const DoubleLinkedList & operator=(const DoubleLinkedList & list);
        const DoubleLinkedList & operator+(const DoubleLinkedList & list);
};

#endif