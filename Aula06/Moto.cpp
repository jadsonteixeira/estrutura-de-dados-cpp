#include "Moto.hpp"

Moto::Moto() {
    this->cilindradas = 50;
}

Moto::Moto(int cilindradas) {
    if (cilindradas >= 50) {
        this->cilindradas = cilindradas;
    } else {
        throw std::invalid_argument("Cilindradas invalida");
    }
}

int Moto::getNCilindradas() const {
    return this->cilindradas;
}

void Moto::acelerar() {
    cout << "Acelerando o Moto....";
    this->velocidade += 10;
    this->combustivel -= 1;
}
void Moto::frear() {
    cout << "\nFreando o Carro...";

    this->velocidade -= 15;
    if (this->velocidade < 0) {
        this->velocidade = 0;
    }
}

void Moto::imprimir() const {
    cout << "\nImprimindo o Moto...";
    Veiculo::imprimir();
    cout << "\nCilindradas: " << this->cilindradas;
}

Moto::~Moto() {
    cout << "\n...Destrutor da Moto...";
}