// arquivo de implementação

#include "Array.hpp"

// construtor padrão
Array::Array(int capacidadeInicial = CAP_PADRAO) {
    if (capacidadeInicial <= 0) {
        cout << "ERRO: capacidade invalida";
        capacidadeInicial = CAP_PADRAO;

        this->capacidade = capacidadeInicial;
        this->tamanho = 0;
        this->dados = new int [this->capacidade]; // alocar memória
    }
}; 

// construtor de cópia
Array::Array(const Array & array) {
    this->capacidade = array.capacidade;
    this->dados = new int [this->capacidade];
    
    for (int i = 0; i < array.tamanho; i++) {
        this->dados[i] = array.dados[i];
    }

    this->tamanho = array.tamanho;
}; 

// destrutor
Array::~Array() {
    delete [] dados; // desalocar toda a memória alocada para dados
}; 

// método que não altera o objeto
int Array::getTamanho() const {
    return this->tamanho;
}; 

// método que não altera o objeto
int Array::getCapacidade() const {
    return this->capacidade;
}; 

// método que não altera o objeto
int Array::get(int indice) const {
    if (indice >= 0 && indice < tamanho) {
        return this->dados[indice];
    }

    throw out_of_range("Indice invalido!");
}; 

void Array::set(int indice, int valor) {
    if (indice >= 0 && indice < this->tamanho) {
        this->dados[indice] = valor;
        return;
    }

    throw out_of_range("Indice invalido!");
};

void Array::inserir(int valor) {

};

bool Array::removerUltimo() {
    if (this->temElementos()) {
        this->tamanho--;
        return true;
    }

    return false;
};

void Array::remover(int indice) {
    if (indice >= 0 && indice < tamanho) {
        for (int i = indice; i < (this->tamanho - 1); i++) {
            this->dados[i] = this->dados[i+1];
        }

        this->tamanho--;
    }

    throw out_of_range("Indice invalido");
};

void Array::limpar() {
    this->tamanho = 0;
};

// método que não altera o objeto
int Array::buscaLinear(int valor) const {
    for (int i = 0; i < this->tamanho; i++) {
        if (this->dados[i] == valor) {
            return i;
        }
    }

    return -1;
}; 

// sobrecarga de operadores
int & Array::operator[](int indice) {

};

int Array::operator[](int indice) const {

};

// a1 = a2
Array & Array::operator=(const Array & array) {

}; 

void Array::redimensionar(int novaCapacidade) {
    int * temp = new int [novaCapacidade];

    for (int i = 0; i < this->tamanho; i++) {
        temp[i] = this->dados[i]; //copiei os dados do meu vetor para um novo vetor maior
    }

    delete [] dados;
    dados = temp;

    this->capacidade = novaCapacidade;
};

bool Array::temElementos() const {
    return this->tamanho != 0;
};