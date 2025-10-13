#ifndef _MOTO_HPP_
#define _MOTO_HPP_

#include "Veiculo.hpp"

// classe derivada de Veiculo
class Moto : public Veiculo {
    private: 
        int cilindradas;

    public:
        Moto();
        Moto(int cilindradas);

        int getNCilindradas() const;
        
        void acelerar();
        void frear();

        void imprimir() const;

        ~Moto();
};

#endif