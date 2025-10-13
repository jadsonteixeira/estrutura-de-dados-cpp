#ifndef _VEICULO_HPP_
#define _VEICULO_HPP_

#include <iostream>

using std::cout;

// classe abstrata
class Veiculo {
    protected:    
        double velocidade;
        double combustivel;

    public:
        Veiculo();
        virtual ~Veiculo();

        double getVelocidade() const;
        double getCombustivel() const;
        void abastecer();

        // método virtual puro
        virtual void acelerar() = 0;
        virtual void frear() = 0;

        virtual void imprimir() const;
};

#endif