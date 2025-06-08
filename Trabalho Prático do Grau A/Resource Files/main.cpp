#include "TelaInicial.h"

int main() {
    #ifdef _WIN32
    system("chcp 1252 > null");
    #endif
    TelaInicial ti;
    ti.exibirTelaInicial();

    return 0;
}
