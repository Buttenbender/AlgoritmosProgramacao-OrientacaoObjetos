#include "Item.h"

Item::Item(string n, string t,int e, int c, int f, int d)
    : nome(n), tipo(t),equipado(e), combate(c), fa(f), dano(d) {}

string Item::getNome() const {
    return nome;
}

string Item::getTipo() const {
    return tipo;
}

int Item::getEquipado() const {
    return equipado;
}

void Item::setEquipado(int e) {
    equipado = e;
}

int Item::getCombate() const {
    return combate;
}

int Item::getFA() const {
    return fa;
}

int Item::getDano() const {
    return dano;
}

bool Item::operator==(const Item& outro) const {
    return nome == outro.nome &&
           tipo == outro.tipo &&
           equipado == outro.equipado &&
           combate == outro.combate &&
           fa == outro.fa &&
           dano == outro.dano;
}
