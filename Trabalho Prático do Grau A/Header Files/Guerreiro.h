#pragma once
#include "Personagem.h"

class Guerreiro: public Personagem {
public:
    Guerreiro(string n);
    virtual ~Guerreiro() = default;
    void exibirDados();
    string getClasse() const override;
};
