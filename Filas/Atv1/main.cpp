#include "Fila.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    Fila f;
    int n;
    int countChegadas = 0;
    int countSaidas = 0;
    
    cout << "Por quantas iterações o programa deve rodar? ";
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        int chegadas = rand() % 4 + 2;
        int saidas = rand() % 2 + 1;
        
        for (int j = 0; j < chegadas; j++) {
            f.enqueue(1);
            countChegadas++;
        }
        
        for (int j = 0; j < saidas; j++) {
            if (!f.empty()) {
                f.dequeue();
                countSaidas++;
            }
            else {
                break;
            }
        }
        
        cout << "Iteração " << (i + 1) << endl;
        cout << "Chegadas: " << chegadas << endl;
        cout << "Saídas: " << saidas << "\n" << endl;
    }
    
    float mediaChegadas = countChegadas / n;
    float mediaSaidas = countSaidas / n;
    
    cout << "Resultados Finais" << endl;
    if (!f.empty()) {
        cout << "Número de pessoas que ainda restam na fila: " << f.size() << endl;
    }
    else {
        cout << "Não há pessoas na fila!" << endl;
    }
    
    cout << "Total de chegadas: " << countChegadas << endl;
    cout << "Média de chegadas por iteração: " << mediaChegadas << endl;
    
    cout << "Total de saídas: " << countSaidas << endl;
    cout << "Média de saídas por iteração: " << mediaSaidas << endl;
}