// arquivo de cabeçalho (definiçã ou interface)

#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <iostream>

using namespace std;

#define CAP_PADRAO 10

class Array {
    private:
        int * dados;
        int capacidade;
        int tamanho;

        void redimensionar(int novaCapacidade); // método auxiliar

    public:
        Array(int capacidadeInicial = CAP_PADRAO); // construtor padrão
        Array(const Array & array); // construtor de cópia
        ~Array(); // destrutor

        int getTamanho() const; // método que não altera o objeto
        int getCapacidade() const; // método que não altera o objeto
        int get(int indice) const; // método que não altera o objeto

        void set(int indice, int valor);
        void inserir(int valor);
        bool removerUltimo();
        void remover(int indice);
        void limpar();
        int buscaLinear(int valor) const; // método que não altera o objeto

        bool temElementos() const;

        // sobrecarga de operadores
        int & operator[](int indice);
        int operator[](int indice) const;
        Array & operator=(const Array & array); // a1 = a2 

};

#endif