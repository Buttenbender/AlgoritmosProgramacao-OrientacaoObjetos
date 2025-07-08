#pragma once
#include <iostream>
using namespace std;

template <class T>
class Fila {
private:
    struct Node {
        T valor;
        Node* proximo;
        Node(T v);
    };

    Node* front;
    Node* rear;
    int count;
public:
    Fila();
    ~Fila();

    void enqueue(T valor);
    T dequeue();
    T peek();
    bool empty();
    int size();
};

template <class T>
Fila<T>::Node::Node(T v)
    : valor(v), proximo(nullptr) {
}

template <class T>
Fila<T>::Fila()
    : front(nullptr), rear(nullptr), count(0) {
}

template <class T>
Fila<T>::~Fila() {
    while (!empty()) {
        dequeue();
    }
}

template <class T>
void Fila<T>::enqueue(T valor) {
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

template <class T>
T Fila<T>::dequeue() {
    if (empty()) {
        throw runtime_error("Erro: Fila Vazia!");
    }

    Node* temp = front;
    T val = temp->valor;
    front = front->proximo;
    delete temp;
    count--;

    if (empty()) {
        rear = nullptr;
    }

    return val;
}

template <class T>
T Fila<T>::peek() {
    if (empty()) {
        throw runtime_error("Erro: Fila Vazia!");
    }
    return front->valor;
}

template <class T>
bool Fila<T>::empty() {
    return (front == nullptr);
}

template <class T>
int Fila<T>::size() {
    return count;
}
