#include "Pilha.h"
#include <iostream>
#include <string>
using namespace std;

string inverterPalavra(const string& palavra) {
    Pilha pilha;
    string palavraInvertida;
    
    for (char c : palavra) {
        pilha.push(c);
    }
    
    while(!pilha.empty()) {
        palavraInvertida += pilha.top();
        pilha.pop();
    }
    
    return palavraInvertida;
}

bool verificaPalindromo(const string& palavra) {
    string invertida = inverterPalavra(palavra);
    
    return (palavra == invertida);
}

int main() {
    Pilha p;
    p.push('J');
    p.push('O');
    p.push('A');
    p.push('O');
    
    while (!p.empty()) {
        cout << p.top() << endl;
        p.pop();
    }
    
    string palavraOriginal = "JOAO";
    string palavraInvertida = inverterPalavra(palavraOriginal);
    
    cout << "Palavra Original: " << palavraOriginal << endl;
    cout << "Palavra Invertida: " << palavraInvertida << endl;
    
    string palavraVerificarPalindromo = "RADAR";
    if (verificaPalindromo(palavraVerificarPalindromo)) {
        cout << "A palavra " << palavraVerificarPalindromo << " é palíndromo!" << endl;
    }
    else {
        cout << "A palavra " << palavraVerificarPalindromo << " não é palíndromo!" << endl;
    }
}