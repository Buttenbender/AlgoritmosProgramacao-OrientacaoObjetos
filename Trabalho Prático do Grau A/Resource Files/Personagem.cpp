#include "Personagem.h"

Personagem::Personagem(string n)
    : nome(n) {
        adicionarItem(Item("Lanterna", "comum",1, 0, 0, 0));
    }

string Personagem::getNome() {
    return nome;
}

void Personagem::setNome(string n) {
    nome = n;
}

int Personagem::getHabilidade() {
    return habilidade;
}

void Personagem::setHabilidade(int h) {
    habilidade = h;
}

int Personagem::getEnergia() {
    return energia;
}

void Personagem::setEnergia(int e) {
    energia = e;
}

int Personagem::getSorte() {
    return sorte;
}

void Personagem::setSorte(int s) {
    sorte = s;
}

int Personagem::getProvisoes() {
    return provisoes;
}

void Personagem::setProvisoes(int p) {
    provisoes = p;
}

int Personagem::getTesouro() {
    return tesouro;
}

void Personagem::setTesouro(int t) {
    tesouro = t;
}

void Personagem::adicionarItem(const Item& item) {
    inventario.push_back(item);
}

void Personagem::excluirItem(const Item& item) {
    for (auto it = inventario.begin(); it != inventario.end(); it++) {
        if (*it == item) {
            inventario.erase(it);
            break;
        }
    }
}

void Personagem::exibirInventario() {
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
    cout << "- Provisões: " << provisoes << "; -- Cura 3 de Energia cada --" << endl;
    cout << "- Tesouro: " << tesouro << " moedas de ouro" << endl;
}

void Personagem::adicionarMagia(const Magia& magia) {
    magias.push_back(magia);
}

void Personagem::excluirMagia(const Magia& magia) {
    for (auto it = magias.begin(); it != magias.end(); it++) {
        if (*it == magia) {
            magias.erase(it);
            break;
        }
    }
}

void Personagem::exibirMagias() {
    cout << "--- Magias ---" << endl;
    for (auto& magia : magias) {
        cout << "- " << magia.getNome() << "; Tipo: " << magia.getTipo() << "; Valor: " << magia.getValor() << endl;
    }
    cout << "------------------------------\n" << endl;
}

void Personagem::exibirDados() {
    cout << "Nome: " << nome << endl;
    cout << "Habilidade: " << habilidade << endl;
    cout << "Energia: " << energia << endl;
    cout << "Sorte: " << sorte << endl;
    exibirInventario();
}

vector<Item>& Personagem::getInventario() {
    return inventario;
}

vector<Magia>& Personagem::getMagias() {
    return magias;
}

void Personagem::editarInventario() {
    if (inventario.empty()) {
        cout << "Inventário está vazio!" << endl;
        return;
    }

    cout << "\n--- Inventário ---" << endl;
    for (size_t i = 0; i < inventario.size(); i++) {
        cout << i + 1 << " - " << inventario[i].getNome()
             << "; Tipo: " << inventario[i].getTipo()
             << (inventario[i].getEquipado() == 1 ? "; Equipado" : "; Não Equipado") << ";" << endl;
    }

    int escolha;
    cout << "\nDigite o número do item para equipar/desequipar (0 para cancelar): ";
    cin >> escolha;

    if (escolha <= 0 || escolha > static_cast<int>(inventario.size())) {
        cout << "Operação cancelada ou item inválido!" << endl;
        return;
    }

    Item& itemEscolhido = inventario[escolha - 1];

    if (itemEscolhido.getEquipado() == 1) {
        itemEscolhido.setEquipado(0);
        cout << itemEscolhido.getNome() << " foi desequipado!" << endl;
    }
    else {
        string tipo = itemEscolhido.getTipo();
        if (tipo == "arma" || tipo == "armadura") {
            for (auto& item : inventario) {
                if (item.getTipo() == tipo) {
                    item.setEquipado(0);
                }
            }
        }

        itemEscolhido.setEquipado(1);
        cout << itemEscolhido.getNome() << " foi equipado!" << endl;
    }
}

int Personagem::getLugarHistoria() {
    return lugarHistoria;
}

void Personagem::setLugarHistoria(int l) {
    lugarHistoria = l;
}

void Personagem::limparInventario() {
    inventario.clear();
}

void Personagem::limparMagias() {
    magias.clear();
}
