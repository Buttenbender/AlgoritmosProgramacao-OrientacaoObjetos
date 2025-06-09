#include "Pilha.h"
#include <string>
using namespace std;

bool verificaBalanceamento(const string& expressao) {
    Pilha pilha;
    for (char c : expressao) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                pilha.push(c);
                break;
            case ')':
                if (pilha.empty()) {
                    cout << "Erro: ')' não tem um caractere de abertura correspondente." << endl;
                    return false;
                }
                if (pilha.top() != '(') {
                    cout << "Erro: ')' esperava um '(', mas encontrou '" << pilha.top() << "'." << endl;
                    return false;
                }
                pilha.pop();
                break;
            case '}':
                if (pilha.empty()) {
                    cout << "Erro: '}' não tem um caractere de abertura correspondente." << endl;
                    return false;
                }
                if (pilha.top() != '{') {
                    cout << "Erro: '}' esperava um '{', mas encontrou '" << pilha.top() << "'." << endl;
                    return false;
                }
                pilha.pop();
                break;
            case ']':
                if (pilha.empty()) {
                    cout << "Erro: ']' não tem um caractere de abertura correspondente." << endl;
                    return false;
                }
                if (pilha.top() != '[') {
                    cout << "Erro: ']' esperava um '[', mas encontrou '" << pilha.top() << "'." << endl;
                    return false;
                }
                pilha.pop();
                break;
        }
    }
    
    if (!pilha.empty()) {
        cout << "Erro: Caractere de abertura '" << pilha.top() << "' não foi fechado." << endl;
        return false;
    }
    return true;
}

int main() {
    char continuar;
    do {
        cout << "Digite uma expressão: ";
        string expressao;
        getline(cin, expressao);
        
        if (verificaBalanceamento(expressao)) {
            cout << "A expressão está balanceada." << endl;
        }
        
        cout << "Deseja continuar? (s / n): ";
        cin >> continuar;
        cin.ignore();
    } while (continuar == 's' || continuar == 'S');
    
    return 0;
}