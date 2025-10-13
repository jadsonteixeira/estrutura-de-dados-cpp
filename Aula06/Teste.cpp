#include "Moto.hpp"
#include "Carro.hpp"

void imprimirVeiculo(const Veiculo & veiculo) {
    veiculo.imprimir();
}

int main() {
    Carro carro = Carro();
    Moto moto = Moto(500);

    carro.imprimir();
    moto.imprimir();

    Veiculo * veiculo = &carro;
    veiculo->imprimir();

    veiculo = &moto;
    veiculo->imprimir();

    imprimirVeiculo(carro);
}