#include "Pilha.h"

Pilha::Node::Node(int v, Node* p)
    : valor(v), proximo(p) {}
    
Pilha::Pilha()
    : topo(nullptr), tamanho(0) {}

Pilha::~Pilha() {
    while (!empty()) {
        pop();
    }
}

void Pilha::push(int valor) {
    topo = new Node(valor, topo);
    tamanho++;
}

void Pilha::pop() {
    if (empty()) {
        cerr << "Erro: Pilha Vazia!" << endl;
        return;
    }
    Node* temp = topo;
    topo = topo->proximo;
    delete temp;
    tamanho--;
}

int Pilha::size() const {
    return tamanho;
}

bool Pilha::empty() const {
    return (topo == nullptr);
}