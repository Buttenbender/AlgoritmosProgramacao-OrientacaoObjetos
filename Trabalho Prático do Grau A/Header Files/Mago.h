#pragma once
#include "Personagem.h"
#include <vector>
using namespace std;

class Mago: public Personagem {
public:
    Mago(string n);
    virtual ~Mago() = default;
    void exibirDados();
    string getClasse() const override;
};
