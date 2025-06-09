#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pilha.h"
using namespace std;

int main() {
    srand(time(0));
    Pilha p;
    
    int turnos;
    cout << "Digite por quantos turnos você quer que o programa funcione: ";
    cin >> turnos;
    cin.ignore();
    
    for (int i = 0; i < turnos; i++) {
        int lavados = rand() % 5 + 1;
        int secos = rand() % 3 + 1;
        
        for (int j = 0; j < lavados; j++) {
            p.push(1);
        }
        
        for (int j = 0; j < secos; j++) {
            if (!p.empty()) {
                p.pop();
            }
            else {
                break;
            }
        }
        
        cout << "Turno " << (i + 1) << endl;
        cout << "Pratos Lavados: " << lavados << endl;
        cout << "Pratos Secos: " << secos << endl;
        cout << "Pratos na pia: " << p.size() << "\n" << endl;
    }
    
    if (!p.empty()) {
        cout << "Quantidades de pratos que ainda não foram secos: " << p.size() << endl;
    }
    else {
        cout << "Todos os pratos foram secos!" << endl;
    }
    
    return 0;
}