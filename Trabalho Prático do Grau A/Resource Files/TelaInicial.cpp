#include "TelaInicial.h"

void TelaInicial::exibirTelaInicial() {
    int opcao = 0;
    while (opcao != 4) {
        cout << "--- Aventuras Fant�sticas RPG ---" << endl;
        cout << "1) Novo Jogo" << endl;
        cout << "2) Carregar Jogo" << endl;
        cout << "3) Exibir Cr�ditos" << endl;
        cout << "4) Encerrar Programa" << endl;
        cout << "Digite sua op��o: ";
        cin >> opcao;

        if (opcao == 1) {
            exibirOpcoesNovoJogo();

            TelaJogo tj;
            tj.carregarHistoria("historia.txt");
            tj.iniciarHistoria(personagem);
        }
        else if (opcao == 2) {
            TelaJogo tj;
            if (tj.carregarPersonagem("personagem.txt")) {
                personagem = tj.getPersonagem();
                tj.iniciarHistoria(personagem);
            }
        }
        else if (opcao == 3) {
            exibirCreditos();
        }
        else if (opcao == 4) {
            cout << "\nEncerrando programa..." << endl;
        }
        else {
            cout << "Op��o inv�lida! Tente novamente!" << endl;
        }
    }
}

void TelaInicial::exibirOpcoesNovoJogo() {
    CriadorPersonagem c;
    int opcao;
    cout << "\n--- Novo Jogo ---" << endl;
    cout << "1) Criar personagem" << endl;
    cout << "2) Gerar personagem aleat�riamente" << endl;
    cout << "3) Voltar" << endl;
    cout << "Digite sua op��o: ";
    cin >> opcao;
    cout << endl;

    if (opcao == 1) {
        bool sucesso = false;
        while(!sucesso) {
            sucesso = c.criarPersonagem();
        }
    }
    else if (opcao == 2) {
        bool sucesso = false;
        while(!sucesso) {
            sucesso = c.criarPersonagemAleatorio();
        }
    }
    else if (opcao == 3) {
        return;
    }
    else {
        cout << "\nOp��o inv�lida! Tente novamente!\n" << endl;
        return;
    }

    personagem = c.getPersonagemCriado();
}

void TelaInicial::exibirCreditos() {
    cout << "\n--- Cr�ditos ---" << endl;
    cout << "Criador: Jo�o Pedro B�ttenbender da Silva" << endl;
    cout << "Curso: Ci�ncias da Computa��o" << endl;
    cout << "Professor: Marcio Garcia Martins" << endl;
    cout << "Obrigado por jogar! ;D\n" << endl;
}

Personagem* TelaInicial::getPersonagem() {
    return personagem;
}
