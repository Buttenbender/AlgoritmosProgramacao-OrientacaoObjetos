#include "Guerreiro.h"

Guerreiro::Guerreiro(string n)
    : Personagem(n) {
        adicionarItem(Item("Espada Longa", "arma",1, 1, 2, 2));
    }

void Guerreiro::exibirDados() {
    cout << "--- Exibição de Personagem ---" << endl;
    cout << "Classe: Guerreiro" << endl;
    Personagem::exibirDados();
    cout << "------------------------------\n" << endl;
}

string Guerreiro::getClasse() const {
    return "Guerreiro";
}
