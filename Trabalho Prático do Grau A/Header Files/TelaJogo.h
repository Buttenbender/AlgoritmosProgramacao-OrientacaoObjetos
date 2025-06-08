#include "Personagem.h"
#include "CriadorPersonagem.h"
#include "Monstro.h"
#include "TelaCombate.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <memory>
#include <algorithm>
using namespace std;

struct Opcao {
    string texto;
    int destino;
};

struct Cena {
    int id;
    string texto;
    vector<Opcao> opcoes;
    string evento;
};

class TelaJogo {
private:
    vector<Cena> cenas;
    int cenaAtual;
    unique_ptr<Personagem> personagem;
public:
    TelaJogo();
    bool carregarHistoria(const string& caminhoArquivo);
    void iniciarHistoria(Personagem* personagem);
    bool processarEvento(const string& evento, Personagem* personagem, int& novaCena);
    bool salvarPersonagem(const string& caminhoArquivo, Personagem* personagem);
    bool carregarPersonagem(const string& caminhoArquivo);
    Personagem* getPersonagem();
};
