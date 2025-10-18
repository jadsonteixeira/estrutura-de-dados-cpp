#include <iostream>
#include "Pilha.h"

using namespace std;

Pilha::Pilha() {
    tamanho = 0;
    estrutura = new TipoItem[MAX_ITENS];
}

Pilha::~Pilha() {
    delete [] estrutura;
}

bool Pilha::estaCheia() {
    return (tamanho == MAX_ITENS);
}

bool Pilha::estVazia() {
    return (tamanho == 0);
}

void Pilha::inserir(TipoItem item) {
    if (estaCheia()) {
        cout << "A pilha está cheia\n";
        cout << "Nao e possivel inserir este elemento\n";
    } else {
        estrutura[tamanho] = item;
        tamanho++;
    }
}

TipoItem Pilha::remover() {
    if (estVazia()) {
        cout << "A pilha esta vazia\n";
        cout << "Nao tem elemento para ser removido\n";
        return 0;
    } else {
        tamanho--;
        return estrutura[tamanho];
    }
}

void Pilha::imprimir() {
    cout << "\nPilha: ";
    for (int i = 0; i < tamanho; i++) {
        cout << estrutura[i] << " ";
    }
    cout << "\n";
}

int Pilha::qualTamanho() {
    return tamanho;
}