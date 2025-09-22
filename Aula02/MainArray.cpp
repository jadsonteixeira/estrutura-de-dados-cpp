#include <cstdlib>
#include "Array.hpp"

int main() {
    system("cls");

    Array a1 = Array(5);
    Array a2 = Array(5);

    cout << "ARRAY a1: ";
    a1.imprimir();

    cout << "ADICIONANDO ELEMENTOS EM a1";
    for (int i = 0; i < a1.getCapacidade(); i++) {
        a1.inserir(i + 1);
    }
    cout << endl;
    cout << "ARRAY a1: ";
    a1.imprimir();

    cout << endl;

    cout << "ARRAY a2: ";
    a2 = a1;
    a2.imprimir();
    cout << "TAMANHO DO ARRAY a2: " << a2.getCapacidade();

    cout << "TESTE AUMENTO DE TAMANHO ARRAY a2: ";
    a2.inserir(6);
    a2.imprimir();
    cout << "CAPACIDADE DO ARRAY a2: " << a2.getCapacidade();

    cout << endl;
    cout << "TESTE SE ARRAY a1 TEM ELEMENTOS: " << a1.temElementos();

    a1.limpar();
    
    cout << endl;
    cout << "ARRAY a1 TEM ELEMENTOS: " << a1.temElementos();
    
    return 0;
}