// Arquivo de implementação da Classe
#include "Array.hpp"

// construtor padrão
Array::Array(int capacidadeInicial) {
    if(capacidadeInicial <= 0)  {
        cout << " ERRO: capacidade invalida!";
        capacidadeInicial = CAP_PADRAO;
    }

    this->capacidade = capacidadeInicial;
    this->tamanho = 0;
    this->dados = new int [this->capacidade]; // alocar memória
}

// construtor de cópia
Array::Array(const Array & array) {
    this->capacidade = array.capacidade;
    this->dados = new int [this->capacidade];

    for(int i = 0; i < array.tamanho; i++) {
        this->dados[i] = array.dados[i];
    }

    this->tamanho = array.tamanho;
}

// destrutor
Array::~Array() {
    // liberando memoria (desalocando)
    delete [] dados;
}

// método que não altera o objeto
int Array::getTamanho() const {
    return this->tamanho;
}

// método que não altera o objeto
int Array::getCapacidade() const {
    return this->capacidade;
}

// método que não altera o objeto
int Array::get(int indice) const {
    if(indice >= 0 && indice < tamanho) {
        return this->dados[indice];
    }

    throw out_of_range(" Indice invalido!");
}

void Array::set(int indice, int valor) {
    if(indice >= 0 && indice < this->tamanho) {
        this->dados[indice] = valor;
        return;
    }

    throw out_of_range(" Indice invalido!");
}

void Array::inserir(int valor) {
    if (this->tamanho == this->capacidade) {
        this->capacidade *= 2;
        this->redimensionar(this->capacidade);
    }

    this->dados[this->tamanho] = valor;
    this->tamanho++;
}

bool Array::removerUltimo() {
    if (this->temElementos()) {
        this->tamanho--;
        return true;
    }

    return false;
}

void Array::remover(int indice) {
    if (indice >= 0 && indice < tamanho) {
        for(int i = indice; i < (this->tamanho - 1); i++) {
            this->dados[i] = this->dados[i+1];
        }

        this->tamanho--;
    }

    throw out_of_range(" Indice invalido!");
}

void Array::limpar() {
    this->tamanho = 0;
}

// método que não altera o objeto
int Array::buscaLinear(int valor) const {
    for(int i = 0; i < this->tamanho; i++) {
        if(this->dados[i] == valor) {
            return i;
        }
    }

    return -1;
}

void Array::imprimir() const {
    cout << "\nARRAY: ";
    for(int i = 0; i < this->tamanho; i++) {
        cout << this->dados[i] << " ";
    }
    cout << "\n";
}

// sobrecarga de operadores
// a1[2] = 10   ->   a1.operator[](2) = 10
int & Array::operator[](int indice) {
    if(indice >= 0 && indice < tamanho) {
        return this->dados[indice];
    }

    throw out_of_range("Indice invalido!");
}

// int num = a1[0]   ->  int num = a1.operator[](0)
int Array::operator[](int indice) const {
    if(indice >= 0 && indice < tamanho) {
        return this->dados[indice];
    }

    throw out_of_range(" Indice invalido!");
}

// a1 = a2    ->     a1.operator=(a2)
const Array & Array::operator=(const Array & array) {
    this->capacidade = array.capacidade;
    this->tamanho = array.tamanho;

    delete [] this->dados;
    
    this->dados = new int [this->capacidade];    
    for(int i = 0; i < array.tamanho; i++) {
        this->dados[i] = array.dados[i];
    }

    return *this;
}

void Array::redimensionar(int novaCapacidade) {
    int * temp = new int [novaCapacidade];

    for(int i = 0; i < this->tamanho; i++) {
        temp[i] = this->dados[i]; // copiei os dados do meu vetor para um novo vetor maior
    }

    delete [] dados;
    dados = temp;

    this->capacidade = novaCapacidade;
}

bool Array::temElementos() const {
    return this->tamanho != 0;
}

// funcionalidades adicionais
void Array::inserirNoInicio(int valor) {
    if (this->tamanho == this->capacidade) {
        this->capacidade *= 2;
        this->redimensionar(this->capacidade);
    }

    // deslocamento dos valores para a direita
    for (int i = this->tamanho - 1; i >= 0; i--) {
        this->dados[i + 1] = this->dados[i];
    }

    this->dados[0] = valor;
    this->tamanho++;    
}

bool Array::removerPrimeiro() {
    if (this->temElementos()) {
        for (int i = 0; i <= this->tamanho - 1; i++) {
            this->dados[i] = this->dados[i + 1];
        }
        this->tamanho--;
        return true;
    }

    return false;
}

void Array::inserir(int indice, int valor) {
    if (indice < 0 || indice > this->tamanho) {
        throw out_of_range("Indice invalido");
    }

    if (this->tamanho == this->capacidade) {
        this->capacidade *= 2;
        this->redimensionar(this->capacidade);
    }

    for (int i = this->tamanho - 1; i >= indice; i--) {
        this->dados[i + 1] = this->dados[i];
    }

    this->dados[indice] = valor;
    this->tamanho++;
}

// OBS: perguntar porque o método temElementos() não retorna um bool