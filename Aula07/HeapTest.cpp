#include "MaxHeap.hpp"

int main(void) {
    MaxHeap heap1;
    MaxHeap heap2;

    cout << " ### EMPTY HEAP1 ###\n";
    heap1.print();

    cout << "\n\n ### INSERTING ELEMENTS INTO HEAP1 ###\n";
    heap1.insert(10);
    heap1.insert(7);
    heap1.insert(5);
    heap1.insert(22);
    heap1.insert(2);

    heap1.print();
    
    cout << "\n\n ### COPYING HEAP1 TO HEAP2 ###\n";
    heap2 = heap1;
    cout << "\n";
    heap2.insert(8);
    heap2.print();

    cout << "\n\n ### CLEANING HEAP1 ###\n";
    heap1.clear();
    heap1.print();

    cout << "\n\n ### BUILDING HEAP3 FROM VECTOR ###\n";
    vector <int> array = {7, 11, 2, 8, 1, 4, 20};
    MaxHeap heap3(array);
    heap3.print();

    cout << "\n\n ### EXTRACTING MAX FROM HEAP3 ###\n";
    cout << " Max Priority: " << heap3.extractMax() << "\n";
    heap3.print();

    cout << "\n\n ### UPDATING I = 4 FROM HEAP3 ###\n";
    heap3.update(4,25);
    heap3.print();    

    cout << "\n\n ### UPDATING I = 0 FROM HEAP3 ###\n";
    heap3.update(0,1);
    heap3.print();    
}