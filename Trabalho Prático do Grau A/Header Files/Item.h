#pragma once
#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string nome;
    string tipo;
    int equipado;
    int combate;
    int fa;
    int dano;
public:
    Item(string n, string t,int e, int c, int f, int d);
    string getNome() const;
    string getTipo() const;
    int getEquipado() const;
    void setEquipado(int e);
    int getCombate() const;
    int getFA() const;
    int getDano() const;
    bool operator==(const Item& outro) const;
};
