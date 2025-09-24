// Header file stack.hpp
#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>

using namespace std;

#define DEFAULT_SIZE 10

class Stack {
    private:
        int * data;     // dynamic array
        int size;       // array size
        int top;        // stack's top

        void resize(int newSize);

    public:
        Stack(int size = DEFAULT_SIZE);     // constructor
        Stack(const Stack & stack);         // copy constructor
        ~Stack();   // class destructor

        void push(int value);   // insert element
        int pop();              // remove element
        int peek() const;       // search element
        
        void clear();
        bool isEmpty() const;

        void printStack() const;

        const Stack & operator=(const Stack & stack);

        int getSize() const;

};

#endif