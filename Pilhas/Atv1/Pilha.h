#include <iostream>
using namespace std;

class Pilha {
private:
    struct Node {
        int valor;
        Node* proximo;
        Node(int v, Node* p);
    };
    
    Node* topo;
    int tamanho;
public:
    Pilha();
    ~Pilha();
    
    void push(int valor);
    void pop();
    int size() const;
    bool empty() const;
};