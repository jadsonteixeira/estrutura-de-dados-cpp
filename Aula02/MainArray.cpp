#include <cstdlib>
#include "Array.hpp"

int main() {
    system("cls");

    Array a1 = Array(5);

    cout << "ADICIONANDO ELEMENTOS EM a1";
    for (int i = 0; i < a1.getCapacidade(); i++) {
        a1.inserir(i + 1);
    }
    a1.imprimir();
    cout << "Tamanho: " << a1.getTamanho() << endl;
    cout << "Capacidade: " << a1.getCapacidade() << endl;
    
    return 0;
}