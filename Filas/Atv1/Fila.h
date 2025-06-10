#include <iostream>
using namespace std;

class Fila {
private:
    struct Node {
        int valor;
        Node* proximo;
        Node(int v);
    };
    
    Node* front;
    Node* rear;
    int count;
public:
    Fila();
    ~Fila();
    
    void enqueue(int valor);
    int dequeue();
    int peek() const;
    bool empty() const;
    int size() const;
};