#include "LinkedList.hpp"

int main(void) {
    LinkedList list01;

    cout << "\n # Inserindo em LIST01 .....";
    list01.insert(7);
    list01.insert(10);
    list01.insert(25);
    list01.insert(15);
    list01.insert(8);
    list01.insert(2);
    list01.insert(6);
    list01.insert(1);

    list01.print();

    cout << "\n\n # Instanciando LIST02, copia de LIST01 .....";
    LinkedList list02 = LinkedList(list01);
    list02.print();

    cout << "\n\n # Removendo chaves de LIST02 .....";
    list02.remove(30);
    list02.remove(7);
    list02.remove(25);
    list02.remove(10);
    list02.remove(1);
    list02.remove(2);
    list02.print();

    LinkedList list03;

    cout << "\n\n # Utilizando sobrecarga: LIST03 = LIST02 .....";
    list03 = list02;
    list03.print();

    cout << "\n\n # Utilizando sobrecarga: LIST03 = LIST01 .....";
    list03 = list01;
    list03.print();

    return 0;
}