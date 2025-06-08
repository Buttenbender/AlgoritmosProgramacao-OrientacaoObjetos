#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Monstro {
private:
    string nome;
    int chefe;
    int habilidade;
    int energia;
    int sorte;
    int tesouro;
    vector<Item> inventario;
public:
    Monstro(string n,int c, int h, int e, int s, int t);
    string getNome();
    int getChefe();

    int getHabilidade();
    void setHabilidade(int h);

    int getEnergia();
    void setEnergia(int e);

    int getSorte();
    void setSorte(int s);

    int getTesouro();
    void setTesouro(int t);

    void adicionarItem(const Item& item);
    void excluirItem(const Item& item);
    void exibirInventario();

    void exibirDados();

    vector<Item>& getInventario();
};
