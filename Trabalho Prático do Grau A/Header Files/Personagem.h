#pragma once
#include "Item.h"
#include "Magia.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Personagem {
private:
    string nome;
    int habilidade = 6;
    int energia = 12;
    int sorte = 6;
    int provisoes = 3;
    int tesouro = 0;
    vector<Item> inventario;
    vector<Magia> magias;
    int lugarHistoria = 1;
public:
    Personagem(string n);
    virtual ~Personagem() = default;

    string getNome();
    void setNome(string n);

    int getHabilidade();
    void setHabilidade(int h);

    int getEnergia();
    void setEnergia(int e);

    int getSorte();
    void setSorte(int s);

    int getProvisoes();
    void setProvisoes(int p);

    int getTesouro();
    void setTesouro(int t);

    virtual void exibirDados();

    void adicionarItem(const Item& item);
    void excluirItem(const Item& item);
    void exibirInventario();

    void adicionarMagia(const Magia& magia);
    void excluirMagia(const Magia& magia);
    void exibirMagias();

    vector<Item>& getInventario();
    vector<Magia>& getMagias();

    void editarInventario();

    virtual string getClasse() const = 0;

    int getLugarHistoria();
    void setLugarHistoria(int l);

    void limparInventario();
    void limparMagias();
};
