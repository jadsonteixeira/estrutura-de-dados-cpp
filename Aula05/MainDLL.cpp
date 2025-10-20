#include "DoubleLinkedList.hpp"

int main() {
    system("cls");

    DoubleLinkedList dll1;

    dll1.insert(5);
    dll1.insert(1);
    dll1.insert(9);
    dll1.insert(3);
    cout << "DLL: ";
    dll1.print();
    cout << "\nLength: " << dll1.getLength();
    cout << "Search: " << dll1.search(1);

    return 0;
}