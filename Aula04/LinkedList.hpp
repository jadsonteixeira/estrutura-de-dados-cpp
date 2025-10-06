#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node * next;
};

class LinkedList {
    private:
        Node * head;
        int length;

        Node * auxiliarSearch(int key) const;

    public:
        LinkedList();
        LinkedList(const LinkedList & list);

        ~LinkedList();

        int getLength() const;
        void clear();

        void print() const;
        bool isEmpty() const;

        Node * search(int key) const;

        bool insert(int key);
        bool remove(int key);

        const LinkedList &operator=(const LinkedList & list);
};

#endif