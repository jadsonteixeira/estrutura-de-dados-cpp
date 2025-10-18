#include <iostream>
#include "Pilha.h"

using namespace std;

int main() {
    Pilha p1;
    TipoItem item;
    int opcao;

    do {
        cout << "\n0 - Sair\n";
        cout << "1 - Inserir\n";
        cout << "2 - Remover\n";
        cout << "3 - Imprimir\n";
        cout << "\nOpcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Digite o elemento: ";
            cin >> item;
            p1.inserir(item);
        } else if (opcao == 2) {
            item = p1.remover();
            cout << "Elemento removido: " << item << endl;
        } else if (opcao == 3) {
            p1.imprimir();
        }

    } while (opcao != 0);

    return 0;
}