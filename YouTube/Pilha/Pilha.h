typedef int TipoItem;
const int MAX_ITENS = 100;

class Pilha {
    private:
        int tamanho;
        TipoItem* estrutura;

    public:
        Pilha();
        ~Pilha();
        bool estaCheia();
        bool estVazia();
        void inserir(TipoItem item);
        TipoItem remover();
        void imprimir();
        int qualTamanho();

};