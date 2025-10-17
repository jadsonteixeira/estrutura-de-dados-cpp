#include "Carro.hpp"

Carro::Carro() {
    this->n_portas = 4;
}

Carro::Carro(int portas) {
    if(portas >= 0) {
        this->n_portas = portas;
    } else {
        throw std::invalid_argument("Numero de portas invalido!");
    }
}

int Carro::getNPortas() const {
    return this->n_portas;
}

// Sobrecarga do método abstrato
void Carro::acelerar() {
    cout << "\n Acelerando o Carro....";
    this->velocidade += 5;
    this->combustivel -= 3;    
}

// Sobrecarga do método abstrato
void Carro::frear() {
    cout << "\n Freando o Carro....";
    
    this->velocidade -= 10;
    if(this->velocidade < 0) {
        this->velocidade = 0;
    }
}

void Carro::imprimir() const {
    cout << "\n\n Imprimindo o Carro...";
    Veiculo::imprimir();
    cout << "\n Portas: " << this->n_portas;
}

Carro::~Carro() {
    cout << "\n... Destrutor de Carro ...";
}