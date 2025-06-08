#pragma once
#include "Guerreiro.h"
#include "Mago.h"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>

class CriadorPersonagem {
private:
    Personagem* personagemCriado = nullptr;
public:
    bool criarPersonagem();
    bool criarPersonagemAleatorio();
    Personagem* getPersonagemCriado() const;
};
