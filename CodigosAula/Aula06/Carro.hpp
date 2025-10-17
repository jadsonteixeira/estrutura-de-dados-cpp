#ifndef _CARRO_HPP_
#define _CARRO_HPP_

#include "Veiculo.hpp"

// Classe derivada de Veiculo
class Carro : public Veiculo {
    private:
        int n_portas;

    public:
        Carro();
        Carro(int portas);

        int getNPortas() const;
        
        void acelerar();
        void frear();

        void imprimir() const;

        ~Carro();
};

#endif