#ifndef _VEICULO_HPP_
#define _VEICULO_HPP_

#include <iostream>
using std::cout;

// Classe ABSTRATA Veiculo (Classe Basica)
class Veiculo {
    protected:
        double velocidade;
        double combustivel;

    public:
        Veiculo();

        double getVelocidade() const;
        double getCombustivel() const;
        void abastecer();

        virtual void acelerar() = 0;    // método virtual puro
        virtual void frear() = 0;       // método virtual puro

        virtual void imprimir() const;  // método virtual

        virtual ~Veiculo();
};

#endif