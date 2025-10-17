#include "Moto.hpp"

Moto::Moto() {
    this->cilindradas = 50;
}

Moto::Moto(int cilindradas) {
    if(cilindradas >= 50) {
        this->cilindradas = cilindradas;
    } else {
        throw std::invalid_argument("Valor invalido de cilindradas!");
    }
}

int Moto::getNCilindradas() const {
    return this->cilindradas;
}

void Moto::acelerar() {
    cout << "\n Acelerando a Moto....";
    this->velocidade += 10;
    this->combustivel -= 1;   
}

void Moto::frear() {
    cout << "\n Freando a Moto....";
    
    this->velocidade -= 15;
    if(this->velocidade < 0) {
        this->velocidade = 0;
    }
}

void Moto::imprimir() const {
    cout << "\n\n Imprimindo a Moto...";
    Veiculo::imprimir();
    cout << "\n Cilindradas: " << this->cilindradas;
}

Moto::~Moto() {
    cout << "\n... Destrutor da Moto ...";
}