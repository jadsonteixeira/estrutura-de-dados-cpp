#include "Veiculo.hpp"

Veiculo::Veiculo() {
    this->velocidade = 0;
    this->combustivel = 100;
}

double Veiculo::getVelocidade() const {
    return this->velocidade;
}

double Veiculo::getCombustivel() const {
    return this->combustivel;
}

void Veiculo::abastecer() { 
    this->combustivel = 100;
}

void Veiculo::imprimir() const {
    cout << "\nVelocidade: " << this->velocidade;
    cout << "\nTanque: " << this->combustivel << "%";
}

Veiculo::~Veiculo() {
    cout << "\n.... Destrutor de Veiculo ....";
}