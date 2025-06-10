#include "Fila.h"
#include <cctype>

int main() {
    Fila<string> estacionamento;
    char opcao;
    string placa;
    
    cout << "Sistema de Estacionamento de Manoel" << endl;
    cout << "Comandos:" << endl;
    cout << "A [placa] - Adicionar carro" << endl;
    cout << "R [placa] - Remover carro" << endl;
    cout << "S - Mostrar estado" << endl;
    cout << "Q - Sair" << endl;
    
    do {
        cout << "\n> ";
        cin >> opcao;
        opcao = toupper(opcao);
        
        switch(opcao) {
            case 'A':
                cin >> placa;
                estacionamento.enqueue(placa);
                cout << "Carro " << placa << " estacionado." << endl;
                break;
                
            case 'R': {
                cin >> placa;
                if (!estacionamento.contains(placa)) {
                    cout << "Carro " << placa << " não encontrado!" << endl;
                    break;
                }
                
                Fila<string> tempFila;
                bool encontrado = false;
                int carrosMovidos = 0;
                
                while (!estacionamento.empty()) {
                    string carroAtual = estacionamento.dequeue();
                    if (carroAtual == placa && !encontrado) {
                        encontrado = true;
                        cout << "Carro " << placa << " saiu. Carros movidos: " << carrosMovidos << endl;
                    } else {
                        tempFila.enqueue(carroAtual);
                        carrosMovidos++;
                    }
                }
                
                while (!tempFila.empty()) {
                    estacionamento.enqueue(tempFila.dequeue());
                }
                
                if (!encontrado) {
                    cout << "Erro: Carro " << placa << " não encontrado após busca!" << endl;
                }
                break;
            }
                
            case 'S':
                estacionamento.display();
                break;
                
            case 'Q':
                cout << "Encerrando sistema..." << endl;
                break;
                
            default:
                cout << "Opção inválida!" << endl;
        }
        
    } while (opcao != 'Q');
    
    return 0;
}