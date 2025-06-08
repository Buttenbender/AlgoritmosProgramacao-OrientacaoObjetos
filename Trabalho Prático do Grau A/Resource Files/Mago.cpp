#include "Mago.h"

Mago::Mago(string n)
    : Personagem(n) {
        adicionarItem(Item("Cajado", "arma", 1, 1, 2, 0));
        adicionarMagia(Magia("Bola de Fogo", "dano", 2));
    }

void Mago::exibirDados() {
    cout << "--- Exibição de Personagem ---" << endl;
    cout << "Classe: Mago" << endl;
    Personagem::exibirDados();
    Personagem::exibirMagias();
}

string Mago::getClasse() const {
    return "Mago";
}
