#include <iostream>
#include <cstdlib>

using namespace std;

class Array {
    private:
        int* dados; // ponteiro para armazenar os elementos
        int tamanho;

    public:
        // construtor: cria um array com tamanho desejado
        Array(int t) {
            tamanho = t;
            dados = new int[tamanho]; // aloca memória
            for (int i = 0; i < tamanho; i++) {
                dados[i] = 0; // inicializa tudo com 0
            }
        }

        // destrutor: libera a memória
        ~Array() {
            delete[] dados;
        }

        // sobrecarga do operador []
        int& operator[](int indice) {
            return dados[indice];
            // retorna uma referência para o elemento
            // assim podemos LER e ESCREVER: arr[0] = 10; cout << arr[0];
        } 

        // sobrecarga do operador =
        Array& operator=(const Array& outro) {
            if (this != &outro) { // evita auto-atribuição (ex: ar = arr)
                delete[] dados; // limpa memória antiga
                tamanho = outro.tamanho;
                dados = new int[tamanho];
                for (int i = 0; i < tamanho; i++) {
                    dados[i] = outro.dados[i]; // copia elemento por elemento
                }
            }
            return *this; // retorna o próprio objeto (permite encadeamento)
        }

        void mostrar() {
            for (int i = 0; i < tamanho; i++) {
                cout << dados[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    system("cls");

    Array a(5); // cria um array de 5 posições
    a[0] = 10; // usando operator[] para escrever 
    a[1] = 20; // escrevendo no índice 1
    cout << a[0] << endl; // usando operator[] para ler

    Array b(5);
    b = a; // usando o operator= para copiar os valores de a para b

    cout << "Array a: ";
    a.mostrar();
    cout << "Array b (copia de a): ";
    b.mostrar();  

    return 0;
}