#include "Fila.h"

Fila::Node::Node(int v)
    : valor(v), proximo(nullptr) {}
    
Fila::Fila()
    : front(nullptr), rear(nullptr), count(0) {}
    
Fila::~Fila() {
    while (!empty()) {
        dequeue();
    }
}

void Fila::enqueue(int valor) {
    Node* novoNode = new Node(valor);
    if (empty()) {
        front = rear = novoNode;
    }
    else {
        rear->proximo = novoNode;
        rear = novoNode;
    }
    count++;
}

int Fila::dequeue() {
    if (empty()) {
        cerr << "Erro: Fila vazia!" << endl;
        return -1;
    }
    Node* temp = front;
    int valor = temp->valor;
    front = front->proximo;
    delete temp;
    count--;
    
    if (empty()) {
        rear = nullptr;
    }
    return valor;
}

int Fila::peek() const {
    if (empty()) {
        cerr << "Erro: Fila vazia!" << endl;
        return -1;
    }
    return front->valor;
}

bool Fila::empty() const {
    return (front == nullptr);
}

int Fila::size() const {
    return count;
}