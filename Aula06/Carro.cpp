#include "Carro.hpp"

Carro::Carro() {
    this->n_portas = 4;
}

Carro::Carro(int portas) {
    if (portas > 0) {
        this->n_portas = portas;
    } else {
        throw std::invalid_argument("Numero de portas invalido");
    }
}

int Carro::getNPortas() const {
    return this->n_portas;
}

// sobrecarga
void Carro::acelerar() {
    cout << "Acelerando o Carro....";
    this->velocidade += 5;
    this->combustivel -= 3;
}

// sobrecarga
void Carro::frear() {
    cout << "\nFreando o Carro...";

    this->velocidade -= 10;
    if (this->velocidade < 0) {
        this->velocidade = 0;
    }
}

void Carro::imprimir() const {
    cout << "\nImprimindo o Carro...";
    Veiculo::imprimir();
    cout << "\nPortas: " << this->n_portas;
}

Carro::~Carro() {
    cout << "\n... Destrutor de Carro ...";
}