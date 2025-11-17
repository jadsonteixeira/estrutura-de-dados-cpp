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
    cout << "\nLength: " << dll1.getLength() << "\n\n";

    DoubleLinkedList dll2;
    dll2.insert(4);
    dll2.insert(2);
    dll2.insert(8);
    dll2.print();

    cout << "\n\nTest concatenate: \n";
    dll1.concatenate(dll2);
    dll1.print();

    return 0;
}