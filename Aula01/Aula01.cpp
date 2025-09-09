#include <iostream>
#include <cstdlib>

using namespace std;

// definindo um rótulo
#define N_VETOR 5 // diretiva: no meu código, onde tiver o nome N_VETOR, vai ser trocado por 5 no ato da compilação

int main (void) {
    system("cls");

    const int TAMANHO = 5; // aloca posição na memória

    int num;
    int vetor[N_VETOR];
    int *ptrInt = nullptr; // ponteiro inicializado sem referência

    cout << "-> Digite um numero: ";
    cin >> num;

    for (int i = 0; i < N_VETOR; i++) {
        cout << " vetor[" << i << "]: ";
        cin >> vetor[i];
    }

    cout << "-> Numero: " << num << endl;
    cout << "-> Vetor: ";
    for (int i = 0; i < N_VETOR; i++) {
        cout << vetor[i] << " ";
    }

    ptrInt = &num; // guardando no ponteiro, o endereço da variável num

    cout << "\n ptrInt: " << ptrInt;
    cout << "\n &ptrInt: " << &ptrInt; // endereço do ponteiro
    // pegando o conteúdo armazenado no endereço do ponteiro
    cout << "\n *ptrInt (num): " << *ptrInt; // operador de deferenciação: quando vamos na referência e pergamos o seu conteúdo

    *ptrInt = 15; // mudando o valor da variável num via ponteiro

    cout << "\n-> Numero: " << num << endl;

    // TO DO
    cout << "\n Vetor: " << vetor;
    cout << "\n Vetor[0]: " << &vetor[0];

    return 0;
}

/*
    << sobrecarga de operadores
*/