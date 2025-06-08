#pragma once
#include "Personagem.h"
#include "Monstro.h"
#include "Guerreiro.h"
#include "Mago.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class TelaCombate {
public:
    void comecarCombate(Personagem* p, Monstro* m);
    void atacar(Personagem* p, Monstro* m);
    void atacarMago(Personagem* p, Monstro* m);
};
