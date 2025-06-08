#include "TelaInicial.h"

void TelaInicial::exibirTelaInicial() {
    int opcao = 0;
    while (opcao != 4) {
        cout << "--- Aventuras Fantásticas RPG ---" << endl;
        cout << "1) Novo Jogo" << endl;
        cout << "2) Carregar Jogo" << endl;
        cout << "3) Exibir Créditos" << endl;
        cout << "4) Encerrar Programa" << endl;
        cout << "Digite sua opção: ";
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
            cout << "Opção inválida! Tente novamente!" << endl;
        }
    }
}

void TelaInicial::exibirOpcoesNovoJogo() {
    CriadorPersonagem c;
    int opcao;
    cout << "\n--- Novo Jogo ---" << endl;
    cout << "1) Criar personagem" << endl;
    cout << "2) Gerar personagem aleatóriamente" << endl;
    cout << "3) Voltar" << endl;
    cout << "Digite sua opção: ";
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
        cout << "\nOpção inválida! Tente novamente!\n" << endl;
        return;
    }

    personagem = c.getPersonagemCriado();
}

void TelaInicial::exibirCreditos() {
    cout << "\n--- Créditos ---" << endl;
    cout << "Criador: João Pedro Büttenbender da Silva" << endl;
    cout << "Curso: Ciências da Computação" << endl;
    cout << "Professor: Marcio Garcia Martins" << endl;
    cout << "Obrigado por jogar! ;D\n" << endl;
}

Personagem* TelaInicial::getPersonagem() {
    return personagem;
}
