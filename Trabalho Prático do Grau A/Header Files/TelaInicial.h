#pragma once
#include "CriadorPersonagem.h"
#include "TelaJogo.h"
#include <iostream>
using namespace std;

class TelaInicial {
private:
    Personagem* personagem = nullptr;
public:
    void exibirTelaInicial();
    void exibirOpcoesNovoJogo();
    void exibirCreditos();

    Personagem* getPersonagem();
};
