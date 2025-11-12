// Arquivo de definição de classe que implementa uma
// MAXHEAP (as maiores prioridades possuem os maiores valores)

#ifndef _MAX_HEAP_HPP_
#define _MAX_HEAP_HPP_

#include <iostream>
#include <vector>
#include <stdexcept>

using std::vector;
using std::cout;

class MaxHeap {
    private:
        vector <int> heap;
        
        int parent(int index) const;
        int leftChild(int index) const;
        int rightChild(int index) const;

        void heapifyUp(int index);
        void heapifyDown(int index);

        void swap(int index1, int index2);

    public:
        MaxHeap() = default;
        MaxHeap(const vector <int> & array);
        MaxHeap(const MaxHeap & heap);

        bool isEmpty() const;
        int size() const;
        int getMax() const;

        void insert(int value);    
        int extractMax();
        void update(int index, int value);        
        
        int search(int value) const;
        void clear();

        void print() const;

        MaxHeap & operator=(const MaxHeap & rightHeap);
};

// ***** OBSERVAÇÕES:
   // Como poderia se transformar um vector em um vector que
   // atende as propriedades de uma heap?
#endif