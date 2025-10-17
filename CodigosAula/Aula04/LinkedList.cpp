#include "LinkedList.hpp"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->length = 0;
}

LinkedList::LinkedList(const LinkedList & list) {
    if (!list.isEmpty()) {
        this->length = list.length;
        Node * ptr = list.head;

        Node * temp1 = new Node();            
        Node * temp2;
        this->head = temp1;
        temp1->key = ptr->key;
        ptr = ptr->next;

        while(ptr != nullptr) {
            temp2 = new Node();            
            temp1->next = temp2;
            temp2->key = ptr->key;
            ptr = ptr->next;
            temp1 = temp2;
        }

        temp1->next = nullptr;

        return;
    }

    this->head = nullptr;
    this->length = 0;
}

LinkedList::~LinkedList() {
    this->clear();
}

int LinkedList::getLength() const {
    return this->length;
}

void LinkedList::clear() {
    if(!this->isEmpty()) {
        Node * ptr1 = this->head;
        this->head = nullptr;
        this->length = 0;

        Node * ptr2 = ptr1->next;
        while(ptr2 != nullptr) {
            delete ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->next;            
        }

        delete ptr1;
    }    
}

void LinkedList::print() const {
    Node * ptr = this->head;

    cout << "\n LINKED LIST: ";
    while(ptr != nullptr) {
        cout << ptr->key << " ";
        ptr = ptr->next;
    }
}

bool LinkedList::isEmpty() const {
    return this->head == nullptr;
}

Node * LinkedList::search(int key) const {
    Node * ptr = this->head;
    Node * ptrData = nullptr;

    while(ptr->key != key && ptr != nullptr) {
        ptr = ptr->next;        
    }

    if(ptr != nullptr) {
        ptrData = new Node();
        ptrData->next = nullptr;
        ptrData->key = ptr->key;
    }

    return ptrData;
}

Node * LinkedList::auxiliarSearch(int key) const {
    Node * ptr = this->head;
    Node * ptrAnt = nullptr;

    while(ptr != nullptr && ptr->key < key) {
        ptrAnt = ptr;
        ptr = ptr->next;
    }

    return ptrAnt;
}

bool LinkedList::insert(int key) {

    Node * ptr = this->auxiliarSearch(key);

    if (ptr == nullptr && (this->head != nullptr && this->head->key != key) || this->head == nullptr) {
        Node * newNode = new Node();
        newNode->key = key;
        newNode->next = this->head;
        this->head = newNode;

        this->length++;
        return true;

    } else if ((ptr->next == nullptr || (ptr->next != nullptr && ptr->next->key != key))) {
        Node * newNode = new Node();
        newNode->key = key;
        newNode->next = ptr->next;
        ptr->next = newNode;            
        
        this->length++;
        return true;
    }

    return false;
}

bool LinkedList::remove(int key) {
    if(!isEmpty()) {        
        Node * ptr = this->auxiliarSearch(key);

        if(ptr == nullptr) {
            if(this->head->key == key) {
                Node * aux = this->head;
                this->head = this->head->next;

                delete aux;
                this->length--;

                return true;                
            }
        } else if(ptr->next != nullptr && ptr->next->key == key) {
            Node * aux = ptr->next;
            ptr->next = ptr->next->next;

            delete aux;
            this->length--;

            return true;
        }
    }

    return false;
}

const LinkedList & LinkedList::operator=(const LinkedList & list) {
    if(this != &list) {
        this->clear();

        if (!list.isEmpty()) {
            this->length = list.length;
            Node * ptr = list.head;

            Node * temp1 = new Node();            
            Node * temp2;
            this->head = temp1;
            temp1->key = ptr->key;
            ptr = ptr->next;

            while(ptr != nullptr) {
                temp2 = new Node();            
                temp1->next = temp2;
                temp2->key = ptr->key;
                ptr = ptr->next;
                temp1 = temp2;
            }

            temp1->next = nullptr;            
        }        
    }

    return *this;
}