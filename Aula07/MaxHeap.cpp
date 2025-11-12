// Arquivo de implementação da classe MaxHeap

#include "MaxHeap.hpp"   // inclusão do arquivo de cabeçalho

// Método privado que retorna o índice do pai
// do elemento armazenado no índice index
int MaxHeap::parent(int index) const {
    return (index - 1) / 2;
}

// Método privado que retorna o índice do filho a esquerda
// do elemento armazenado no índice index
int MaxHeap::leftChild(int index) const {
    return 2 * index + 1;
}

// Método privado que retorna o índice do filho a direita
// do elemento armazenado no índice index
int MaxHeap::rightChild(int index) const {
    return 2 * index + 2;
}

// Método privado que ajusta a heap para manter suas
// propriedades - subida de nó na árvore em procedimentos
// de inserção ou atualização
void MaxHeap::heapifyUp(int index) {
    while (index > 0 && this->heap[index] > this->heap[parent(index)]) {
        this->swap(index, parent(index));
        index = parent(index);
    }
}

// Método privado que ajusta a heap para manter suas
// propriedades - descida de nó na árvore em procedimentos
// de retirada de máxima prioridade ou atualização
void MaxHeap::heapifyDown(int index) {
    int size = this->heap.size();
    int greater = index;

    while(true) {
        int left = this->leftChild(index);    // filho da esquerda
        int right = this->rightChild(index);  // filho da direita

        // verifica qual é o filho de maior prioridade
        if(left < size && this->heap[left] > this->heap[greater]) {
            greater = left;
        }

        if(right < size && this->heap[right] > this->heap[greater]) {
            greater = right;
        }

        if (greater == index) {
            break;
        }

        // se greater é maior que o valor armazenado em index,
        // efetua-se a troca de valores de prioridades
        this->swap(index,greater);
        index = greater;
    }    
}

// Método privado que efetua a troca de valores entre
// posições da heap (vetor)
void MaxHeap::swap(int index1, int index2) {
    int aux = this->heap[index1];
    this->heap[index1] = this->heap[index2];
    this->heap[index2] = aux;
}

// Construtor que instancia uma heap a partir de
// vetor (o vetor pode não ser uma heap)
MaxHeap::MaxHeap(const vector<int> &array) {
    for(int v : array) {
        // insere cada elemento do vetor na heap
        this->insert(v);
    }
}

// Construtor de cópia
MaxHeap::MaxHeap(const MaxHeap & heap) {
    *this = heap;       // sobrecarga do operador '='
}

// Método que verifica se a heap está vazia
bool MaxHeap::isEmpty() const {
    return this->heap.empty();
}

// Método que retorna o número de elementos
// (tamanho) da heap
int MaxHeap::size() const {
    return this->heap.size();
}

// Retorna o valor da raiz da árvore binária,
// ou seja, o elemento de maior prioridade
int MaxHeap::getMax() const {
    if(this->heap.empty()) {
        throw std::out_of_range(" Empty heap!");
    }

    // a raiz se encontra na primeira posição da heap
    return this->heap[0];
}

// Insere um elemento na heap
void MaxHeap::insert(int value) {
    this->heap.push_back(value);              // insere na última posição
    this->heapifyUp(this->heap.size() - 1);   // efetua ajuste se necessário
}

// Remove e retorna o elemento de maior prioridade da heap
int MaxHeap::extractMax() {
    if(this->isEmpty()) {
        throw std::out_of_range(" Empty heap!");
    }

    int max = this->heap[0];            // elemento de maior prioridade
    this->heap[0] = this->heap.back();  // valor do último elemento vai para a raiz 
    this->heap.pop_back();              // remove o último elemento da heap

    // se a heap não se tornou vaziaa
    if(!this->isEmpty()) {
        this->heapifyDown(0);       // efetua ajuste se necessário
    }

    return max;        
}

// Método que realiza a atualização da prioridade de um elemento
// que se encontra no índice index
void MaxHeap::update(int index, int value) {
    if (index < 0 || index >= this->heap.size()) {
        throw std::out_of_range(" Invalid index!");
    }

    int oldValue = this->heap[index];
    this->heap[index] = value;

    if(value > oldValue) {
        this->heapifyUp(index);
    } else {
        this->heapifyDown(index);
    }
}

// Método que retorna o índice em que um determinado
// valor de prioridade foi encontrado, ou -1 caso contrário
int MaxHeap::search(int value) const {
    int size = this->heap.size();

    for (int i = 0; i < size; i++) {
        if(this->heap[i] == value) {
            return i;
        }
    }

    return -1;
}

// Método que remove todos os elementos da heap
void MaxHeap::clear() {
    this->heap.clear();
}

// Método que exibe todos os elementos da heap
void MaxHeap::print() const {
    cout << " HEAP: ";
    for(int v : this->heap) {
        cout << v << " ";
    }

    if (this->isEmpty()) {
        cout << "(empty heap)";
    }
}

// Método de sobrecarga do operador '='. Efetua uma cópia
// de um objeto heap em outra heap
MaxHeap & MaxHeap::operator=(const MaxHeap & rightHeap) {
    this->heap.clear();     // limpa a heap que efetuou a chamada
                            // operando da esquerda

    // insere todos os elementos do objeto heap (operando da direita)
    // na heap que efetuou a chamada do método (operando da esquerda)
    for(int v : rightHeap.heap) {
        this->heap.push_back(v);
    }

    return *this;
}