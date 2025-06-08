#include "Monstro.h"

Monstro::Monstro(string n,int c, int h, int e, int s, int t)
    : nome(n),chefe(c), habilidade(h), energia(e), sorte(s), tesouro(t) {}

string Monstro::getNome() {
    return nome;
}

int Monstro::getChefe() {
    return chefe;
}

int Monstro::getHabilidade() {
    return habilidade;
}

void Monstro::setHabilidade(int h) {
    habilidade = h;
}

int Monstro::getEnergia() {
    return energia;
}

void Monstro::setEnergia(int e) {
    energia = e;
}

int Monstro::getSorte() {
    return sorte;
}

void Monstro::setSorte(int s) {
    sorte = s;
}

int Monstro::getTesouro() {
    return tesouro;
}

void Monstro::setTesouro(int t) {
    tesouro = t;
}

void Monstro::adicionarItem(const Item& item) {
    inventario.push_back(item);
}

void Monstro::excluirItem(const Item& item) {
    for (auto it = inventario.begin(); it != inventario.end(); it++) {
        if (*it == item) {
            inventario.erase(it);
            break;
        }
    }
}

void Monstro::exibirInventario() {
    cout << "--- Inventário ---" << endl;
    for (auto& item : inventario) {
        if (item.getEquipado() == 1) {
            cout << "Equipado: ";
        }
        cout << "- " << item.getNome() << "; Tipo: " << item.getTipo();

        if (item.getCombate() == 1) {
            cout << "; Pode ser usado em combate";
            cout << "; FA: " << item.getFA() << "; Dano: " << item.getDano();
        } else {
            cout << "; Não pode ser usado em combate";
        }

        cout << ";" << endl;
    }
}

void Monstro::exibirDados() {
    if (chefe == 1) {
        cout << "--- Chefe ---" << endl;
    }
    else {
        cout << "--- Monstro ---" << endl;
    }
    cout << "Nome: " << nome << endl;
    cout << "Habilidade: " << habilidade << endl;
    cout << "Energia: " << energia << endl;
    cout << "Sorte: " << sorte << endl;
    cout << "Tesouro: " << tesouro << " moedas de ouro" << endl;
    exibirInventario();
}

vector<Item>& Monstro::getInventario() {
    return inventario;
}
