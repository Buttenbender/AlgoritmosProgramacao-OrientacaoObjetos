#include "TelaCombate.h"

void TelaCombate::comecarCombate(Personagem* p, Monstro* m) {
    while (p->getEnergia() > 0 && m->getEnergia() > 0) {
        int opcao;
        cout << "\n--- Tela de Combate ---\n" << endl;
        p->exibirDados();
        m->exibirDados();
        cout << "\n1) Atacar" << endl;
        cout << "2) Abrir inventário" << endl;
        cout << "3) Fugir" << endl;
        cout << "4) Comer provisão" << endl;
        cout << "Digite sua opção: ";
        cin >> opcao;

        if (opcao == 1) {
            if (Guerreiro* guerreiro = dynamic_cast<Guerreiro*>(p)) {
                atacar(guerreiro, m);
            }
            else if (Mago* mago = dynamic_cast<Mago*>(p)) {
                atacarMago(mago, m);
            }
        }
        else if (opcao == 2) {
            p->editarInventario();
        }
        else if (opcao == 3) {
            if (m->getChefe() == 1) {
                cout << "\nVocê não consegue fugir!\n" << endl;
            }
            else {
                srand(time(0));
                int num = 1 + rand() % 20;
                if (num <= p->getSorte()) {
                    cout << "\nVocê fugiu!\n" << endl;
                    return;
                }
                else {
                    cout << "\nVocê não consegue fugir!\n" << endl;
                }
            }
        }
        else if (opcao == 4) {
            if (p->getProvisoes() > 0) {
                cout << "\nVocê comeu uma provisão e curou 3 pontos de energia!\n" << endl;
                p->setEnergia(p->getEnergia() + 3);
                p->setProvisoes(p->getProvisoes() - 1);
            }
            else {
                cout << "\nVocê não possui provisões!\n" << endl;
            }
        }
        else {
            cout << "\nOpção inválida! Tente novamente!\n" << endl;
        }
    }

    if (p->getEnergia() <= 0) {
        cout << "\nVocê foi derrotado!\n" << endl;
        return;
    }
    else {
        cout << "\nVocê venceu o combate!" << endl;
    }
}

void TelaCombate::atacar(Personagem* p, Monstro* m) {
    srand(time(0));
    int numP = 1 + rand() % 10;
    int numM = 1 + rand() % 10;

    int danoPersonagem = 2;
    int danoMonstro = 2;

    int faPersonagem = p->getHabilidade() + numP;
    int faMonstro = m->getHabilidade() + numM;

    for (auto& item : p->getInventario()) {
        if (item.getEquipado() == 1 && item.getCombate() == 1) {
            if (item.getTipo() == "arma") {
                faPersonagem += item.getFA();
                danoPersonagem += item.getDano();
            }
            else if (item.getTipo() == "armadura") {
                faMonstro -= item.getFA();
                danoMonstro -= item.getDano();
                if (danoMonstro < 0) danoMonstro = 0;
            }
        }
    }

    for (auto& item : m->getInventario()) {
        if (item.getEquipado() == 1 && item.getCombate() == 1) {
            if (item.getTipo() == "arma") {
                faMonstro += item.getFA();
                danoMonstro += item.getDano();
            }
            else if (item.getTipo() == "armadura") {
                faPersonagem -= item.getFA();
                danoPersonagem -= item.getDano();
                if (danoPersonagem < 0) danoPersonagem = 0;
            }
        }
    }

    cout << "FA do personagem: " << faPersonagem << " (Rolagem: " << numP << ")" << endl;
    cout << "FA do monstro: " << faMonstro << " (Rolagem: " << numM << ")" << endl;

    if (faPersonagem > faMonstro) {
        m->setEnergia(m->getEnergia() - danoPersonagem);
        cout << "Você venceu a rodada e causou " << danoPersonagem << " de dano!" << endl;
    }
    else if (faMonstro > faPersonagem) {
        p->setEnergia(p->getEnergia() - danoMonstro);
        cout << "O monstro venceu a rodada e causou " << danoMonstro << " de dano!" << endl;
    }
    else {
        cout << "Empate, ninguém sofreu dano!" << endl;
    }
}

void TelaCombate::atacarMago(Personagem* p, Monstro* m) {
    srand(time(0));

    int numP = 1 + rand() % 10;
    int numM = 1 + rand() % 10;

    int danoPersonagem = 2;
    int danoMonstro = 2;

    int faPersonagem = p->getHabilidade() + numP;
    int faMonstro = m->getHabilidade() + numM;

    for (auto& item : m->getInventario()) {
        if (item.getEquipado() == 1 && item.getCombate() == 1) {
            if (item.getTipo() == "arma") {
                faMonstro += item.getFA();
                danoMonstro += item.getDano();
            }
            else if (item.getTipo() == "armadura") {
                faPersonagem -= item.getFA();
                danoPersonagem -= item.getDano();
                if (danoPersonagem < 0) danoPersonagem = 0;
            }
        }
    }

    for (auto& item : p->getInventario()) {
        if (item.getEquipado() == 1 && item.getCombate() == 1) {
            if (item.getTipo() == "arma") {
                faPersonagem += item.getFA();
                danoPersonagem += item.getDano();
            }
            else if (item.getTipo() == "armadura") {
                faMonstro -= item.getFA();
                danoMonstro -= item.getDano();
                if (danoMonstro < 0) danoMonstro = 0;
            }
        }
    }

    const auto& magias = p->getMagias();
    cout << "\n--- Magias Disponíveis ---" << endl;
    for (size_t i = 0; i < magias.size(); i++) {
        cout << i + 1 << ") " << magias[i].getNome() << "; Tipo: " << magias[i].getTipo() << "; Valor: " << magias[i].getValor() << endl;
    }

    int escolha;
    cout << "Escolha uma magia para usar: ";
    cin >> escolha;

    Magia magiaUsada = magias[escolha - 1];

    if (magiaUsada.getTipo() == "dano") {
        danoPersonagem += magiaUsada.getValor();
    }
    else if (magiaUsada.getTipo() == "cura") {
        p->setEnergia(p->getEnergia() + magiaUsada.getValor());
    }

    cout << "FA do personagem: " << faPersonagem << " (Rolagem: " << numP << ")" << endl;
    cout << "FA do monstro: " << faMonstro << " (Rolagem: " << numM << ")" << endl;

    if (faPersonagem > faMonstro) {
        if (magiaUsada.getTipo() == "dano") {
            m->setEnergia(m->getEnergia() - danoPersonagem);
            cout << "Você venceu a rodada e causou " << danoPersonagem << " de dano!" << endl;
        }
        else if (magiaUsada.getTipo() == "cura") {
            cout << "Você venceu a rodada e curou " << magiaUsada.getValor() << " da sua energia!" << endl;
        }
    }
    else if (faMonstro > faPersonagem) {
        p->setEnergia(p->getEnergia() - danoMonstro);
        cout << "O monstro venceu a rodada e causou " << danoMonstro << " de dano!" << endl;
    }
    else {
        cout << "Empate, ninguém sofreu dano!" << endl;
    }
}
