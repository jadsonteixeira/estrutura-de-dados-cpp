// Header file Stack.hpp
#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include <string>

using namespace std;

#define DEFAULT_CAPACITY 10
#define ERROR_EMPTY -1010

class Stack {
    private:
        int * data;     
        int capacity;       
        int top;        

        void resize(int newCapacity);
        void deallocate();

        bool isFull() const;

    public:
        Stack(int capacity = DEFAULT_CAPACITY);   
        Stack(const Stack & stack);       

        ~Stack();  

        void push(int value);  
        int pop();             
        int peek() const;      
        
        int getCapacity() const;
        int getSize() const;
        
        void clear();
        bool isEmpty() const;

        void print(const string & header = "") const;

        const Stack & operator=(const Stack & stack);
        friend ostream & operator<<(ostream & os, const Stack & stack);              
};

#endif