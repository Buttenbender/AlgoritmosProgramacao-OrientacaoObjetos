#include "CriadorPersonagem.h"

bool CriadorPersonagem::criarPersonagem() {
    int opcao;
    string nome;

    cout << "\n--- Menu de Cria��o de Personagem ---" << endl;
    cout << "Digite o nome do seu personagem: ";
    cin.ignore();
    getline(cin, nome);

    if (nome.empty()) {
        cout << "\nO nome do personagem n�o pode ser vazio! Tente novamente!\n" << endl;
        return false;
    }

    cout << "\nEscolha uma classe para seu personagem:" << endl;
    cout << "1) Guerreiro" << endl;
    cout << "2) Mago" << endl;
    cout << "Digite sua op��o: ";
    cin >> opcao;

    Personagem* personagem = nullptr;

    if (opcao == 1) {
        personagem = new Guerreiro(nome);
    }
    else if (opcao == 2) {
        personagem = new Mago(nome);
    }
    else {
        cout << "\nOp��o inv�lida! Tente novamente!\n" << endl;
        return false;
    }

    int pontosDisponiveis = 12;
    int valor = 0;
    int escolha = -1;

    while (pontosDisponiveis > 0) {
        cout << "\nAtributos Atuais:" << endl;
        cout << "1) Habilidade: " << personagem->getHabilidade() << "/12" << endl;
        cout << "2) Energia: " << personagem->getEnergia() << "/24" << endl;
        cout << "3) Sorte: " << personagem->getSorte() << "/12" << endl;
        cout << "4) Finalizar Distribui��o" << endl;
        cout << "Pontos Dispon�veis: " << pontosDisponiveis << endl;

        cout << "Escolha um atributo para aumentar: ";
        cin >> escolha;

        if (escolha == 4) {
            break;
        }

        cout << "Quantos pontos deseja adicionar? ";
        cin >> valor;

        if (valor <= 0 || valor > pontosDisponiveis) {
            cout << "Valor Inv�lido!" << endl;
            continue;
        }

        bool sucesso = false;

        switch (escolha) {
            case 1:
                if (personagem->getHabilidade() + valor <= 12) {
                    personagem->setHabilidade(personagem->getHabilidade() + valor);
                    sucesso = true;
                }
                else {
                    cout << "\nHabilidade excede o m�ximo de pontos permitidos!" << endl;
                }
                break;
            case 2:
                if (personagem->getEnergia() + valor <= 24) {
                    personagem->setEnergia(personagem->getEnergia() + valor);
                    sucesso = true;
                }
                else {
                    cout << "\nEnergia excede o m�ximo de pontos permitidos!" << endl;
                }
                break;
            case 3:
                if (personagem->getSorte() + valor <= 12) {
                    personagem->setSorte(personagem->getSorte() + valor);
                    sucesso = true;
                }
                else {
                    cout << "\nSorte excede o m�ximo de pontos permitidos!" << endl;
                }
                break;
            default:
                cout << "\nOp��o Inv�lida!\n" << endl;
        }

        if (sucesso) {
            pontosDisponiveis -= valor;
        }
    }

    cout << "Personagem criado com sucesso!\n" << endl;
    personagem->exibirDados();

    personagemCriado = personagem;
    return true;
}

bool CriadorPersonagem::criarPersonagemAleatorio() {
    string nome;
    cout << "\n--- Cria��o Aleat�ria de Personagem ---" << endl;
    cout << "Digite o nome do seu personagem: ";
    cin.ignore();
    getline(cin, nome);

    if (nome.empty()) {
        cout << "\nO nome do personagem n�o pode ser vazio! Tente novamente!\n" << endl;
        return false;
    }

    srand(time(0));

    int classe = rand() % 2;
    Personagem* personagem = nullptr;

    if (classe == 0) {
        personagem = new Guerreiro(nome);
        cout << "\nClasse sorteada: Guerreiro\n";
    }
    else {
        personagem = new Mago(nome);
        cout << "\nClasse sorteada: Mago\n";
    }

    int pontosDisponiveis = 12;

    while (pontosDisponiveis > 0) {
        int escolha = rand() % 3;
        int valor = 1 + rand() % pontosDisponiveis;

        switch (escolha) {
        case 0:
            if (personagem->getHabilidade() + valor <= 12) {
                personagem->setHabilidade(personagem->getHabilidade() + valor);
                pontosDisponiveis -= valor;
            }
            break;
        case 1:
            if (personagem->getEnergia() + valor <= 24) {
                personagem->setEnergia(personagem->getEnergia() + valor);
                pontosDisponiveis -= valor;
            }
            break;
        case 2:
            if (personagem->getSorte() + valor <= 12) {
                personagem->setSorte(personagem->getSorte() + valor);
                pontosDisponiveis -= valor;
            }
            break;
        }
    }

    cout << "\nPersonagem criado aleat�riamente com sucesso!\n" << endl;
    personagem->exibirDados();

    personagemCriado = personagem;
    return true;
}

Personagem* CriadorPersonagem::getPersonagemCriado() const {
    return personagemCriado;
}
