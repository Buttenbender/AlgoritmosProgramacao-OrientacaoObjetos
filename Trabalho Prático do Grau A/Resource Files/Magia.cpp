#include "Magia.h"

Magia::Magia(string n, string t, int v)
    : nome(n), tipo(t), valor(v) {}

string Magia::getNome() const {
    return nome;
}

string Magia::getTipo() const {
    return tipo;
}

int Magia::getValor() const {
    return valor;
}

bool Magia::operator==(const Magia&outro) const {
    return nome == outro.nome &&
    tipo == outro.tipo &&
    valor == outro.valor;
}
