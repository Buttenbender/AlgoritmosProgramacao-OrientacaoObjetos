#pragma once
#include <iostream>
#include <string>
using namespace std;

class Magia {
private:
    string nome;
    string tipo;
    int valor;
public:
    Magia(string n, string t, int v);
    string getNome() const;
    string getTipo() const;
    int getValor() const;
    bool operator==(const Magia& outro) const;
};
