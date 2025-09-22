#include "Array.hpp"

int main(void) {
    Array a1;                // Array(10)
    Array a2(5);             // Array(5)
    Array a3 = Array(15);    // Array(15)

    cout << " --- IMPRIMINDO a1 ---";
    a1.imprimir();

    cout << "\n\n --- ADICIONANDO em a1 ---";
    a1.inserir(10);
    a1.inserir(-5);
    a1.inserir(3);

    a1.imprimir();

    cout << "\n\n --- COPIAR a1 em a2 ---";
    a2 = a1;
    a2.imprimir();

    cout << "\n\n --- PREENCHENDO a3 ---";
    for(int i = 0; i < a3.getCapacidade(); i++) {
        a3.inserir(i);
    }

    a3.imprimir();
    
    cout << "\n\n -- TESTE REALOCACAO em a3 --";
    a3.inserir(50);
    cout << "\n Nova capacidade de a3: " << a3.getCapacidade();

    a3.imprimir();

    cout << "\n\n -- TESTE CONSTRUTOR DE COPIA --";
    Array a4 = Array(a3);

    a4.imprimir();

    cout << "\n\n -- TESTE SOBRECARGA DE [] --";
    a4[a4.getTamanho() - 1] = 25;

    a4.imprimir();
    cout << "\n a4[5]: " << a4[5];

    try {
        a4[100] = 100;
    } catch(const std::out_of_range & e) {
        cout << "\n\n ## ERRO: " << e.what();
    }

    return 0;
}