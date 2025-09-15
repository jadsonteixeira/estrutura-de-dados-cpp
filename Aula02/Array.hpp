#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#define CAP_PADRAO 10

class Array {
    private:
        int * dados;
        int capacidade;
        int tamanho;

    public:
        Array(int capacidadeInicial = CAP_PADRAO); // construtor padrão
        Array(const Array & array); // construtor de cópia
        ~Array(); // destrutor

        int getTamanho();
        int getCapacidade();
        int get(int indice);

        void set(int indice, int valor);
        void inserir(int valor);
        bool removerUltimo();
        void remover(int indice);
        void limpar();
        int buscaLinear(int valor);

        int & operator[](int indice);
        //int operator[](int indice);
        Array & operator=(const Array & array);

};

#endif