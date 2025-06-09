#include <iostream>
using namespace std;

class Pilha {
private:
    struct Node {
        char valor;
        Node* proximo;
        Node(char v, Node* p);
    };
    
    Node* topo;
    int tamanho;
public:
    Pilha();
    ~Pilha();
    
    void push(char valor);
    void pop();
    char top() const;
    int size() const;
    bool empty() const;
};